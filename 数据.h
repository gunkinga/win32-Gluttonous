#ifndef __��������__
#define __��������__

#include <windows.h>
#define Snakehead 5//��ʼ��ͷ��λ��
#define SnaKeSize 10//�ߵĴ�С
#define SnakeMAX 101//�ߵ���󳤶�
#define WindowX 400//���ڿ�
#define WindowY 600//���ڸ�
#define TOP 1//��
#define RIGHT 2//��
#define LEFT 3//��
#define BOTTOM 4//��
#define TIMER_1 1//��ʱ��
#define Game_Green RGB(154,205,50)//��Ϸ����ɫ
#define SnaKe_Yellow RGB(138,43,226)//�ߵ���ɫ
#define FoodColour RGB(178,34,34)//ʳ�����ɫ
static POINT Snakexy[SnakeMAX];//�ߵ�����
static POINT FOOD = {0,0};//ʳ�������
static int Snakelen = 4; //��ʼ�ߵĳ���
static int Snakeposition = 0;//��ͷ����
static int STATUS = RIGHT;//����״̬��ʼ��Ϊ��
static int FoodStatus = 2;//ʳ��״̬ 1��ʾʳ�ﱻ���� 2��ʾʳ��û������
static HWND hWnd = NULL;
#endif