#pragma once
#ifndef __DARWH__
#define __DARWH__
#include "initialize.h"
#include "move.h"
#include "food.h"


void SetRectColour(HDC hdc, RECT *rect);//改变游戏区颜色
void CreateRect(HDC hdc, RECT *rect);//创建矩形
void DrawSnake(HDC hdc, POINT *pn);//绘制蛇
void DrawFood(HDC hdc, POINT *pn, RECT *rect);


void SetRectColour(HDC hdc,RECT *rect)
{
	HBRUSH hbrush = CreateSolidBrush(Game_Green);
	FillRect(hdc, rect, hbrush);
}
void CreateRect(HDC hdc,RECT *rect)
{
	Rectangle(hdc, rect->left, rect->top, rect->right, rect->bottom);
}
void DrawSnake(HDC hdc, POINT *pn)
{
	HBRUSH hbrush = CreateSolidBrush(SnaKe_Yellow);
	SelectObject(hdc, hbrush);
	for (int i = 0; i < Snakelen; i++)
	{
		Rectangle(hdc, pn[i].x * SnaKeSize, pn[i].y * SnaKeSize, pn[i].x * SnaKeSize + SnaKeSize,pn[i].y * SnaKeSize + SnaKeSize);
	}
}
void DrawFood(HDC hdc, POINT *pn,RECT *rect)
{
	POINT Food;
	Food = CreateFood(pn,rect);
	HBRUSH hbrush = CreateSolidBrush(FoodColour);
	SelectObject(hdc, hbrush);
	Rectangle(hdc, Food.x * SnaKeSize, Food.y * SnaKeSize, Food.x * SnaKeSize + SnaKeSize, Food.y * SnaKeSize + SnaKeSize);
}
#endif