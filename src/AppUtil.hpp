#pragma once
#include <cstdint>  // 必须包含，用于uint8_t


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


	
	
};
