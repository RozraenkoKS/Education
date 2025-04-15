#include <iostream>
#include <variant>
#include <optional>
#include <vector>
int main() {
	try {
		int* HugeArray = new int[100]; //int* HugeArray = new int[10000000000] --> error
		std::cout << "Allocation completed successfully" << '\n';
		delete[] HugeArray;
	}
	catch (const std::bad_alloc& e1) {
		std::cerr << "Error: " << e1.what() << '\n';
	}

	try {
		std::variant<int, double> num = 42.0; 
		auto x = std::get<double>(num); //auto x = std::get<int>(num); --> error
		std::cout << "Num double value is " << x << '\n';
	}
	catch (const std::bad_variant_access& e2) {
		std::cerr << "Error: " << e2.what() << '\n';
	}

	try {
		std::optional<double> num = 42; //std::optional<double> num = std::nullopt; --> error
		auto x = num.value();
		std::cout << "Num double value is " << x << '\n';
	}
	catch (const std::bad_optional_access& e3) {
		std::cerr << "Error: " << e3.what() << '\n';
	}

	try {
		std::vector<int> array(100); //std::vector<int> array(100000000000000000000); --> error
		std::cout << "Allocation completed successfully" << '\n'; 
	}
	catch (const std::length_error& e4) {
		std::cerr << "Length error: " << e4.what() << std::endl;
	}
	try {
		std::vector<int> myVector = { 1, 2, 3, 4, 5 };
		int value = myVector.at(4); //int value = myVector.at(15); --> error
		std::cout << "Value: " << value << std::endl;
	}
	catch (const std::out_of_range& e5) {
		std::cerr << "Out of range error: " << e5.what() << std::endl;
	}

	return 0;
	}


	