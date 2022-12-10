#include <iostream>
#include <type_traits>
#include <utility>

struct ToAnyFieldType {
    size_t ignore;

    template<typename Tp>
    consteval operator Tp&() const&& noexcept {
        constexpr void* ptr = nullptr;
        // use std::declval() will fail in static_assert
        return *static_cast<std::remove_reference_t<Tp>*>(ptr);
    }
};

template<typename Tp, size_t... Index>
    requires requires { Tp{ToAnyFieldType{Index}...}; }
consteval auto FieldCountGuessImpl(std::index_sequence<Index...> index_seq) {
    return true;
}

template<typename Tp, size_t... Index>
consteval auto FieldCountGuessImpl(...) {
    return false;
}

template<typename Tp, size_t Low, size_t High>
consteval size_t getFieldCountImpl() {
    if constexpr (Low == High) {
        return Low;
    }
    constexpr size_t kMid = (Low + High + 1) >> 1;
    if constexpr (FieldCountGuessImpl<Tp>(std::make_index_sequence<kMid>{})) {
        return getFieldCountImpl<Tp, kMid, High>();
    } else {
        return getFieldCountImpl<Tp, Low, kMid - 1>();
    }
}

template<typename Tp>
consteval size_t getFieldCount() {
    return getFieldCountImpl<Tp, 0, sizeof(Tp)>();
}

struct struct2field {
    int a;
    float b;
};

struct struct3field {
    int a;
    float b;
    char c;
};

int main() {
    std::cout << "Class field count is : " << getFieldCount<struct2field>() << "\n"
              << "Class field count is : " << getFieldCount<struct3field>() << "\n";
    return 0;
}