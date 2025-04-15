#include <iostream>
void printType(char x)
{
	switch (x)
	{
	case '1':
		[[fallthrough]]
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '10':
		std::cout << "Number";
		break;
	case '+':
		[[fallthrough]]
	case '-':
	case '*':
	case '/':
		std::cout << "Operator";
		break;
	case ')':
		[[fallthrough]]
	case '(':
		std::cout << "Brace";
		break;
	default:
		std::cout << "Else";
		break;
	}
	return;
}
int main()
{
	char x{};
	std::cin >> x;
	printType(x);
	std::cout << '\n';

	return 0;
}

