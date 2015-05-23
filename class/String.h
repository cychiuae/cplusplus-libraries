/*
 * String.h
 *
 *  Created on: 23 May, 2015
 *      Author: yinyinchiu
 */

#ifndef STRING_H_
#define STRING_H_
#include <iostream>

namespace YinLib {

	class String {
		public:
			//Constructors
			String();
			String(const char*);
			String(const String&);

			//Destructor
			~String();

			//Getters and Setters
			int size() const;

			//class functions
			void clear();
			void push_back(char);

			//operator
			const char operator[](int i) const;
			String& operator+=(const String&);
			String& operator=(const String&);
			friend std::ostream& operator<<(std::ostream&, const String&);
			friend std::istream& operator>>(std::istream&, const String&);

		private:
			char* _charactor;
			unsigned int _length;
	};

} /* namespace yin */

#endif /* STRING_H_ */
