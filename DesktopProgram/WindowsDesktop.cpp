/*Esta es la practica 12 */
/*Esto va a ser un Windows Desktop Application*/
/*zap363 Eva Luna Alvarez Calderón  AMK 1° Dev */
// Compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c


/*Variables Globales*/
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>

/*El nombre de la clase de ventana principal*/
static TCHAR szWindowClass[] = _T("DesktopApp");


/*The string that appears in the application's title bar */
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

HINSTANCE hInst;

/* Forward declarations of functions included in this code module: */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	int CALLBACK WinMain
	(


		_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPSTR	lpCmdLine,
		_In_ int	nCmdShow


	)


{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{

		MessageBox
		(
			NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);


		return 1;


	}

	/* Store instance handle in our global varible*/
	hInst = hInstance;

	/* The parameters to CreateWindow explained: */
	HWND hWnd = CreateWindow
	(
		/* szWindowClass: the name of the application */
		szWindowClass,

		/* szTitle the text that appears in the title bar */
		szTitle,

		/* WS_OVERLAPPEDWINDOW: the type of window to create */
		WS_OVERLAPPEDWINDOW,

		/* CW_USEDEFAULT , CW_USEDEFAULT: initial position (x, y) */
		CW_USEDEFAULT, CW_USEDEFAULT,

		/* 500, 100: inital size (width, length) */
		500, 100,

		/* NULL: the parent of this window is non existent (this window is an oprhan) F in chat*/
		NULL,

		/* NULL: this application does not have a menu bar*/
		NULL,

		/* hInstance: the first parameter from WinMain */
		hInstance,

		/* NULL: not used in this application (lpParam) */
		NULL





	);

	if (!hWnd)
	{
		MessageBox
		(
			NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Toy"),
			NULL
		);

		return 1;
	}


	/* The parameters to ShowWindow finally explained!!! */
	ShowWindow
	(
		/* hWnd: the value returned from CreateWindow */
		hWnd,

		/* nCmdShow: the fourth parameter from WinMain */
		nCmdShow
	);
	UpdateWindow(hWnd);

	/* Main message loop: */
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return (int)msg.wParam;

}

/* Function: WndProc (HWND, UINT, WPARAM, LPARAM) */

//PURPOSE : Processes messages for the main window.

/* WM_PAINT  - Paint the main window (what an odd way to refer to give style to the window hehe) */

/* WM_DESTROY - post a quit message and return */

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Mau! This Windows Desktop Window is done!  yay =D ");

	switch (message)
	{
	case WM_PAINT:
		
		hdc = BeginPaint(hWnd, &ps);

		/* Here the windows application finally shows something tangible to the screen hehe */
		/* For this introduction, we just print out "Hello, Mau! This Windows Desktop Windows is done... */
		/* this string is displayed in the top left corner */

		TextOut
		(

			hdc,
			5, 5,
			greeting, _tcslen(greeting)
		);
		
		/* to end the application-specific layout section */
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		
		PostQuitMessage(0);
		break;
	default: 
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;

	}

	return 0;
}