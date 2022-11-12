#include <windows.h>

#include "main.h"

int WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance, LPSTR CommandLine, int CommandShow) {

    SetWindowClass(g_WindowClass, Instance);
    
    g_WindowHandle = CreateWindowA(g_WindowClass.lpszClassName, 0, WS_VISIBLE | WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, g_WindowWidth, g_WindowHeight, 0, 0, Instance, 0);

    MoveWindow(g_WindowHandle, (GetSystemMetrics(SM_CXSCREEN) / 2) - (g_WindowWidth / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (g_WindowHeight / 2), g_WindowWidth, g_WindowHeight, FALSE);

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

            DisplayText(g_WindowHandle, g_Text);

            EndPaint(g_WindowHandle, &PS);

            Result = 0;

            break;
        
        }

        case WM_KEYDOWN: {

            switch (WParam) {
                
                case VK_LEFT: {
                    
                    g_Text = "Left";

                    SendMessageA(WindowHandle, WM_PAINT, WParam, LParam);

                    break;

                }

            }

            Result = 0;

            break;

        }

        default: {
            
            Result = DefWindowProcA(WindowHandle, Message, WParam, LParam);

            break;
        
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

void SetWindowClass(WNDCLASSA WindowClass, HINSTANCE Instance) {
 
    g_WindowClass.lpfnWndProc = WindowProc;
    
    g_WindowClass.hInstance = Instance;
        
    g_WindowClass.hCursor = LoadCursorA(0, IDC_ARROW);
    
    g_WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    
    g_WindowClass.lpszClassName = "MainWindowClass";
        
    RegisterClassA(&g_WindowClass);

}