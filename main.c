#include <windows.h>
 
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

int g_WindowWidth = 150;

int g_WindowHeight = 150;

HWND g_WindowHandle;
 
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
    
    g_WindowHandle = CreateWindowExA(WS_EX_CLIENTEDGE | WS_EX_COMPOSITED, WindowClass.lpszClassName, "Pressed Key Displayer (PKDisplayer)", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, g_WindowWidth, g_WindowHeight, 0, 0, Instance, 0);
 
    NONCLIENTMETRICSA NonClientMetrics;

    NonClientMetrics.cbSize = sizeof(NonClientMetrics);
    
    SystemParametersInfoA(SPI_GETNONCLIENTMETRICS, sizeof(NonClientMetrics), &NonClientMetrics, 0);
 
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

        case WM_CLOSE: {
            
            DestroyWindow(WindowHandle);
            
            break;

        }
 
        case WM_DESTROY: {
            
            PostQuitMessage(0);
            
            break;
        
        }

        default: {
            
            return DefWindowProcA(WindowHandle, Message, WParam, LParam);
        
        }

    }

}