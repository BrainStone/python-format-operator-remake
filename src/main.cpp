#include <iostream>

#include "FormatterHelper.hpp"

using formatter::_;

int main() {
	std::cout << "Hello CMake: %d %s" % _() << std::endl;
	return 0;
}
