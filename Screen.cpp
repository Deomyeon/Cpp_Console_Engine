#include "Screen.h"



Screen::Screen(const Vector2 size, const char* const title) : screen(new WORD[(int)size.x * (int)size.y]), handle(CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL)), size(size), title(title) {}
Screen::~Screen() 
{
	delete[] this->screen;
}


void Screen::SetConsole() const
{
	CONSOLE_SCREEN_BUFFER_INFOEX sbi;
	sbi.cbSize = sizeof(sbi);
	sbi.bFullscreenSupported = FALSE;
	sbi.dwSize = { (SHORT)this->size.x, (SHORT)this->size.y };
	sbi.srWindow = { 0, 0, (SHORT)this->size.x, (SHORT)this->size.y };
	sbi.dwMaximumWindowSize = { (SHORT)this->size.x, (SHORT)this->size.y };
	sbi.dwCursorPosition = { 0, 0 };
	for (int i = 0; i < 16; i++)
	{
		sbi.ColorTable[i] = RGB(i * 17, i * 17, i * 17);
	}
	SetConsoleScreenBufferInfoEx(this->handle, &sbi); // 스크린버퍼 크기 설정 | 색 암 - 명 설정


	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 1;
	cfi.dwFontSize.Y = 1;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(this->handle, FALSE, &cfi); // 폰트사이즈 1로 설정

	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = 0;
	ci.dwSize = 1;
	SetConsoleCursorInfo(this->handle, &ci); // 커서 숨기기

	SetConsoleActiveScreenBuffer(this->handle); // 스크린 버퍼 활성화

	SetConsoleTitleA(this->title); // 타이틀 변경

	for (int x = 0; x < (int)this->size.x; x++)
	{
		for (int y = 0; y < (int)this->size.y; y++)
		{
			this->screen[y * (int)this->size.y + x] = 0;
		}
	}
}

void Screen::ResetConsole() const
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);

	CONSOLE_SCREEN_BUFFER_INFOEX sbi;
	sbi.cbSize = sizeof(sbi);
	sbi.bFullscreenSupported = FALSE;
	sbi.dwSize = { 120, 30 };
	sbi.srWindow = { 0, 0, 120, 30 };
	sbi.dwMaximumWindowSize = { 120, 30 };
	sbi.dwCursorPosition = { 0, 0 };
	sbi.ColorTable[0] = RGB(12, 12, 12);
	sbi.ColorTable[1] = RGB(0, 55, 218);
	sbi.ColorTable[2] = RGB(19, 161, 14);
	sbi.ColorTable[3] = RGB(58, 150, 221);
	sbi.ColorTable[4] = RGB(197, 15, 31);
	sbi.ColorTable[5] = RGB(136, 23, 152);
	sbi.ColorTable[6] = RGB(193, 156, 0);
	sbi.ColorTable[7] = RGB(204, 204, 204);
	sbi.ColorTable[8] = RGB(118, 118, 118);
	sbi.ColorTable[9] = RGB(59, 120, 255);
	sbi.ColorTable[10] = RGB(22, 198, 12);
	sbi.ColorTable[11] = RGB(97, 214, 214);
	sbi.ColorTable[12] = RGB(231, 72, 86);
	sbi.ColorTable[13] = RGB(180, 0, 158);
	sbi.ColorTable[14] = RGB(249, 241, 165);
	sbi.ColorTable[15] = RGB(242, 242, 242);
	sbi.wAttributes = 7;
	sbi.wPopupAttributes = 117;
	SetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = 1;
	ci.dwSize = 16;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);

	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));
}


const Vector2 Screen::GetScreenSize() const
{
	return this->size;
}


void Screen::ReSize(const Vector2 size)
{
	delete[] this->screen;
	this->size = size;
	this->screen = new WORD[(int)size.x * (int)size.y];
}


void Screen::SetPixelInScreen(const Vector2 position, const WORD color)
{
	this->screen[((int)this->size.y - 1 - (int)position.y) * (int)this->size.y + (int)position.x] = color;
}

const WORD Screen::GetPixelInScreen(const Vector2 position)
{
	return this->screen[((int)this->size.y - 1 - (int)position.y) * (int)this->size.y + (int)position.x];
}


void Screen::DrawScreen() const
{
	DWORD bytesWritten = 0;

	WriteConsoleOutputAttribute(this->handle, this->screen, (int)this->size.x * (int)this->size.y, { 0, 0 }, &bytesWritten);
}