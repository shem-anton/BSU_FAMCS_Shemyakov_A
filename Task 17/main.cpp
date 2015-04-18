//#undef UNICODE

#include <windows.h>

#define TIMER 1

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";

static int count = 0;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{	
HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;

	wcApp.lpszClassName = (LPCWSTR)szClassName;
	wcApp.hInstance		= hInstance;   
	wcApp.lpfnWndProc	= WndProc;
	wcApp.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wcApp.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName	= 0;
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style			= CS_HREDRAW | CS_VREDRAW;
	wcApp.cbClsExtra	= 0;
	wcApp.cbWndExtra	= 0;
	
	if (!RegisterClass(&wcApp)){
		MessageBox(NULL, L"Class hasn't been registered", L"RegisterClass", MB_OK);
		return 0;
	}

	hWnd=CreateWindow((LPCWSTR)szClassName, L"Simple Windows Program", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg,0,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
	SetTimer(hWnd, TIMER, 1000, NULL);
	HDC hdc;
	PAINTSTRUCT ps;

	switch (uMsg) {
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		RECT r;
		GetClientRect(hWnd,&r);
		HBRUSH MyBrush, OldBrush;
		MyBrush = CreateSolidBrush(RGB(70,70,70));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

		Rectangle(hdc, r.right/2 - (r.bottom - 20)/5, 10, r.right/2 + (r.bottom - 20)/5, r.bottom - 10);

		MyBrush = CreateSolidBrush(RGB(100,50,50));
		SelectObject(hdc, MyBrush);

		Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.015*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.316);

		MyBrush = CreateSolidBrush(RGB(100,100,50));
		SelectObject(hdc, MyBrush);

		Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.348*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.649);

		MyBrush = CreateSolidBrush(RGB(50,100,50));
		SelectObject(hdc, MyBrush);

		Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.681*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.982);

		if(count%11 == 0 || count%11 == 1 || count%11 == 3)
		{
			MyBrush = CreateSolidBrush(RGB(250,50,50));
			SelectObject(hdc, MyBrush);
			Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.015*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.316);
		}
		else if(count%11 == 6 || count%11 == 7 || count%11 == 9)
			{
				MyBrush = CreateSolidBrush(RGB(50,250,50));
				SelectObject(hdc, MyBrush);
				Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.681*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.982);
			}
			else if(count%11 == 5 || count%11 == 10)
				{
					MyBrush = CreateSolidBrush(RGB(250,250,50));
					SelectObject(hdc, MyBrush);
					Ellipse(hdc, r.right/2 - (r.bottom - 20)*0.16, 10 + 0.348*(r.bottom - 20),r.right/2 + (r.bottom - 20)*0.16, 10 + (r.bottom - 20)*0.649);
				}
		SelectObject(hdc, OldBrush);
		DeleteObject(MyBrush);
		EndPaint(hWnd,&ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		if(wParam == TIMER)
			count++;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	default:
		return (DefWindowProc(hWnd,uMsg,wParam,lParam));
	}
	return (0);
}
