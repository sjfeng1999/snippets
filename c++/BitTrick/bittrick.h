//
// BitTrick From `Hacker's Delight`
//

unsigned int reverseRightmostBit1(unsigned int value) {
    return value & (value - 1);
}

unsigned int reverseRightmostBit0(unsigned int value) {
    return value | (value + 1);
}

void exchangeBits(unsigned int& left, unsigned int& right) {
    left = left ^ right;
    right = left ^ right;
    left = left ^ right;
}
