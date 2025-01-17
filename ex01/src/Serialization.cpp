#include "../inc/Serialization.hpp"

Serializer::Serializer(const std::string & name, int age) {
	ptr = new Data;
	ptr->name = name;
	ptr->age = age;
}
Serializer::Serializer(const Serializer & other) {
	ptr = new Data;
	ptr->name = other.ptr->name;
	ptr->age = other.ptr->age;
}
Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other) {
		delete ptr;
		ptr = new Data;
		ptr->name = other.ptr->name;
		ptr->age = other.ptr->age;
	}
	return *this;
}
Serializer::~Serializer() { delete ptr; ptr = NULL; }

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

void Serializer::printData() const {
	if (ptr) {
		std::cout << "Data:\n";
		std::cout << "Name: " << ptr->name << "\n";
		std::cout << "Age: " << ptr->age << "\n";
	} else {
		std::cout << "Data pointer is null.\n";
	}
}
