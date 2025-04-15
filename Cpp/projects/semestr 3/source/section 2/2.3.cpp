#include <iostream>

void insertion_sort(int* a, int size);
void merge(int* a, int left, int middle, int right);

void merge_sort(int* a, int left, int right) {
    static const auto blocksize = 64;
    if (right - left + 1 <= blocksize) {
        insertion_sort(a + left, right - left + 1);
    }
    else {
        auto middle = left + (right - left) / 2;
        merge_sort(a, left, middle);
        merge_sort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}

void insertion_sort(int* a, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
			std::swap(a[j - 1], a[j]);
		}
	}
}
void merge(int* a, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];
    for (int i = 0; i < n1; i++) {
        leftArray[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = a[middle + 1 + j];
    }
    int i = 0; 
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            a[k] = leftArray[i];
            i++;
        }
        else {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = rightArray[j];
        j++;
        k++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

int main() {
    int size = 100;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = 100 - i;
    }
    merge_sort(array, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << '\n';
    }
    delete[] array;
}






//Разница между i++ и ++i, динамическое выделение памяти, namespace