#pragma once
#include <Windows.h>
#include <cstdint>  // 必须包含，用于uint8_t
#include <string>

class AppUtil
{
public:
	// 输入：16进制字符（0-9, A-F, a-f）
	// 输出：一个uint8_t，低4位存储二进制结果（高4位为0）
	// 例如：'A' → 0x0A → 二进制 0000 1010
	/*
		uint8_t bin = AppUtil::HexCharToBits('A'); // 调用
		// bin = 10 (0x0A)，二进制：0000 1010
		// 想取每一位直接用位运算：
		uint8_t bit0 = bin & 0x01;        // 第1位
		uint8_t bit1 = (bin >> 1) & 0x01; // 第2位
		uint8_t bit2 = (bin >> 2) & 0x01; // 第3位
		uint8_t bit3 = (bin >> 3) & 0x01; // 第4位
	*/
	static uint8_t HexCharToBits(char hexChar);
	static void HexCharToBits(char hexChar, uint8_t bits[4]);


	/***********************************************************
	 * 功能：将4位二进制数组 转换为 对应的16进制字符（反向转换函数）
	 * 输入：uint8_t bits[4]
	 *       bits[0] = 二进制第0位（最低位）
	 *       bits[1] = 二进制第1位
	 *       bits[2] = 二进制第2位
	 *       bits[3] = 二进制第3位（最高位）
	 *
	 * 返回值：char 类型的16进制字符（0-9，A-F）
	 **********************************************************/
	static char BitsToHexChar(uint8_t bits[4]);


	std::string WStrToStr(const std::wstring& wstr);
	std::wstring StrToWStr(const std::string& str);
	
};
