#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 100;
const int minsize = 10;

int MinSum(int arr[], int start, int currentMinSum, int currentPos, int& minPos) {
    if (start > size - minsize) {
        return currentMinSum;
    }

    int currentSum = 0;
    for (int i = 0; i < minsize; i++) {
        currentSum += arr[start + i];
    }

    if (currentSum < currentMinSum) {
        currentMinSum = currentSum;
        minPos = start;
    }

    return MinSum(arr, start + 1, currentMinSum, currentPos, minPos);
}
int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned>(time(0)));
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    int minPos = 0;
    MinSum(arr, 0, INT_MAX, 0, minPos);

    std::cout << "Начало позиции из 10 чисел с мин суммой: " << minPos << std::endl;

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int max(int arr[], int size) {
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int max(int** arr, int rows, int cols) {
    int maxValue = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxValue) {
                maxValue = arr[i][j];
            }
        }
    }
    return maxValue;
}

int max(int*** arr, int depth, int rows, int cols) {
    int maxValue = arr[0][0][0];
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                if (arr[i][j][k] > maxValue) {
                    maxValue = arr[i][j][k];
                }
            }
        }
    }
    return maxValue;
}

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 10;
    int arr[SIZE] = { 1, 5, 3, 9, 2, 8, 7, 6, 4, 0 };
    std::cout << "Макс значение в одномерном массиве: " << max(arr, SIZE) << std::endl;

    const int ROWS = 3;
    const int COLS = 4;
    int** arr2D = new int* [ROWS];
    for (int i = 0; i < ROWS; i++) {
        arr2D[i] = new int[COLS] {1, 2, 3, 4};
    }
    std::cout << "Макс значение в двумерном массиве: " << max(arr2D, ROWS, COLS) << std::endl;

    const int DEPTH = 2;
    int*** arr3D = new int** [DEPTH];
    for (int i = 0; i < DEPTH; i++) {
        arr3D[i] = new int* [ROWS];
        for (int j = 0; j < ROWS; j++) {
            arr3D[i][j] = new int[COLS] {1, 2, 3, 4};
        }
    }
    std::cout << "Макс значение в трехмерном массиве: " << max(arr3D, DEPTH, ROWS, COLS) << std::endl;

    std::cout << "Макс значение между 5 и 10: " << max(5, 10) << std::endl;
    std::cout << "Макс значение между 5, 10 и 15: " << max(5, 10, 15) << std::endl;

    for (int i = 0; i < ROWS; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;

    for (int i = 0; i < DEPTH; i++) {
        for (int j = 0; j < ROWS; j++) {
            delete[] arr3D[i][j];
        }
        delete[] arr3D[i];
    }
    delete[] arr3D;

    return 0;
}
