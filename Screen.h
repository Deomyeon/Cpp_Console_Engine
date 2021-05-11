#pragma once

#include <Windows.h>
#include <array>
#include "Vector2.h"
#include "Color.h"


class Screen
{
private:
	WORD*			screen; // 화면
	const HANDLE	handle; // 콘솔 핸들
	Vector2			size;	// 화면 크기
	const char*		title; // 콘솔 타이틀
	std::array<Color, 2>	colorToColor; // 두 색

public:

					Screen(const Vector2 size, const char* const title, std::array<Color, 2> colorToColor);
					~Screen();

	void			SetConsole() const; // 콘솔 설정
	void			ResetConsole() const; // 콘솔 초기화

	const Vector2	GetScreenSize() const; // 화면 크기 리턴

	void			ReSize(const Vector2 size);
	void			SetColorToColor(const std::array<Color, 2> colorToColor);

	void			SetPixelInScreen(const Vector2 position, const WORD color); // (x, y) 위치의 픽셀을 color 값으로 바꿈.
	const WORD		GetPixelInScreen(const Vector2 position); // (x, y) 위치의 픽셀을 얻어옴.

	void			DrawScreen() const; // 화면 출력
};