#include <string>
#include <vector>
#include <cassert>

std::vector<std::string> split(std::string const& input, std::string const& separators) {
    std::vector<std::string> result;

    std::string::size_type first = 0;
    std::string::size_type last = 0;
    while ((first = input.find_first_not_of(separators, last)) != std::string::npos) {
        last = input.find_first_of(separators, first);

        std::string const token(input, first, last - first);
        result.push_back(token);

        first = last;
    }

    return result;
}

int main()
{
	using namespace std::string_literals;
	std::vector<std::string> expected{ "this", "is", "a", "sample" };
	assert(expected == split("this is a sample"s, ' '));
	assert(expected == split("this,is a.sample!!"s, ",.! "s));
    return 0;
}