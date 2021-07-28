#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK MainWindowCallback(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_SIZE:
	{
		OutputDebugStringA("WM_SIZE\n");
		break;
	}

	case WM_DESTROY:
	{
		OutputDebugStringA("WM_DESTROY\n");
		break;
	}

	case WM_CLOSE:
	{
		OutputDebugStringA("WM_CLOSE\n");
		break;
	}

	case WM_ACTIVATEAPP:
	{
		OutputDebugStringA("WM_ACTIVATE\n");
		break;
	}

	default:
	{
		result = DefWindowProc(window_handle, message, wParam, lParam);
		break;
	}
	}
	return result;
}

int CALLBACK WinMain(HINSTANCE instance,
					 HINSTANCE previous_instance,
					 LPSTR command_line,
					 int show_code)
{
	WNDCLASS window_class = {};

	window_class.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = MainWindowCallback;
	window_class.hInstance = instance;
	window_class.lpszClassName = _T("WafflzWindowClass");

	if (RegisterClass(&window_class))
	{
		HWND window_handle = CreateWindowEx(
			0,
			window_class.lpszClassName,
			_T("Wafflz"),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			instance,
			0);

		if (window_handle != NULL)
		{
			MSG message;
			for (;;)
			{
				BOOL message_result = GetMessage(&message, 0, 0, 0);
				if (message_result > 0)
				{
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			// Log create window failure
		}
	}
	else
	{
		// Log resgister failure
	}

	return 0;
}