#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<ctype.h>
#include "Darw.h"
#pragma comment(lib,"User32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK Wndproc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevlnstance, PSTR szCmdLine, int iCmdshow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	/*初始化窗口类-----------------------------------------*/
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //窗口风格
	wndclass.lpfnWndProc = Wndproc;			  //窗口消息处理函数
	wndclass.cbClsExtra = 0;				  //窗口扩展
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hlnstance;			  //程序句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//程序图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//鼠标图标
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景颜色
	wndclass.lpszMenuName = NULL; //菜单名字
	wndclass.lpszClassName = szAppName;//窗口类名
	/*------------------------------------------------------*/

	/*注册窗口类*/
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("没有注册成功"), szAppName, MB_ICONERROR);
		return 0;
	}

	/*创建窗口类*/
	hwnd = CreateWindow(szAppName,	//窗口类名
		TEXT("贪吃蛇"),	//窗口标题
		WS_OVERLAPPEDWINDOW,		//窗格格式
		CW_USEDEFAULT,              //水平位置
		CW_USEDEFAULT,				//垂直位置
		CW_USEDEFAULT,				//窗口宽度
		CW_USEDEFAULT,				//窗口高度
		NULL,						//父窗口句柄
		NULL,						//窗口菜单句柄
		hlnstance,					//程序实例句柄
		NULL,						//创建参数
		);
	ShowWindow(hwnd, iCmdshow);//指定窗口如何显示
	UpdateWindow(hwnd);		   //指示窗口自我更新
	hWnd = hwnd;
	while (GetMessage(&msg, NULL, 0, 0))//消息循环
	{
		TranslateMessage(&msg);//获取键盘消息转换为字符消息然后发送到消息队列中
		DispatchMessage(&msg); //将消息调度到窗口过程
	}






	return msg.wParam;
}
LRESULT CALLBACK Wndproc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//设备句柄
	PAINTSTRUCT ps;//绘图结构
	RECT rect;
	char pd;
	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &rect);
		initializeWindow(hwnd);
		initializeSnakexy(&Snakexy);
		SetTimer(hwnd, TIMER_1, 500, NULL);
		return 0;
	case WM_TIMER:
		hdc = GetDC(hwnd); 
		GetClientRect(hwnd, &rect);
		MoveSnake(STATUS, Snakexy,&rect);
		InvalidateRect(hwnd,NULL, TRUE);
		UpdateWindow(hwnd);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_CHAR:
		pd = wParam;
		tolower(pd);
		switch (pd)
		{
		case 'w':
			if(STATUS != BOTTOM)
			STATUS = TOP;
			break;
		case 's':
			if (STATUS != TOP)
			STATUS = BOTTOM;
			break;
		case 'a':
			if (STATUS != RIGHT)
			STATUS = LEFT;
			break;
		case 'd':
			if (STATUS != LEFT)
			STATUS = RIGHT;
			break;
		default:
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		CreateRect(hdc, &rect);
		SetRectColour(hdc, &rect);
		DrawSnake(hdc, Snakexy, &rect);
		DrawFood(hdc, Snakexy,&rect);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hwnd, TIMER_1);
		PostQuitMessage(0);
		return 0;
	}


	return DefWindowProc(hwnd, message, wParam, lParam);
}
