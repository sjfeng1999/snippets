#include <iostream>

#include "macro.h"

bool TestMacroConcat() {
    bool res = true;
    int val, a, vala = 1;
    res &= (MACRO_CONCAT(123, 456) == 123456);
    res &= (MACRO_CONCAT(val, a) == vala);
    return res;
}

bool TestMacroTuple() {
    bool res = true;
    res &= (MACRO_TUPLE_GET(0, (0, 1, 2)) == 0);
    res &= (MACRO_TUPLE_GET(1, (0, 1, 2)) == 1);
    res &= (MACRO_TUPLE_GET(2, (0, 1, 2)) == 2);
    return res;
}

int main() {
    bool res = true;
    res &= TestMacroConcat();
    res &= TestMacroTuple();

    if (res) {
        std::cout << ">>>>> Test Passed <<<<<" << std::endl;
    } else {
        std::cout << ">>>>> Test Failed <<<<<" << std::endl;
    }
    return 0;
}