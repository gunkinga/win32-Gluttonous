#pragma once
#ifndef __MOVEH__
#define __MOVEH__
#include"����.h"
#include"judge.h"
#include "food.h"


void getSnakehead(void);//��ȡ��ͷ��λ��
void MoveSnakeright(POINT *pn, RECT *rect);
void MoveSnakebottom(POINT *pn, RECT *rect);
void MoveSnaketop(POINT *pn, RECT *rect);
void MoveSnakeleft(POINT *pn, RECT *rect);
void MoveSnake(int status, POINT *pn, RECT *rect);



void MoveSnakeright(POINT *pn, RECT *rect)
{
	POINT lingshipa, lingshipb;
	getSnakehead();
	int lei = 0;
	for (int i = 0; i < Snakelen; i++)
	{
		if (lei == 0)//��һ��ִ�б����ߵ�λ��
		{
			lingshipa.x = pn[Snakeposition].x;//��ͷ���걣�浽��ʱ������
			lingshipa.y = pn[Snakeposition].y;
			pn[Snakeposition].x += 1;		 //����x�����һ
			strikesnake(pn);//�ж��Ƿ�ײ������
			strikemap(pn, rect);//�ж��Ƿ�������ͼ�߽�
			StrikFood(pn, rect);
			lei = 1;//������ͷ��λ��ֻ��Ҫִ��һ��
		}
		else
		{
			/*
			��ͷ��λ�øı�������������λ�þͻ�ı�
			��ͷ�ĺ�һ��λ�ã���Ϊ��ͷԭ��������
			��ͷ�ĺ�ڶ���λ�ã���Ϊ��ͷ�ĵ�һ��λ��
			�Դ�����
			*/
			lingshipb.x = pn[Snakeposition - i].x;
			lingshipb.y = pn[Snakeposition - i].y;
			pn[Snakeposition - i].x = lingshipa.x;
			pn[Snakeposition - i].y = lingshipa.y;
			lingshipa.x = lingshipb.x;
			lingshipa.y = lingshipb.y;
		}
	}
	STATUS = RIGHT;
}
void MoveSnakebottom(POINT *pn, RECT *rect)
{
	POINT lingshipa, lingshipb;
	getSnakehead(); 
	int lei = 0;
	for (int i = 0; i < Snakelen; i++)
	{
		if (lei == 0)//��һ��ִ�б����ߵ�λ��
		{
			lingshipa.x = pn[Snakeposition].x;
			lingshipa.y = pn[Snakeposition].y;
			pn[Snakeposition].y += 1;
			strikesnake(pn);
			strikemap(pn, rect);
			StrikFood(pn, rect);
			lei = 1;
		}
		else
		{
			lingshipb.x = pn[Snakeposition - i].x;
			lingshipb.y = pn[Snakeposition - i].y;
			pn[Snakeposition - i].x = lingshipa.x;
			pn[Snakeposition - i].y = lingshipa.y;
			lingshipa.x = lingshipb.x;
			lingshipa.y = lingshipb.y;
		}
	}
	STATUS = BOTTOM;
}
void MoveSnakeleft(POINT *pn, RECT *rect)
{
	POINT lingshipa, lingshipb;
	L2:
	getSnakehead();
	int lei = 0;
	for (int i = 0; i < Snakelen; i++)
	{
		if (lei == 0)//��һ��ִ�б����ߵ�λ��
		{
			lingshipa.x = pn[Snakeposition].x;
			lingshipa.y = pn[Snakeposition].y;
			pn[Snakeposition].x -= 1;
			strikesnake(pn);
			strikemap(pn, rect);
			StrikFood(pn, rect);
			lei = 1;
		}
		else
		{
			lingshipb.x = pn[Snakeposition - i].x;
			lingshipb.y = pn[Snakeposition - i].y;
			pn[Snakeposition - i].x = lingshipa.x;
			pn[Snakeposition - i].y = lingshipa.y;
			lingshipa.x = lingshipb.x;
			lingshipa.y = lingshipb.y;
		}
	}
	STATUS = LEFT;
}
void MoveSnaketop(POINT *pn, RECT *rect)
{
	POINT lingshipa, lingshipb;
	getSnakehead();
	int lei = 0;
	for (int i = 0; i < Snakelen; i++)
	{
		if (lei == 0)//��һ��ִ�б����ߵ�λ��
		{
			lingshipa.x = pn[Snakeposition].x;
			lingshipa.y = pn[Snakeposition].y;
			pn[Snakeposition].y -= 1;
			strikesnake(pn);
			strikemap(pn, rect);
			StrikFood(pn, rect);
			lei = 1;
		}
		else
		{
			lingshipb.x = pn[Snakeposition - i].x;
			lingshipb.y = pn[Snakeposition - i].y;
			pn[Snakeposition - i].x = lingshipa.x;
			pn[Snakeposition - i].y = lingshipa.y;
			lingshipa.x = lingshipb.x;
			lingshipa.y = lingshipb.y;
		}
	}
	STATUS = TOP;
}
void MoveSnake(int status,POINT *pn, RECT *rect)
{
	if (status == RIGHT)
		MoveSnakeright(pn,rect);
	else if (status == LEFT)
		MoveSnakeleft(pn,rect);
	else if (status == TOP)
		MoveSnaketop(pn,rect);
	else if (status == BOTTOM)
		MoveSnakebottom(pn,rect);
}
void getSnakehead(void)
{
	Snakeposition = Snakelen - 1;
}
#endif