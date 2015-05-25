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

	template<typename T>
	void ArrayList<T>::insert(T& element, int index) {
		T* new_array = NULL;

		if (_number_of_elements + 1 == _size) {
			new_array = new T[2 * _size];
		} else {
			new_array = new T[_size];
		}

		for (int i = 0; i < index; i++) {
			new_array[i] = _array[i];
		}

		new_array[index] = element;

		for (int i = index + 1; i < _size; i++) {
			new_array[i - 1] = _array[i];
		}

		delete [] _array;
		_size *= 2;
		_number_of_elements++;

		_array = new_array;
	}

	template<typename T>
	bool ArrayList<T>::is_exists(T& element) {
		for (int i = 0; i < _number_of_elements; i++) {
			if (_array[i] == element) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	void ArrayList<T>::remove(int index) {
		if (index >= _size) {
			exit(-1);
		} else if (index < _number_of_elements) {
			for (int i = index; i < _number_of_elements; i++) {
				_array[index] = _array[index + 1];
			}
			_number_of_elements--;
		}

		if (_number_of_elements < _size / 3) {
			T* new_array = new T[_size / 2];

			for (int i = 0; i < _number_of_elements; i++) {
				new_array[i] = _array[i];
			}

			delete [] _array;
			_size /= 2;

			_array = new_array;
		}
	}
}
