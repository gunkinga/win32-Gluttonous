#ifndef __常量数据__
#define __常量数据__

#include <windows.h>
#define Snakehead 5//初始蛇头的位置
#define SnaKeSize 10//蛇的大小
#define SnakeMAX 101//蛇的最大长度
#define WindowX 400//窗口宽
#define WindowY 600//窗口高
#define TOP 1//上
#define RIGHT 2//右
#define LEFT 3//左
#define BOTTOM 4//下
#define TIMER_1 1//计时器
#define Game_Green RGB(154,205,50)//游戏背景色
#define SnaKe_Yellow RGB(138,43,226)//蛇的颜色
#define FoodColour RGB(178,34,34)//食物的颜色
static POINT Snakexy[SnakeMAX];//蛇的坐标
static POINT FOOD = {0,0};//食物的坐标
static int Snakelen = 4; //初始蛇的长度
static int Snakeposition = 0;//蛇头坐标
static int STATUS = RIGHT;//方向状态初始化为右
static int FoodStatus = 2;//食物状态 1表示食物被绘制 2表示食物没被绘制
static HWND hWnd = NULL;
#endif