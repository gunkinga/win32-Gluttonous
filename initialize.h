#pragma once
#ifndef __initialize__
#define __initialize__
#include"����.h"
void initializeSnakexy(POINT *pn);//��ʼ���ߵ�λ��
void initializeWindow(HWND hwnd);//��ʼ������


void initializeWindow(HWND hwnd)
{
	MoveWindow(hwnd, 400, 400, WindowX, WindowY, TRUE);
}
void initializeSnakexy(POINT *pn)
{
	for (int i = 0; i < SnakeMAX; i++)//��ʼ������
	{
		pn[i].x = 0;
		pn[i].y = 0;
	}

	for (int i = 0; i < Snakelen; i++)//�����ߵĳ�ʼ��λ��
	{
		pn[i].x = i;
		pn[i].y = 0;
	}
}
#endif