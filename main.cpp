#include "myvector.hpp"
#include <chrono>
#include <iostream>

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

int main() {
    testCopyVsMove();
    return 0;
}