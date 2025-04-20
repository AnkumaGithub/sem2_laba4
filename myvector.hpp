#include <algorithm>
#include <utility>

class MyVector {
    int* data;
    size_t size;
public:
    // Конструктор с размером
    explicit MyVector(size_t size = 0) : size(size), data(size ? new int[size] : nullptr) {}

    // Деструктор
    ~MyVector() { delete[] data; }

    // Конструктор копирования
    MyVector(const MyVector& other) : size(other.size), data(size ? new int[size] : nullptr) {
        std::copy(other.data, other.data + size, data);
    }

    // Move-конструктор
    MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Оператор присваивания копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new int[size] : nullptr;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Move-оператор присваивания
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    size_t getSize() const { return size; }
};