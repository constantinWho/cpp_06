#include "./inc/Serialization.hpp"

int main() {

	Serializer serializer("John Doe", 30);
	serializer.printData();

	Serializer test(serializer);
	test.printData();

	return 0;
}
