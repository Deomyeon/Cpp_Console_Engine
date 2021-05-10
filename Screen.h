#pragma once

#include <Windows.h>
#include "Vector2.h"


class Screen
{
private:
	WORD*			screen; // ȭ��
	const HANDLE	handle; // �ܼ� �ڵ�
	Vector2			size;	// ȭ�� ũ��
	const char*		title; // �ܼ� Ÿ��Ʋ
public:

					Screen(const Vector2 size, const char* const title);
					~Screen();

	void			SetConsole() const; // �ܼ� ����
	void			ResetConsole() const; // �ܼ� �ʱ�ȭ

	const Vector2	GetScreenSize() const; // ȭ�� ũ�� ����

	void			ReSize(const Vector2 size);

	void			SetPixelInScreen(const Vector2 position, const WORD color); // (x, y) ��ġ�� �ȼ��� color ������ �ٲ�.
	const WORD		GetPixelInScreen(const Vector2 position); // (x, y) ��ġ�� �ȼ��� ����.

	void			DrawScreen() const; // ȭ�� ���
};