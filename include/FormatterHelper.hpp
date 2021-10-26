#pragma once

#include <string>

namespace formatter {

class FormatterHelper {
	;

	friend std::string operator%(const std::string& format, const FormatterHelper& args);
	friend std::string operator%(const char* format, const FormatterHelper& args);
};

// To make the syntax nicer
using _ = FormatterHelper;

}  // namespace formatter
