#include "AppUtil.hpp"
#include <cuchar>
#include <stdexcept>
#include <clocale>


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

char AppUtil::BitsToHexChar(uint8_t bits[4])
{
    uint8_t val = 0;
    val |= (bits[0] & 0x01) << 0;	// 把 bits[0]（第0位）放到 val 的第0位
    val |= (bits[1] & 0x01) << 1;	// 把 bits[1]（第1位）放到 val 的第1位  
    val |= (bits[2] & 0x01) << 2;	// 把 bits[2]（第2位）放到 val 的第2位
    val |= (bits[3] & 0x01) << 3;	// 把 bits[3]（第3位）放到 val 的第3位
    return (val < 10) ? ('0' + val) : ('A' + val - 10);	  // 将合并后的数值（0~15）转换为16进制字符并返回
}

std::string WStrToStr(const std::wstring& wstr){
	if (wstr.empty()) return {};
    int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(len, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &result[0], len, nullptr, nullptr);
    if (!result.empty()) result.pop_back();
    return result;
}

std::wstring StrToWStr(const std::string& str){
	if (str.empty()) return {};
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    std::wstring result(len, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &result[0], len);
    if (!result.empty()) result.pop_back();
    return result;
}
