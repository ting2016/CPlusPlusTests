#ifndef MY_UNORDERED_MAP_H
#define MY_UNORDERED_MAP_H 
#include <utility>
#include <cstddef>
namespace ting{
	namespace unordered_map{
		#define BUCKET_SIZE 20
		template <typename K> 
		struct Hash{
	   		static size_t get(const K& k){
				return k%BUCKET_SIZE;
	   		}
		};
		template<class key, class value,class F=Hash<key>>
		class My_Unordered_Map{
			public:
				typedef std::pair<key, value> mypair;
				My_Unordered_Map(){
					for(int i = 0; i<BUCKET_SIZE;i++){
						my_map[i]= nullptr;
					}
					num = 0;
				}
				~My_Unordered_Map(){
					for(int i = 0; i<BUCKET_SIZE;i++){
						Node* temp = my_map[i];
						while(temp!=nullptr){
							Node* currentPtr = temp;
							temp=temp->next;
							delete currentPtr;
						}
					}
				}
				size_t size() const;
				bool empty() const;
				//insert mypair to the proper place of the map
				void insert(const mypair&) const;
				//delete the pair with key from map, if delete, return true, if key not found, return false
				bool erase(const key&);
				void print();
				size_t hashFunc(const key& k);
			private:
				template<class key, class value, class F>
				class Node{
					key k;
					value v;
					Node* next;
					Node::Node(key other_k,value other_v ):key(other_k),v(other_v),next(nullptr){};
				};
				class hash_function{
					int operator()(const key& k) const{
						return k%BUCKET_SIZE;
					}
				}
				//an arry of pointers point to Node objects
				Node* my_map[BUCKET_SIZE];
				//stores the number of pairs in the map
				size_type num;
				F hashFunc;
		};	
	}
}


template <class key, class value,class F>
size_t ting::unordered_mpa::My_unordered_map(const key& k){
	return Hash::get(k)
}

template <class key, class value,class F>
size_t ting::unordered_map::My_unordered_map::size(){
	return num;
}

template<class key, class value, class F>
bool ting::unordered_map::My_unordered_map::empty() const{
	return num==0;
}

template<class key, class value, class F>
void ting::unordered_map::My_unordered_map::insert(const mypair& pair) const{
	
}

template<class key, class value, class F>
bool erase(const key& k){
	return true;
}


#endif
