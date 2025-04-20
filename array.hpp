#include <sstream>
#include <stdexcept>

template <typename T, size_t len>
class MyArray {
    T data[len];
public:
    T& operator[](size_t index) {
        if (index >= len) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= len) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const { return len; }
};