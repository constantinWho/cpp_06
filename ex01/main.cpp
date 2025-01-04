#include "./inc/Serialization.hpp"

void runTest(const std::string &name, int age) {
	Data* data = new Data();
	data->name = name;
	data->age = age;

	std::cout << "----------------------------------\n";
	std::cout << "Original Data:\n";
	std::cout << "Name: " << data->name << "\n";
	std::cout << "Age: " << data->age << "\n";

	uintptr_t raw = serialize(data);
	std::cout << "Serialized uintptr_t: " << raw << "\n";

	Data* deserializedData = deserialize(raw);

	std::cout << "Deserialized Data:\n";
	std::cout << "Name: " << deserializedData->name << "\n";
	std::cout << "Age: " << deserializedData->age << "\n";

	delete data;
}


int main() {
	runTest("Alice", 30);

	runTest("", 0);

	runTest("Hello, World! 😊", 25);

	runTest("A very long name with multiple characters to test serialization", 42);

	runTest("Negative Age Test", -15);

	runTest("Max Int Test", 2147483647);

	return 0;
}

