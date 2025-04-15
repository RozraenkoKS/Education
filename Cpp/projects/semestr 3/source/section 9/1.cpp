#include <iostream>

template <typename Implementation>
class Drawing_API {
public:
    void draw() const {
        Implementation::draw();
    }
};

struct Drawing_API_v1 {
    static void draw() {
        std::cout << "drawing API v1" << std::endl;
    }
};

struct Drawing_API_v2 {
    static void draw() {
        std::cout << "drawing API v2" << std::endl;
    }
};

template <typename Implementation>
class Shape {
public:
    void draw() const {
        Drawing_API<Implementation>().draw();
    }
};

template <typename Implementation>
class Triangle : public Shape<Implementation> {};

int main() {
    Triangle<Drawing_API_v1>().draw();
    Triangle<Drawing_API_v2>().draw();

    return 0;
}
