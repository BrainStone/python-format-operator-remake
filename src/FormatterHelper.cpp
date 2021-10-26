#include "FormatterHelper.hpp"

#include <any>
#include <cstdarg>
#include <cstdio>
#include <vector>

namespace formatter {

std::string operator%(const std::string& format, const FormatterHelper& args) {
	return format.c_str() % args;
}

std::string operator%(const char* format, const FormatterHelper& args) {
#ifdef _WIN32
	// TODO: Add arguments
	std::size_t size = snprintf(nullptr, 0, format);
	std::string out(size, '\0');

	// TODO: Add arguments
	sprintf_s(out.data(), size + 1, format);
#else
	char* res = nullptr;

	// TODO: Add arguments
	asprintf(&res, format, xxx);

	std::string out{res};
	free(res);
#endif

	return out;
}

}  // namespace formatter
