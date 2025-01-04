#include "./inc/Identify.hpp"
#include <ctime>  // For seeding rand()

int main() {
	std::srand(std::time(NULL));  // Seed the random number generator

	for (int i = 0; i < 5; ++i) {
		Base* randomBase = generate();  // Generate random instance of A, B, or C
		std::cout << "Test " << i + 1 << ":\n";
		std::cout << "Pointer identify: ";
		identify(randomBase);  // Identify type using pointer
		std::cout << "Reference identify: ";
		identify(*randomBase);  // Identify type using reference
		delete randomBase;  // Clean up memory
		std::cout << "----------------------------------\n";
	}

	return 0;
}
