#pragma once
#ifndef __JUDGE__
#define __JUDGE__
#include "����.h"
void strikesnake(POINT *pn);//ײ�����ߵ�����
void strikemap(POINT *pn, RECT *rect);
void Gameover(void);


void Gameover(void)
{
	KillTimer(hWnd, TIMER_1);
	MessageBox(hWnd, "���Ѿ�����", "��Ϸ����", NULL);
	SendMessage(hWnd, WM_DESTROY, NULL, NULL);
}
void strikesnake(POINT *pn)
{
	for (int i = 0; i < Snakelen - 1; i++)
		if (pn[Snakeposition].x == pn[i].x && pn[Snakeposition].y == pn[i].y)
				Gameover();
}
void strikemap(POINT *pn,RECT *rect)
{
	int Right = rect->right / 10;
	int bottom = rect->bottom / 10;
	if (pn[Snakeposition].x == -1)//-1����Ϊ��Χ����
		Gameover();
	else if (pn[Snakeposition].x == Right)
		Gameover();
	else if (pn[Snakeposition].y == -1)
		Gameover();
	else if(pn[Snakeposition].y == bottom)
		Gameover();
}

#endif