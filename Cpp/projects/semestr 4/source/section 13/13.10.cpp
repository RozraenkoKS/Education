#include <regex>
#include <iostream>

using namespace std::literals;

[[nodiscard]] std::vector<std::smatch> search_emails(const std::string& string) {
  std::vector<std::smatch> matches;
  std::regex pattern(R"([a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z0-9_-]+)");
  for (std::sregex_iterator it(std::cbegin(string), std::cend(string), pattern); it != std::sregex_iterator(); ++it) {
    matches.push_back(*it);
  }
  return matches;
}

int main() {
  const auto data = "john.doe@example.com, alice_smith@gmail.com, bob-123@yahoo.co.uk, invalid_email@.com"s;
  std::vector<std::smatch> matches = search_emails(data);

  std::for_each(std::cbegin(matches), std::cend(matches), [](const auto& match) {std::cout << match.str() << ' ';});

  return 0;
}
