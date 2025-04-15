#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

enum class Procstatus { suspended, running };

enum class Platforms { p32bit, p64bit };

struct Procinfo {
	int id;
	std::string name;
	Procstatus status;
	std::string account;
	size_t memory;
	Platforms platform;
};

std::string status_to_string(Procstatus status)
{
	if (status == Procstatus::suspended) return "suspended";
	else return "running";
}

std::string platform_to_string(Platforms platform)
{
	if (platform == Platforms::p32bit) return "32-bit";
	else return "64-bit";
}

void print_processes(std::vector<Procinfo> processes)
{
	std::sort(
		std::begin(processes), std::end(processes),
		[](Procinfo const& p1, Procinfo const& p2) {
			return p1.name < p2.name; });
	for (auto const& pi : processes)
	{
		std::cout << std::left << std::setw(25) << std::setfill(' ')
			<< pi.name;
		std::cout << std::left << std::setw(8) << std::setfill(' ')
			<< pi.id;
		std::cout << std::left << std::setw(12) << std::setfill(' ')
			<< status_to_string(pi.status);
		std::cout << std::left << std::setw(15) << std::setfill(' ')
			<< pi.account;
		std::cout << std::right << std::setw(10) << std::setfill(' ')
			<< (int)(pi.memory / 1024);
		std::cout << std::left << ' ' << platform_to_string(pi.platform);
		std::cout << std::endl;
	}
}

int main()
{
	using namespace std::literals;
	std::vector<Procinfo> processes
	{
	{512, "cmd.exe"s, Procstatus::running, "SYSTEM"s,
	148293, Platforms::p64bit },
	{1044, "chrome.exe"s, Procstatus::running, "USER"s,
	25180454, Platforms::p32bit},
	{7108, "explorer.exe"s, Procstatus::running, "USER"s,
	2952943, Platforms::p64bit },
	{10100, "chrome.exe"s, Procstatus::running, "USER"s,
	227756123, Platforms::p32bit},
	{22456, "skype.exe"s, Procstatus::suspended, "USER"s,
	16870123, Platforms::p64bit },
	};
	print_processes(processes);
}
