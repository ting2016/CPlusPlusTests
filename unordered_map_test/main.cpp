#include <utility>
#include <cstddef>
#include <iostream>
#include <string>
#define BUCKET_SIZE 20
namespace ting{
        namespace unordered_map{
	        //test for custom class as key
		class Person{
		public:
			int age;
			bool sex ;
		public:
			//friend class Hash_function<Person>;
			Person(const int age, const bool sex):age(age),sex(sex){}
			//need to overload == operator
   			bool operator==(const Person& other_p){return ((age==other_p.age)&&(sex==other_p.sex));}
			friend std::ostream& operator<<(std::ostream& o, const Person& p);
		};

	    //hash class template
            template<class key>
            class Hash_function{
                    int operator()(const key& k) const{
                            return k%BUCKET_SIZE;
                    }
                    template<class K, class V,class F>
                    friend class My_Unordered_Map;

            };

	    //class template specialization    
            template<>
	    class Hash_function<Person>{
	    public:
		int operator()(const Person& p) const{
			if(p.sex){
				return (p.age+1)%BUCKET_SIZE;
			}
			else{
				return p.age%BUCKET_SIZE;
			}	
		}
            
	    };

            std::ostream& operator<<(std::ostream& o, const Person& p){
		o<<"age: "<<p.age<<" sex: "<<p.sex;
		return o;
	    }

            template<class key, class value>
            class Node{
                key k;
                value v;
                Node* next;
            public:
                template<class K, class V,class F>
                friend class My_Unordered_Map;
                Node(key other_k,value other_v ):k(other_k),v(other_v),next(nullptr){}
                Node(const std::pair<key, value>& p):k(p.first),v(p.second),next(nullptr){}
            };

            template<class key, class value,class F = Hash_function<key>>
            class My_Unordered_Map{
                    public:
                            typedef int (*hasher)();
                            My_Unordered_Map(){
                                    for(int i = 0; i<BUCKET_SIZE;i++){
                                            my_map[i]= nullptr;
                                    }
                                    num = 0;
                            }
                            ~My_Unordered_Map(){
                                    for(int i = 0; i<BUCKET_SIZE;i++){
                                            Node<key, value>* temp = my_map[i];
                                            while(temp!=nullptr){
                                                    Node<key, value>* currentPtr = temp;
                                                    temp=temp->next;
                                                    delete currentPtr;
                                            }
                                    }
                            }
                            size_t size() const{
                                return num;
                            }
                            bool empty() const{
                                return num==0;
                            }
                            //insert mypair to the proper place of the map. if key already exists in the map, update the value
                            //else insert new node at the front
                            void insert(const std::pair<key, value>& pair){
                                int bucketIndex = hashFunc(pair.first);
                                auto cPtr = my_map[bucketIndex];
                                std::cout<<"bucket Index for pair:"<<pair.first<<"-->"<<pair.second<<" is "<<bucketIndex<<std::endl;
                                //not nullptr
                                while(cPtr){
                                    if(cPtr->k!=pair.first)
                                        cPtr= cPtr->next;
                                    else{
                                        std::cout<<" find a node with the same key"<<std::endl;
                                        std::cout<<"update the value with new"<<std::endl;
                                        cPtr->v = pair.second;
                                        return;
                                    }
                                }
                                    //add a new node to the end of given bucket
                                    auto newNode = new Node<key, value>(pair);
                                    newNode->next = my_map[bucketIndex];
                                    my_map[bucketIndex] = newNode;
                                    num++;
                            }
                            void insert(const key& k, const value& v){
                                int bucketIndex = hashFunc(k);
                                auto bPtr = my_map[bucketIndex];
                                std::cout<<"bucket Index for pair:"<<k<<"-->"<<v<<" is "<<bucketIndex<<std::endl;
                                //not nullptr
                                while(bPtr){
                                    if(bPtr->k==k){
                                        std::cout<<" find a node with the same key"<<std::endl;
                                        std::cout<<"update the value with new"<<std::endl;
                                        bPtr->v = v;
                                        return;
                                    }
                                    bPtr= bPtr->next;
                                }
                                //add a new node to the given bucket
                                auto newNode = new Node<key, value>(k,v);
                                newNode->next = my_map[bucketIndex];
                                my_map[bucketIndex] = newNode;
                                num++;
                            }
                            //delete the pair with key from map, if delete, return true, if key not found, return false
                            bool erase(const key& k){
                                int bucketIndex = hashFunc(k);
				std::cout<<"index for the k to be erased is: "<<bucketIndex<<std::endl;
                                Node<key, value>* cPtr = my_map[bucketIndex];
                                auto prevPtr =cPtr;
                                while(cPtr){
                                    if(cPtr->k==k){
					std::cout<<"find a node with matched key: "<<cPtr->k<<std::endl;
                                        if(cPtr==my_map[bucketIndex]){
                                            std::cout<<"first node with key = "<< k << std::endl;
                                            my_map[bucketIndex] = cPtr->next;
                                        }
                                        else{
                                            prevPtr->next = cPtr->next;
                                        }
                                        delete cPtr;
                                        num--;
                                        return true;
                                    }
                                    prevPtr = cPtr;
                                    cPtr = cPtr->next;
                                }
                                std::cout<<"node with key = "<< k << " not found" << std::endl;
                                return false;
                            }

                            void print(){
                                for(int i = 0; i<BUCKET_SIZE; i++){
                                    auto bPtr = my_map[i];
                                    std::cout<<"bucket: "<<i<<" ";
                                    while(bPtr){
                                        std::cout<<bPtr->k<<"-->"<<bPtr->v<< " ";
                                        bPtr=bPtr->next;
                                    }
                                    std::cout<<std::endl;
                                }
                            }
                            //return pointer to the hash function
                            hasher hash_function() const{
                                return hashFunc();
                            }
                    private:
                            //an arry of pointers point to Node objects
                            Node<key, value>* my_map[BUCKET_SIZE];
                            //stores the number of pairs in the map
                            size_t num;
                            F hashFunc;
            };
        }
}


int main(){
    using namespace ting::unordered_map;
    My_Unordered_Map<int, std::string,  Hash_function<int>> myMap;
    myMap.insert(33, "hello");
    myMap.insert(std::pair<int, std::string>(11,"haha"));
    myMap.insert(53, "hello2");
    myMap.erase(53);
    myMap.erase(43);
    myMap.print();
/*************test for custom class key********************/
    My_Unordered_Map<Person, std::string, Hash_function<Person>> myCustomMap;
    myCustomMap.insert(Person(33,1),"wangming");
    myCustomMap.insert(Person(33,0),"lingling");
    myCustomMap.insert(Person(53,1),"niuniu");
    myCustomMap.insert(Person(11,0),"hehe");
    myCustomMap.print();

}

