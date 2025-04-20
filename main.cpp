#include "myvector.hpp"
#include "swap.hpp"
#include "array.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>

void testCopyVsMove() {
    const size_t N = 1000000000;

    // Создание большого вектора
    MyVector vec(N);

    // Измерение копирования
    auto start = std::chrono::high_resolution_clock::now();
    MyVector copy = vec;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // Измерение перемещения
    start = std::chrono::high_resolution_clock::now();
    MyVector moved = std::move(vec);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

void testSwap() {
    // Тест с int
    int a = 5, b = 10;
    mySwap(a, b);
    std::cout << "After Swap<int>: a = " << a << ", b = " << b << "\n";

    // Тест с std::string
    std::string s1 = "Hello", s2 = "World";
    mySwap(s1, s2);
    std::cout << "After Swap<string>: s1 = " << s1 << ", s2 = " << s2 << "\n";
}

void testContainerToString() {
    std::vector<int> vec = {1, 2, 3};
    std::list<double> lst = {4.5, 6.7, 8.9};
    std::set<std::string> st = {"BombordiroCrocodilo", "TralalelaTralalalo", "tuntuntunsahur"};

    std::cout << "Vector to string: " << containerToString(vec) << "\n";
    std::cout << "List to string: " << containerToString(lst) << "\n";
    std::cout << "Set to string: " << containerToString(st) << "\n";
}

void testArray() {
    MyArray<int, 5> intArr;
    for (size_t i = 0; i < intArr.size(); ++i) {
        intArr[i] = i * 10;
    }
    std::cout << "Array<int, 5>: ";
    for (size_t i = 0; i < intArr.size(); ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n";

    MyArray<std::string, 3> strArr;
    strArr[0] = "BombordiniGussini";
    strArr[1] = "BaleriniCaphuchini";
    strArr[2] = "SpioniroGolubini";
    std::cout << "Array<string, 3>: ";
    for (size_t i = 0; i < strArr.size(); ++i) {
        std::cout << strArr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    testCopyVsMove();
    testSwap();
    testContainerToString();
    testArray();
    return 0;
}