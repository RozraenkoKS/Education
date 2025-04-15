//Реализуйте алгоритм бинарного поиска заданного пользователем значения в заранее отсортированном встроенном динамическом массиве целочисленных значений. Минимизируйте количество сравнений в цикле поиск

#include <iostream>
#include <optional>



template <typename T1, typename T2>
std::optional<int> bin_search(T1* arr, int size, T2 target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        T1 middle = arr[mid];

        if (middle < target) {
            left = mid + 1;
        }
        else if (middle > target) {
            right = mid - 1;
        }
        else {
            return mid;  
        }
    }

    return std::nullopt;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid array size. Please enter a positive number." << std::endl;
        return 1; 
    }

    double* array = new double[size];

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    double target;
    std::cout << "Enter the target value to search: ";
    std::cin >> target;

    auto result = bin_search(array, size, target);

    if (result.has_value()) {
        std::cout << "Value found at index: " << result.value() << std::endl;
    }
    else {
        std::cout << "Value not found." << std::endl;
    }

    delete[] array;

    return 0;
}
