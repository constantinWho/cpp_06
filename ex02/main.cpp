#include "./inc/Identify.hpp"

int main() {

	for (int i = 0; i < 5; ++i) {
		Base* randomBase = generate();
		std::cout << "Test " << i + 1 << ":\n";
		std::cout << "Pointer identify: ";
		identify(randomBase);
		std::cout << "Reference identify: ";
		identify(*randomBase);
		delete randomBase;
		std::cout << "----------------------------------\n";
	}

	return 0;
}
