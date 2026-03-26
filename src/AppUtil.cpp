#include "AppUtil.hpp"



uint8_t AppUtil::HexCharToBits(char hexChar)
{
	uint8_t value = 0;

    // 转换为 0~15 的值
    if (hexChar >= '0' && hexChar <= '9') {
        value = hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        value = 10 + (hexChar - 'A');
    } else if (hexChar >= 'a' && hexChar <= 'f') {
        value = 10 + (hexChar - 'a');
    }
    return value;   // 返回的 value 本身就是4位二进制值
}

void AppUtil::HexCharToBits(char hexChar, uint8_t bits[4]){
	uint8_t bin = AppUtil::HexCharToBits(hexChar);
	// 下标 0~3 直接对应 二进制第0位~第3位
	bits[0] =  bin        & 1;  // 第0位（最低位）
	bits[1] = (bin >> 1)  & 1;  // 第1位
	bits[2] = (bin >> 2)  & 1;  // 第2位
	bits[3] = (bin >> 3)  & 1;  // 第3位（最高位）
}


