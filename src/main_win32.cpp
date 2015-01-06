#include <windows.h>

LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_DESTROY: // pass through
	case WM_CLOSE:
		::PostQuitMessage(0);
		break;

	}

	return ::DefWindowProc(window, message, wParam, lParam);
}


int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow)
{
	WNDCLASSA wc = {};
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = instance;
	wc.lpszClassName = "game";

	if (::RegisterClass(&wc))
	{
		HWND window = ::CreateWindowEx(0, wc.lpszClassName, "\"game\"", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 960, 540, 0, 0, instance, 0);
		if (window)
		{
			::ShowCursor(0);

			bool running = true;
			while (running)
			{
				MSG msg;
				while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
					{
						running = false;
					}
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				HDC dc = ::GetDC(window);
				::PatBlt(dc, 0, 0, 960, 540, BLACKNESS);
				::ReleaseDC(window, dc);
				
				// render game here
				::Sleep(10);
			}

		}

	}

	return 0;
}