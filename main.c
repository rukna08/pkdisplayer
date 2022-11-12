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
                    
                    g_Text = "LEFT";

                    break;

                }

                case VK_RIGHT: {
                    
                    g_Text = "RIGHT";

                    break;

                }

                case VK_UP: {
                    
                    g_Text = "UP";

                    break;

                }

                case VK_DOWN: {
                    
                    g_Text = "DOWN";

                    break;

                }

                case VK_BACK: {
                    
                    g_Text = "BACKSPACE";

                    break;

                }

                case VK_TAB: {
                    
                    g_Text = "TAB";

                    break;

                }

                case VK_RETURN: {
                    
                    g_Text = "ENTER";

                    break;

                }

                case VK_SHIFT: {
                    
                    g_Text = "SHIFT";

                    break;

                }

                case VK_CONTROL: {
                    
                    g_Text = "CTRL";

                    break;

                }

                case VK_MENU: {
                    
                    g_Text = "ALT";

                    break;

                }

                case VK_CAPITAL: {
                    
                    g_Text = "CAPSLOCK";

                    break;

                }

                case VK_SPACE: {
                    
                    g_Text = "SPACEBAR";

                    break;

                }

                case VK_PRIOR: {
                    
                    g_Text = "PAGE UP";

                    break;

                }

                case VK_NEXT: {
                    
                    g_Text = "PAGE DOWN";

                    break;

                }

                case VK_END: {
                    
                    g_Text = "END";

                    break;

                }

                case VK_HOME: {
                    
                    g_Text = "HOME";

                    break;

                }

                case VK_SNAPSHOT: {
                    
                    g_Text = "PRINT SCREEN";

                    break;

                }

                case VK_INSERT: {
                    
                    g_Text = "INSERT";

                    break;

                }

                case 0x30: {
                    
                    g_Text = "0";

                    break;

                }

                case 0x31: {
                    
                    g_Text = "1";

                    break;

                }

                case 0x32: {
                    
                    g_Text = "2";

                    break;

                }

                case 0x33: {
                    
                    g_Text = "3";

                    break;

                }

                case 0x34: {
                    
                    g_Text = "4";

                    break;

                }

                case 0x35: {
                    
                    g_Text = "5";

                    break;

                }

                case 0x36: {
                    
                    g_Text = "6";

                    break;

                }

                case 0x37: {
                    
                    g_Text = "7";

                    break;

                }

                case 0x38: {
                    
                    g_Text = "8";

                    break;

                }

                case 0x39: {
                    
                    g_Text = "9";

                    break;

                }

                case 0x41: {
                    
                    g_Text = "A";

                    break;

                }
                
                case 0x42: {
                    
                    g_Text = "B";

                    break;

                }

                case 0x43: {
                    
                    g_Text = "C";

                    break;

                }

                case 0x44: {
                    
                    g_Text = "D";

                    break;

                }

                case 0x45: {
                    
                    g_Text = "E";

                    break;

                }

                case 0x46: {
                    
                    g_Text = "F";

                    break;

                }

                case 0x47: {
                    
                    g_Text = "G";

                    break;

                }

                case 0x48: {
                    
                    g_Text = "H";

                    break;

                }

                case 0x49: {
                    
                    g_Text = "I";

                    break;

                }

                case 0x4A: {
                    
                    g_Text = "J";

                    break;

                }

                case 0x4B: {
                    
                    g_Text = "K";

                    break;

                }

                case 0x4C: {
                    
                    g_Text = "L";

                    break;

                }

                case 0x4D: {
                    
                    g_Text = "M";

                    break;

                }

                case 0x4E: {
                    
                    g_Text = "N";

                    break;

                }

                case 0x4F: {
                    
                    g_Text = "O";

                    break;

                }

                case 0x50: {
                    
                    g_Text = "P";

                    break;

                }

                case 0x51: {
                    
                    g_Text = "Q";

                    break;

                }

                case 0x52: {
                    
                    g_Text = "R";

                    break;

                }

                case 0x53: {
                    
                    g_Text = "S";

                    break;

                }

                case 0x54: {
                    
                    g_Text = "T";

                    break;

                }

                case 0x55: {
                    
                    g_Text = "U";

                    break;

                }

                case 0x56: {
                    
                    g_Text = "V";

                    break;

                }

                case 0x57: {
                    
                    g_Text = "W";

                    break;

                }

                case 0x58: {
                    
                    g_Text = "X";

                    break;

                }

                case 0x59: {
                    
                    g_Text = "Y";

                    break;

                }

                case 0x5A: {
                    
                    g_Text = "Z";

                    break;

                }

                case VK_NUMLOCK: {
                    
                    g_Text = "NUMLOCK";

                    break;

                }

                case VK_NUMPAD0: {
                    
                    g_Text = "NUM 0";

                    break;

                }

                case VK_NUMPAD1: {
                    
                    g_Text = "NUM 1";

                    break;

                }

                case VK_NUMPAD2: {
                    
                    g_Text = "NUM 2";

                    break;

                }

                case VK_NUMPAD3: {
                    
                    g_Text = "NUM 3";

                    break;

                }

                case VK_NUMPAD4: {
                    
                    g_Text = "NUM 4";

                    break;

                }

                case VK_NUMPAD5: {
                    
                    g_Text = "NUM 5";

                    break;

                }

                case VK_NUMPAD6: {
                    
                    g_Text = "NUM 6";

                    break;

                }

                case VK_NUMPAD7: {
                    
                    g_Text = "NUM 7";

                    break;

                }

                case VK_NUMPAD8: {
                    
                    g_Text = "NUM 8";

                    break;

                }

                case VK_NUMPAD9: {
                    
                    g_Text = "NUM 9";

                    break;

                }

                case VK_ADD: {
                    
                    g_Text = "+";

                    break;

                }

                case VK_SUBTRACT: {
                    
                    g_Text = "-";

                    break;

                }

                case VK_MULTIPLY: {
                    
                    g_Text = "*";

                    break;

                }

                case VK_DIVIDE: {
                    
                    g_Text = "/";

                    break;

                }

                case VK_F1: {
                    
                    g_Text = "F1";

                    break;

                }

                case VK_F2: {
                    
                    g_Text = "F2";

                    break;

                }

                case VK_F3: {
                    
                    g_Text = "F3";

                    break;

                }

                case VK_F4: {
                    
                    g_Text = "F4";

                    break;

                }

                case VK_F5: {
                    
                    g_Text = "F5";

                    break;

                }

                case VK_F6: {
                    
                    g_Text = "F6";

                    break;

                }

                case VK_F7: {
                    
                    g_Text = "F7";

                    break;

                }

                case VK_F8: {
                    
                    g_Text = "F8";

                    break;

                }

                case VK_F9: {
                    
                    g_Text = "F9";

                    break;

                }

                case VK_F10: {
                    
                    g_Text = "F10";

                    break;

                }

                case VK_F11: {
                    
                    g_Text = "F11";

                    break;

                }

                case VK_F12: {
                    
                    g_Text = "F12";

                    break;

                }
                
                case VK_SCROLL: {
                    
                    g_Text = "SCROLL";

                    break;

                }

                // Escape is set to quit the application temporarily.

                case VK_ESCAPE: {
                    
                    SendMessageA(WindowHandle, WM_CLOSE, WParam, LParam);

                    break;

                }

            }

            InvalidateRect(WindowHandle, 0, TRUE);
            
            SendMessageA(WindowHandle, WM_PAINT, WParam, LParam);

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

    UpdateWindow(WindowHandle);

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