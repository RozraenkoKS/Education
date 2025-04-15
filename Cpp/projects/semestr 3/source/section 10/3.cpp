
#include <iostream>
#include <string>
#include <optional>
class Person {
public:
	explicit Person(const std::string& name, const std::string& familyname, int age) : m_age(age), m_name(name), m_familyname(familyname) {
	}
	void set_adress(const std::string& adress) {
		m_address = adress;
	}
	std::optional<std::string> get_address() const {
		return m_address.has_value() ? m_address : std::nullopt;
	}
	std::string get_name() const {
		return m_name;
	}

private:
	int m_age;
	std::string m_name;
	std::string m_familyname;
	std::optional<std::string> m_address;
};
int main() {
	Person p1("Ivan", "Ivanov", 15);
	Person p2("Kirill", "Rozraenko", 19);
	p2.set_adress("Pervomaiskaya 30k8");
	auto address1 = p1.get_address();
	auto address2 = p2.get_address();
	if (address1.has_value()) {
		std::cout <<p1.get_name() << " has address: " << address1.value() << std::endl;
	}
	else {
		std::cout << p1.get_name() <<  " has no addres" << std::endl;
	}
	if (address2.has_value()) {
		std::cout << p2.get_name() << " has address: " << address2.value() << std::endl;
	}
	else {
		std::cout << p2.get_name() << " has no addres" << std::endl;
	}
}
