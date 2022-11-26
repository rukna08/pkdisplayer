#pragma once

LRESULT CALLBACK WindowProc(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam);

void DisplayText(HWND WindowHandle, char* Text);

void SetWindowClass(WNDCLASSA WindowClass, HINSTANCE Instance);

void ProcessMessage();

LRESULT CALLBACK KBDHook(int NCode, WPARAM WParam, LPARAM LParam);

int g_WindowWidth = 150;

int g_WindowHeight = 150;

HWND g_WindowHandle;

WNDCLASSA g_WindowClass = {0};

char* g_Text = "NULL";

UINT_PTR IDT_TIMER;

int g_WindowWaitTime = 1;

HHOOK g_KeyboardHookHandle;

LPARAM g_LParam;