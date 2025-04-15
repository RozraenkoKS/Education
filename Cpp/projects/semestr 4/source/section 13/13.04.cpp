#include <string>
#include <vector>
#include <cassert>
#include <iterator>
#include <iostream>

template <typename C>
std::string join_strings(C const& c, char const* const separator) {
	std::string result{};
	if (c.size() == 0) return result;
	for (auto word : c) {
		result += word + separator;
	}
	result.pop_back();
	return result;
}
int main() {
	using namespace std::literals;
	std::vector<std::string> v1{ "this","is","an","example" };
	std::vector<std::string> v2{ "example" };
	std::vector<std::string> v3{ };
	assert(join_strings(v1, " ") == "this is an example"s);
	assert(join_strings(v2, " ") == "example"s);
	assert(join_strings(v3, " ") == ""s);
}