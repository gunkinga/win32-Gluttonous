#pragma once
#ifndef __initialize__
#define __initialize__
#include"数据.h"
void initializeSnakexy(POINT *pn);//初始化蛇的位置
void initializeWindow(HWND hwnd);//初始化窗口


void initializeWindow(HWND hwnd)
{
	MoveWindow(hwnd, 400, 400, WindowX, WindowY, TRUE);
}
void initializeSnakexy(POINT *pn)
{
	for (int i = 0; i < SnakeMAX; i++)//初始化数组
	{
		pn[i].x = 0;
		pn[i].y = 0;
	}

	for (int i = 0; i < Snakelen; i++)//设置蛇的初始化位置
	{
		pn[i].x = i;
		pn[i].y = 0;
	}
}
#endif