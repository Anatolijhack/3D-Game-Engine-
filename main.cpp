#include "AppWindow.h"

int main()
{
	AppWindow app;
	if (app.Init())
	{
		while (app.isWindowRunning())
		{
			app.Broadcast();
		}
	}
	return 0;
}