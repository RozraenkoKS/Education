#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <exception>

class Error : public std::exception {
public:
	explicit Error(const std::string& message) noexcept :
		std::exception(message.c_str()) {
	}
};

enum class Device {
	mobile,
	tablet,
	laptop,
};

class Computer {
public:

	virtual ~Computer() = default; // note: polymorphic base class

	virtual void run() const = 0;
};

class Mobile : public Computer { public: void run() const override { std::cout << "Mobile" << std::endl; }; };
class Tablet : public Computer { public: void run() const override { std::cout << "Tablet" << std::endl; }; };
class Laptop : public Computer { public: void run() const override { std::cout << "Laptop" << std::endl; }; };

class Factory {
public:

	auto code(Device device) const {
		switch (device) {
		case Device::mobile: return m_mobile_code;
		case Device::tablet: return m_tablet_code;
		case Device::laptop: return m_laptop_code;
		}
		throw Error("No device with such code");
	}

	void show_devices() const {
		std::cout << "Avalible devices are mobile, tablet and laptop\n";
	}

	[[nodiscard]] auto create_device(Device device) const {
		auto it = create.find(device);
		if (it != std::end(create)) {
			return it->second();
		}
		else {
			throw Error("Device creation function not found\n");
		}
	}

private:
	const std::map<Device, std::function<std::unique_ptr<Computer>()>> create{
		{Device::mobile, [this]() {
			std::cout << "Mobile created\n";
			std::cout << "The code is: " << m_mobile_code << '\n';
			return std::make_unique<Mobile>();
		}},
		{Device::tablet, [this]() {
			std::cout << "Tablet created\n";
			std::cout << "The code is: " << m_tablet_code << '\n';
			return std::make_unique<Tablet>();
		}},
		{Device::laptop, [this]() {
			std::cout << "Laptop created\n";
			std::cout << "The code is: " << m_laptop_code << '\n';
			return std::make_unique<Laptop>();
		}},
	};

	int m_mobile_code{ 0 };
	int m_tablet_code{ 1 };
	int m_laptop_code{ 2 };

};

int main() {
	Factory factory;
	factory.show_devices();

	std::cout << std::endl;

	std::cout << "Code for Mobile: " << factory.code(Device::mobile) << std::endl;
	std::cout << "Code for Tablet: " << factory.code(Device::tablet) << std::endl;
	std::cout << "Code for Laptop: " << factory.code(Device::laptop) << std::endl;

	std::cout << std::endl;

	auto mobile = factory.create_device(Device::mobile);
	mobile->run();

	std::cout << std::endl;

	auto tablet = factory.create_device(Device::tablet);
	tablet->run();

	std::cout << std::endl;

	auto laptop = factory.create_device(Device::laptop);
	laptop->run();

	std::cout << std::endl;

	return 0;
}