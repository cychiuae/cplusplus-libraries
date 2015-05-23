#include "String.h"

namespace YinLib {

	String::String() {
		_charactor = NULL;
		_length = 0;
	}

	String::String(const char* charactors) {
		_length = strlen(charactors);
		_charactor = new char[_length];

		for (int i = 0; i < _length; i++) {
			_charactor[i] = charactors[i];
		}
	}

	String::String(const String& s) {
		_length = s._length;
		_charactor = new char[_length];

		for (int i = 0; i < _length; i++) {
			_charactor[i] = s[i];
		}
	}

	String::~String() {
		delete [] _charactor;
	}

	int String::size() const{
		return _length;
	}

	void String::clear() {
		delete [] _charactor;
		_length = 0;
	}

	void String::push_back(char c) {
		char* new_charactors = new char[++_length];

		for (int i = 0; i < _length - 1; i++) {
			new_charactors[i] = _charactor[i];
		}
		new_charactors[_length - 1] = c;

		delete [] _charactor;
		_charactor = new_charactors;
	}

	//Operators
	const char String::operator[](int i) const {
		return _charactor[i];
	}

	String& String::operator+=(const String& s) {
		for (int i = 0; i < s._length; i++)
			push_back(s._charactor[i]);
		return *this;
	}

	String& String::operator=(const String& s) {
		String result(s);
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const String& s) {
		for (int i = 0; i < s.size(); i++) {
			os << s._charactor[i];
		}
		return os;
	}

} /* namespace yin */
