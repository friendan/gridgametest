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

public:
	static size_t mWidth;
	static size_t mHeight;
	static size_t mTotalPage;
	static size_t mPageSize;
	static size_t mCurPage;
	static std::string mHexString;

private:
    // GDI+ 全局变量
    static Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    static ULONG_PTR gdiplusToken;
    static size_t mDrawWidth;
    static size_t mDrawHeight;
};
