#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#ifndef NULL
#define NULL ((void*) 0)
#endif

#include <stdlib.h>

namespace YinLib {

	template<typename T>
	class ArrayList {
		public:
			ArrayList();
			ArrayList(int);
			~ArrayList();

			void add(T&);
			void clear();
			T& get(int);
			void insert(T&, int);
			bool is_exists(T&);
			void remove(int);
		private:
			T* _array;
			int _size;
			int _number_of_elements;
	};

}

#endif /* ARRAYLIST_H_ */
