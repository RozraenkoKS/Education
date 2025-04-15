#include <iostream>

template <typename T>
void merge(T* arr, int left, int mid, int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid + 1;

    T* leftArray = new T[n1];
    T* rightArray = new T[n2];

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightArray[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        arr[k++] = (leftArray[i] <= rightArray[j]) ? leftArray[i++] : rightArray[j++];
    }

    while (i < n1) {
        arr[k++] = leftArray[i++];
    }

    while (j < n2) {
        arr[k++] = rightArray[j++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void mergeSort(T* arr, int left, int right) {
    if (left < right) {
        const int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
void mergeSort(T* arr, int size) {
    if (size < 2) {
        return;
    }
    mergeSort(arr, 0, size - 1);
}

int main() {
    const int size = 6;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = size - i;
    }

    mergeSort(arr, size);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}