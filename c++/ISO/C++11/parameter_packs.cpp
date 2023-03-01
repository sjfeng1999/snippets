#include <array>
#include <iostream>
#include <string>
#include <utility>

template<typename T>
int print_single(const T& val) {
    std::cout << val << ", ";
    return 0;
}

template<typename... Args>
void print(Args&&... args) {
    int _[] = {print_single(args)...};
}

#if __cplusplus >= 201402L
template<size_t... Idx>
auto range_array(std::index_sequence<Idx...>) -> std::array<int, sizeof...(Idx)> {
    return {Idx...};
}
#endif

int main() {
    print(1, 3.14f, 7355608, 'A');

#if __cplusplus >= 201402L
    constexpr int kRange = 5;
    std::array<int, kRange> x = range_array(std::make_index_sequence<kRange>{});
    for (int i : x) {
        std::cout << i << ", ";
    }
#endif
    std::cout << std::endl;
    return 0;
}