#include <iostream>

#include "bittrick.h"

bool TestReverseRightmostBit1() {
    bool res = true;
    res &= (reverseRightmostBit1(0xffffffffu) == 0xfffffffeu);
    res &= (reverseRightmostBit1(0x00000001u) == 0x00000000u);
    res &= (reverseRightmostBit1(0x00000000u) == 0x00000000u);
    return res;
}

bool TestReverseRightmostBit0() {
    bool res = true;
    res &= (reverseRightmostBit0(0xffffffffu) == 0xffffffffu);
    res &= (reverseRightmostBit0(0x00000001u) == 0x00000003u);
    res &= (reverseRightmostBit0(0x00000000u) == 0x00000001u);
    return res;
}

bool TestExchangeBits() {
    bool res = true;
    auto fn = [](unsigned int x, unsigned int y) {
        unsigned int old_x = x;
        unsigned int old_y = y;
        exchangeBits(x, y);
        return x == old_y && y == old_x;
    };
    res &= fn(0xffffffffu, 0xffffffffu);
    res &= fn(0x00000000u, 0x00000000u);
    res &= fn(0x01010101u, 0x10101010u);
    return res;
}

int main() {
    bool res = true;
    res &= TestReverseRightmostBit1();
    res &= TestReverseRightmostBit0();
    res &= TestExchangeBits();

    if (res) {
        std::cout << ">>>>> Test Passed <<<<<" << std::endl;
    } else {
        std::cout << ">>>>> Test Failed <<<<<" << std::endl;
    }
    return 0;
}