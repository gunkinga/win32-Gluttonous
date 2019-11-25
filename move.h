#pragma once
#ifndef __MOVEH__
#define __MOVEH__
#include"数据.h"
#include"judge.h"
#include "food.h"


void getSnakehead(void);//获取蛇头的位置
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
		if (lei == 0)//第一次执行保存蛇的位置
		{
			lingshipa.x = pn[Snakeposition].x;//蛇头坐标保存到临时变量中
			lingshipa.y = pn[Snakeposition].y;
			pn[Snakeposition].x += 1;		 //右移x坐标加一
			strikesnake(pn);//判断是否撞到自身
			strikemap(pn, rect);//判断是否碰到地图边界
			StrikFood(pn, rect);
			lei = 1;//由于蛇头的位置只需要执行一次
		}
		else
		{
			/*
			蛇头的位置改变过后，蛇身的坐标位置就会改变
			蛇头的后一个位置，改为蛇头原来的坐标
			蛇头的后第二个位置，改为蛇头的第一个位置
			以此类推
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
		if (lei == 0)//第一次执行保存蛇的位置
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
		if (lei == 0)//第一次执行保存蛇的位置
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
		if (lei == 0)//第一次执行保存蛇的位置
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