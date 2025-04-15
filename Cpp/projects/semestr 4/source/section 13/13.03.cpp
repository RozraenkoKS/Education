#include <string>
#include <cassert>
#include <iostream>

std::string capitalize(std::string_view text) {
	char elem;
	std::string result;
	bool newWord = true;
	for (auto const ch : text)
	{
		newWord = newWord || std::ispunct(ch) || std::isspace(ch);
		if (std::isalpha(ch))
		{
			if (newWord)
			{
				result.push_back(std::toupper(ch));
				newWord = false;
			}
			else
				result.push_back(std::tolower(ch));
		}
		else result.push_back(ch);;
	}
	return result;
}

int main()
{
	using namespace std::literals;
	assert("The C++ Challenger"s ==
		capitalize("the c++ challenger"s));
	assert("This Is An Example, Should Work!"s == capitalize("THIS IS an ExamplE, should wORk!"s));
}