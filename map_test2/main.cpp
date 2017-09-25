#include <utility>
#include <cstddef>
#include <iostream>
#include <string>
#define BUCKET_SIZE 20
namespace ting{
        namespace unordered_map{
            template<class key>
            class Hash_function{
                    int operator()(const key& k) const{
                            return k%BUCKET_SIZE;
                    }
                    template<class K, class V,class F>
                    friend class My_Unordered_Map;

            };

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
                                Node<key, value>* bPtr = my_map[bucketIndex];
                                std::cout<<"bucket Index for pair:"<<pair.first<<"-->"<<pair.second<<" is "<<bucketIndex<<std::endl;
                                //not nullptr
                                while(bPtr){
                                    if(bPtr->k!=pair.first)
                                        bPtr= bPtr->next;
                                    else
                                        std::cout<<" find a node with the same key"<<std::endl;
                                        break;
                                }
                                if(bPtr){
                                    std::cout<<"update the value with new"<<std::endl;
                                    bPtr->v = pair.second;
                                }
                                else{
                                    std::cout<<"..."<<std::endl;
                                    //add a new node to the end of given bucket
                                    auto newNode = new Node<key, value>(pair);
                                    bPtr = newNode;
                                    num++;
                                }
                            }
                            //delete the pair with key from map, if delete, return true, if key not found, return false
                            bool erase(const key& k){
                                int bucketIndex = hashFunc(k);
                                Node<key, value>* bPtr = my_map[bucketIndex];
                                if(!bPtr){
                                    if(bPtr->k==k){
                                       std::cout<<"find a node with key = "<< k << std::endl;
                                       num--;
                                       return true;
                                    }
                                    bPtr= bPtr->next;
                                }
                                std::cout<<"node with key = "<< k << " not found" << std::endl;
                                return false;
                            }

                            void print(){
                                for(int i = 0; i<BUCKET_SIZE; i++){
                                    Node<key, value>* bPtr = my_map[i];
                                    std::cout<<"bucket: "<<i<<" ";
                                    while(!bPtr){
                                        std::cout<<bPtr->k<<"-->"<<bPtr->v<< " ";
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
    myMap.insert(std::pair<int, std::string>(33, "hello"));
    myMap.print();
}
