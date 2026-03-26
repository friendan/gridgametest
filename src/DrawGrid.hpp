#pragma once
#include <Windows.h>
#include <cstdint>  // 必须包含，用于uint8_t
#include <string>
#include <gdiplus.h>

class DrawGrid
{
public:
    // 在窗口客户区绘制边界线（顶部、底部、左侧、右侧）
	static void DrawBorder(HWND hwnd, HDC hdc);
	static void DrawPixGrid(HWND hwnd);

	static void SetHexString(const std::string& hexString);
	
	static void InitGdiPlus();
	static void UninitGdiPlus();

private:
    // GDI+ 全局变量
    static Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    static ULONG_PTR gdiplusToken;
    static std::string mHexString;
};
