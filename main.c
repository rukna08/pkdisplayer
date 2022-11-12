#include <windows.h>

#include "main.h"

int WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance, LPSTR CommandLine, int CommandShow) {
    
    WNDCLASSEXA WindowClass = {0};
 
    WindowClass.cbSize = sizeof(WNDCLASSEXA);

    WindowClass.lpfnWndProc = WindowProc;
    
    WindowClass.hInstance = Instance;
    
    WindowClass.hIcon = LoadIconA(0, IDI_APPLICATION);
    
    WindowClass.hCursor = LoadCursorA(0, IDC_ARROW);
    
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    
    WindowClass.lpszClassName = "MainWindowClass";
    
    WindowClass.hIconSm = LoadIconA(0, IDI_APPLICATION);
    
    RegisterClassExA(&WindowClass);
    
    g_WindowHandle = CreateWindowExA(0, WindowClass.lpszClassName, 0, WS_VISIBLE | WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, g_WindowWidth, g_WindowHeight, 0, 0, Instance, 0);
 
    UpdateWindow(g_WindowHandle);
 
    MSG Message = {0};
 
    while(GetMessage(&Message, 0, 0, 0) > 0) {
        
        TranslateMessage(&Message);
        
        DispatchMessage(&Message);
    
    }
 
    return 0;

}
 
LRESULT CALLBACK WindowProc(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam) {
    
    switch(Message) {

        LRESULT Result;

        case WM_CLOSE: {
            
            DestroyWindow(WindowHandle);

            Result = 0;
            
            break;

        }
 
        case WM_DESTROY: {
            
            PostQuitMessage(0);

            Result = 0;
            
            break;
        
        }

        case WM_PAINT: {

            PAINTSTRUCT PS;

            BeginPaint(g_WindowHandle, &PS);

            DisplayText(g_WindowHandle, "K");

            EndPaint(g_WindowHandle, &PS);

            Result = 0;
        
        }

        default: {
            
            Result = DefWindowProcA(WindowHandle, Message, WParam, LParam);
        
        }

        return Result;

    }

}

void DisplayText(HWND WindowHandle, char* Text) {

    HDC DC = GetDC(WindowHandle);
    
    RECT TextRect;
    
    GetClientRect(WindowHandle, &TextRect);
    
    DrawTextA(DC, Text, -1, &TextRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    ReleaseDC(WindowHandle, DC);

}