#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "./Data.hpp"

class Serializer {
	private:
		Data*				ptr;
	public:
		Serializer(const std::string & name, int age);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

		void printData() const;
};

#endif
