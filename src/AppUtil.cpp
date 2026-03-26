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



