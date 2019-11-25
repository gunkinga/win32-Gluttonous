#pragma once
#ifndef __FOOD__
#define __FOOD__
#include "数据.h"
#include "move.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
POINT CreateFood(POINT *pn,RECT *rect);

int StrikFood(POINT *pn, RECT *rect);

void AddSnake(POINT *pn, RECT *rect);





void AddSnake(POINT *pn,RECT *rect)
{
	POINT Snaketail;
	POINT tmep;
	if (Snakelen == SnakeMAX)
	{
		KillTimer(hWnd, TIMER_1);
		MessageBox(hWnd, "恭喜通关", "恭喜通关", NULL);
		SendMessage(hWnd, WM_DESTROY, NULL, NULL);
	}
	int Right = rect->right / 10;
	int bottom = rect->bottom / 10;
	for (int i = 0; i < Snakelen; i++)
	{
		if (pn[0].x + 1 != pn[i].x && pn[0].x + 1 != Right)//判断是否能将蛇尾添加在右边
		{
			Snaketail.x = pn[0].x + 1;
			Snaketail.y = pn[0].y;
		}
		else if (pn[0].y - 1 != pn[i].y && pn[0].y - 1 != 0)//判断是否能将蛇尾添加在上边
		{                    
			Snaketail.x = pn[0].x;
			Snaketail.y = pn[0].y - 1;
		}
		else if (pn[0].x - 1 != pn[i].x && pn[0].x - 1 != 0)
		{
			Snaketail.x = pn[0].x - 1;
			Snaketail.y = pn[0].y;
		}
		else if (pn[0].y + 1 != pn[i].y && pn[0].y + 1 != bottom)
		{
			Snaketail.x = pn[0].x;
			Snaketail.y = pn[0].y + 1;
		}
	}
	for (int i = Snakelen - 1; i > 0; i--)//为蛇尾留出空间
	{
		tmep.x = pn[i].x;
		tmep.y = pn[i].y;
		pn[i + 1].x = tmep.x;
		pn[i + 1].y = tmep.y;
	}
	//添加蛇尾
	pn[0].x = Snaketail.x;
	pn[0].y = Snaketail.y;
	Snakelen++;
	FoodStatus = 2;
		
}
int StrikFood(POINT *pn, RECT *rect)
{
	if (pn[Snakeposition].x == FOOD.x && pn[Snakeposition].y == FOOD.y)
	{
		AddSnake(pn, rect);
		return 1;
	}
	else
		return 0;

}
POINT  CreateFood(POINT *pn,RECT *rect)
{
	int Right = rect->right / 10;
	int bottom = rect->bottom / 10;
	if (FoodStatus == 2)
	{
		L1:
		srand((unsigned int)time(NULL));
		FOOD.x = rand() % Right;
		srand((unsigned int)time(NULL));
		FOOD.y = rand() % bottom;
	}
	for (int i = 0; i < Snakelen; i++)
	{
		if (FOOD.x == pn[i].x  && FOOD.y == pn[i].y)
				goto L1;
	}
	FoodStatus = 1;
	return FOOD;
}
#endif