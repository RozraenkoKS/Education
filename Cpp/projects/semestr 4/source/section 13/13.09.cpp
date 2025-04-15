#include <regex>
#include <iostream>

using namespace std::literals;

inline std::vector<std::smatch> search_car_numbers(const std::string& string) {
  std::vector<std::smatch> matches;
  std::regex pattern(R"([[:upper:]]\d{3}[[:upper:]]{2}\d{2}\d?)");
  for (std::sregex_iterator it(std::cbegin(string), std::cend(string), pattern); it != std::sregex_iterator(); ++it) {
    matches.push_back(*it);
  }
  return matches;
}

int main() {
  const auto data = "A999TV123аA999TV123A999TB123 A999TV123BUSSA999TV93"s;
  std::vector<std::smatch> matches = search_car_numbers(data);

  std::for_each(std::cbegin(matches), std::cend(matches), [](const auto& match) {std::cout << match.str() << ' ';});

  return 0;
}


    
