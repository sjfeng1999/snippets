#include <iostream>
#include <type_traits>

template<typename... Ts>
struct TypeList {};

template<typename T, typename U>
struct TypePair {};

template<typename T, typename U>
struct Concat;

template<typename... Ts, typename... Us>
struct Concat<TypeList<Ts...>, TypeList<Us...>> {
    using type = TypeList<Ts..., Us...>;
};

template<typename T, typename U>
struct CartesianProduct;

template<typename... Us>
struct CartesianProduct<TypeList<>, TypeList<Us...>> {
    using type = TypeList<>;
};

template<typename T, typename... Ts, typename... Us>
struct CartesianProduct<TypeList<T, Ts...>, TypeList<Us...>> {
    using type = typename Concat<TypeList<TypePair<T, Us>...>,
                                 typename CartesianProduct<TypeList<Ts...>, TypeList<Us...>>::type>::type;
};

struct X {};

int main() {
    using InputTypeList1 = TypeList<float, int>;
    using InputTypeList2 = TypeList<double, X>;
    using ProductType = typename CartesianProduct<InputTypeList1, InputTypeList2>::type;

    static_assert(
            std::is_same<TypeList<TypePair<float, double>, TypePair<float, X>, TypePair<int, double>, TypePair<int, X>>,
                         ProductType>::value,
            "support since c++14");
    std::cout << "PASS\n";
    return 0;
}