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
	int val = 43;
	std::vector<const void*> data{reinterpret_cast<const void*>(val), reinterpret_cast<const void*>("TEST")};

#ifdef _WIN32
	va_list vaArgs = reinterpret_cast<va_list>(data.data());

	std::size_t size = vsnprintf(nullptr, 0, format, vaArgs);
	std::string out(size, '\0');

	vsprintf_s(out.data(), size + 1, format, vaArgs);
#else
	va_list vaArgs = {(__va_list_tag)data.data()};

	char* res = nullptr;

	//vasprintf(&res, format, vaArgs);
	asprintf(&res, format);

	std::string out{res};
	free(res);
#endif

	return out;
}

}  // namespace formatter
