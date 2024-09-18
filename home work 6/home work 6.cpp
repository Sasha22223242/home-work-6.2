#include <iostream>
#include <locale>

void SeparateNumbers(int* array, int size, int*& positiveArray, int*& negativeArray, int& positiveSize, int& negativeSize) {
    positiveSize = 0;
    negativeSize = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0)
            positiveSize++;
        else if (array[i] < 0)
            negativeSize++;
    }

    positiveArray = new int[positiveSize];
    negativeArray = new int[negativeSize];

    int posIndex = 0, negIndex = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0)
            positiveArray[posIndex++] = array[i];
        else if (array[i] < 0)
            negativeArray[negIndex++] = array[i];
    }
}

void ShowArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int size;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> size;

    int* array = new int[size];
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    int* positiveArray = nullptr;
    int* negativeArray = nullptr;
    int positiveSize = 0, negativeSize = 0;

    SeparateNumbers(array, size, positiveArray, negativeArray, positiveSize, negativeSize);

    std::cout << "Додатні числа: ";
    ShowArray(positiveArray, positiveSize);
    std::cout << "Від'ємні числа: ";
    ShowArray(negativeArray, negativeSize);

    delete[] array;
    delete[] positiveArray;
    delete[] negativeArray;

    return 0;
}
