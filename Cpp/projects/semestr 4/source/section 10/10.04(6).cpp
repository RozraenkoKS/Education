#include <iostream>
#include <memory>

class Computation
{
public:

    virtual ~Computation() = default; // note: polymorphic base class

    virtual void compute() const = 0;

}; // class Computation

struct AVX : public Computation { void compute() const override { std::cout << "AVX" << std::endl; } };
struct SSE : public Computation { void compute() const override { std::cout << "SSE" << std::endl; } };

class Computer
{
public:

    explicit Computer(std::unique_ptr<Computation> computation) : m_computation(std::move(computation))
    {
        if (!m_computation) std::cout << "invalid computation" << std::endl;
    }

    void compute() const { m_computation->compute(); }

private:

    std::unique_ptr<Computation> m_computation;

}; // class Computer

int main()
{
    Computer(std::make_unique<AVX>()).compute(); // note: instruction set for computations

    return 0;
}