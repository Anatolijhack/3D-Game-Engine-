#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	bool Init();
	bool Broadcast();
	bool Release();
	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnDestroy();
	bool isWindowRunning();

	~Window();
protected:
	HWND hWnd;
	bool isRunning = false;
};

