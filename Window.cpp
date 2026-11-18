#include "Window.h"
#include <stdexcept>
Window::Window()
{
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM  lParam)
{
	switch (uMessage)
	{
	case WM_CREATE:
	{
		Window* window = (Window*)((LPCREATESTRUCT)lParam)->lpCreateParams;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);
		window->OnCreate();
		break;
	}
	case WM_DESTROY:
	{
		Window* window = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		window->OnDestroy();
		::PostQuitMessage(0);
		break;
	}
	case WM_SIZE:
	{
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
	}
	default:
		return ::DefWindowProcW(hWnd, uMessage, wParam, lParam);
	}
	

}
bool Window::Init()
{
	WNDCLASSEX  wc = {};
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"WindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WinProc;
	
	if (!::RegisterClassEx(&wc))
	{
		return false;

	}

	hWnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass", L"ConsoleEngine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, NULL, this);

	if (!hWnd)
	{
		throw std::runtime_error("Window::Init()  failed");
	}

	::ShowWindow(hWnd, SW_SHOW);
	::UpdateWindow(hWnd);

	isRunning = true;

	return true;
}

bool Window::Broadcast()
{
	MSG message;
	while (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	this->OnUpdate();
	Sleep(1);
	return true;
}

bool Window::Release()
{
	if (!::DestroyWindow(hWnd))
		return false;


	return true;
}

void Window::OnCreate()
{
}

void Window::OnUpdate()
{
}

void Window::OnDestroy()
{
	isRunning = false;
}

bool Window::isWindowRunning()
{
	return isRunning;
}

Window::~Window()
{
}
