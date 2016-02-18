#include <iostream>
#include "MergesortVector.hpp"

int main() {
	int size;
	std::cout << "Size> "; std::cin >> size;

	MsVector ms = MsVector(size);
	ms.print();

	ms.sort();
	ms.print();

	return 0;
}
