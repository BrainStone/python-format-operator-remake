#include <iostream>

#include "FormatterHelper.hpp"

using namespace formatter;

int main() {
	std::cout << "Hello CMake: %d %s" % _() << std::endl;
	return 0;
}
