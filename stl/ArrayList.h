/*
 * ArrayList.h
 *
 *  Created on: 23 May, 2015
 *      Author: yinyinchiu
 */

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
		private:
			void increase_size();
			T* _array;
			int _size;
			int _number_of_elements;
	};

}

#endif /* ARRAYLIST_H_ */
