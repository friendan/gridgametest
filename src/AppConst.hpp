#pragma once
#include <Windows.h>

namespace AppConst
{
	// 二进制值(0~15) → 16进制字符
	constexpr char BinTohex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	constexpr int BORDER_LINE_OFFSET = 2;	// 表示：从顶部/底部/左侧/右侧 数第几条线
	constexpr int BORDER_LINE_COUNT  = 2;	// 表示：从顶部/底部/左侧/右侧 依次画N条线
	constexpr COLORREF BORDER_COLOR  = RGB(255, 0, 0);


}
