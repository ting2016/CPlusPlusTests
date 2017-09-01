#ifndef MY_UNORDERED_MAP_H
#define MY_UNORDERED_MAP_H
#include <utility>
#include <array>
#include <forward_list>
namespace ting{
	namespace unordered_map{
		#define BUCKET_SIZE 20
		template<class key, class value>
		class My_Unordered_Map{
			public:
				typedef std::pair<key, value> mypair;
				typedef int size_type;
				My_Unordered_Map(){
					for(int i = 0; i<BUCKET_SIZE;i++){
						my_map[i] = new std::forward_list<mypair>();
					}
					num = 0;
				}
				~My_Unordered_Map(){
					for(int i = 0; i<BUCKET_SIZE;i++){
						delete my_map[i];
					}
				}
				int hash_function(const key& k) const;
				size_type size() const;
				bool empty() const;
				//insert mypair to the proper place of the map
				void insert(const mypair&) const;
				//delete the pair with key from map, if delete, return true, if key not found, return false
				bool erase(const key&);
				void print();
			private:
				std::array<std::forward_list<mypair>*, BUCKET_SIZE> my_map;
				size_type num;
		};	
	}
}

#endif
