#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Класс для модели Изинга
class IsingModel {
public:

    // Конструктор класса IsingModel
    IsingModel(int width, int height) : width(width), height(height), gen(std::random_device{}()), dis(0.0, 1.0) {
        lattice.resize(width, std::vector<bool>(height));
        for (auto i = 0; i < width; ++i) {
            for (auto j = 0; j < height; ++j) {
                lattice[i][j] = dis(gen) < 0.5 ? false : true;
            }
        }
    }

    // Печать решётки (для проверки)
    void printLattice() const {
        for (auto i = 0; i < width; ++i) {
            for (auto j = 0; j < height; ++j) {
                std::cout << (lattice[i][j] ? '+' : '-') << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    // Получение значения спина в позиции (x, y)
    int getSpin(int x, int y) const {
        return lattice[x][y];
    }

    // Получение значения спина соседнего узла с учётом периодических граничных условий
    int getNeighborSpin(int x, int y) const {
        x = (x + width) % width;
        y = (y + height) % height;
        return lattice[x][y];
    }

    // Вычисление изменения энергии при перевороте спина
    int calculateEnergyChange(int x, int y, double magneticField) const {
        auto spin = lattice[x][y];
        auto neighborSum = getNeighborSpin(x + 1, y) + getNeighborSpin(x - 1, y) + getNeighborSpin(x, y + 1) + getNeighborSpin(x, y - 1);
        return 2 * spin * (neighborSum + magneticField);
    }

    // Обновление состояния модели
    void update(double temperature, double magneticField) {
        for (auto i = 0; i < width; ++i) {
            for (auto j = 0; j < height; ++j) {
                auto dE = calculateEnergyChange(i, j, magneticField);
                if (dE < 0 || dis(gen) < std::exp(-dE / temperature)) {
                    lattice[i][j] = !lattice[i][j];
                }
            }
        }
    }

private:

    int width, height;
    std::vector<std::vector<bool>> lattice;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
};

// Главная функция
int main() {
    const auto size = 10;  // Размер решётки
    IsingModel model(size, size);

    auto temperature = 298.0;   // Начальная температура
    auto magneticField = 10; // Начальное магнитное поле

    // Печать начального состояния решётки
    std::cout << "Initial lattice:\n";
    model.printLattice();

    // Обновление состояния решётки
    for (auto step = 0; step < 100; ++step) {
        model.update(temperature, magneticField);
    }

    // Печать конечного состояния решётки
    std::cout << "Final lattice after 100 steps:\n";
    model.printLattice();

    return 0;
}

