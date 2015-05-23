#include "ArrayList.h"

namespace YinLib {
	template<typename T>
	ArrayList<T>::ArrayList() {
		_array = NULL;
		_size = 0;
		_number_of_elements = 0;
	}

	template<typename T>
	ArrayList<T>::ArrayList(int size) {
		_size = 0;
		_number_of_elements = 0;
		_array = new T[size];
	}

	template<typename T>
	ArrayList<T>::~ArrayList() {
		clear();
	}

	template<typename T>
	void ArrayList<T>::add(T& element) {
		if (_number_of_elements + 1 == _size) {
			T* new_array = new T[2 * _size];

			for (int i = 0; i < _number_of_elements; i++) {
				new_array[i] = _array[i];
			}

			delete [] _array;
			_size *= 2;
			_array = new_array;
		}

		_array[_number_of_elements++] = element;
	}

	template<typename T>
	void ArrayList<T>::clear() {
		delete [] _array;
	}

	template<typename T>
	T& ArrayList<T>::get(int index) {
		if (index >= _number_of_elements) {
			return NULL;
		} else if (index >= _size) {
			exit(-1);
		} else {
			return _array[index];
		}
	}
}
