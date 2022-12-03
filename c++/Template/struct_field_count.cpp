#include <iostream>
#include <type_traits>
#include <utility>

struct Foo {
    int a;
    float b;
};

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
consteval auto Impl(std::index_sequence<Index...>) -> decltype(Tp{ToAnyFieldType{Index}...});

template<typename Tp, size_t... Index>
consteval int Impl(...);

template<typename Tp, size_t... Index>
consteval auto FieldCountGuessImpl(std::index_sequence<Index...> index_seq) {
    return !std::is_same_v<decltype(Impl<Tp>(index_seq)), int>;
}

template<typename Tp, int GieldCount>
consteval bool FieldCountGuess() {
    return FieldCountGuessImpl<Tp>(std::make_index_sequence<GieldCount>{});
}

int main() {
    std::cout << "Guess Class Foo field count is greater than or equal to 1 : "
              << (FieldCountGuess<Foo, 1>() ? "true" : "false") << "\n"
              << "Guess Class Foo field count is greater than or equal to 2 : "
              << (FieldCountGuess<Foo, 2>() ? "true" : "false") << "\n"
              << "Guess Class Foo field count is greater than or equal to 3 : "
              << (FieldCountGuess<Foo, 3>() ? "true" : "false") << "\n";
    Foo f;
    auto& [a, b] = f;
    std::cout << "First field type : " << typeid(decltype(a)).name() << "\n"
              << "Second field type : " << typeid(decltype(b)).name() << "\n";
    return 0;
}