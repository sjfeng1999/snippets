#include <iostream>
#include <type_traits>

template<typename T>
struct Foo {
    // the following code is not work
    // 
    // std::enable_if_t<std::is_same_v<T, int>> print() {
    //     std::cout << "print Int type\n";
    // }
    // std::enable_if_t<std::is_same_v<T, float>> print() {
    //     std::cout << "print Float type\n";
    // }
    //

    template<typename _T = T>
    std::enable_if_t<std::is_same_v<_T, int>> print() {
        std::cout << "print Int type\n";
    }

    template<typename _T = T>
    std::enable_if_t<std::is_same_v<_T, float>> print() {
        std::cout << "print Float type\n";
    }
};

int main() {
    Foo<int> f1;
    Foo<float> f2;
    f1.print();
    f2.print();
}