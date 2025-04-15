#include <iostream>
#include <locale>
#include <iomanip>

int main() {
    std::locale locale_1("ru_RU.UTF-8");
    std::locale locale_2("de_DE.UTF-8");

    std::cout.imbue(locale_1);
    std::cout << "Введите сумму денег в евро: ";
    
    std::cin.imbue(locale_2);
    long double v1{}; std::cin >> std::get_money(v1, true);

    const long double course = 99.0; 
    auto v2 = v1 * course;

    std::cout << "Сумма в рублях: " << std::showbase << std::put_money(v2, true) << std::endl;

    return 0;
}


