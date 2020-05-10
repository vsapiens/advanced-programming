#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HHOOK MouseHook;
volatile int checkForClick, success;
volatile POINT p;

int main(int argc, char *argv[])
{
    char c;
    HINSTANCE hInstance;
    POINT p11, p12, p1n, p21, p2n;

    //Hook on mouse
    hInstance = GetModuleHandle(0);
    MouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, hInstance, 0);
    if (!MouseHook)
    {
        printf("FAILED TO INSTALL MOUSE HOOK!");
        goto kraj;
    }
    printf("Please click: ");
    if (!CollectPoint())
        goto kraj;
    p11 = p;
    printf("(%d, %d)\n", p.x, p.y);

kraj:
    UnhookWindowsHookEx(MouseHook);
    printf("DEBUG: Unhooked...");
    system("PAUSE");
    return 0;
}

int CollectPoint()
{
    MSG message;

    success = 0;
    checkForClick = 1;
    printf("DEBUG: Waiting...\n");
    while (checkForClick)
    {
        printf("DEBUG: LOOP\n");
        if (GetMessage(&message, NULL, 0, 0))
        {
            printf("DEBUG: MSG1\n");
            TranslateMessage(&message);
            printf("DEBUG: MSG2\n");
            DispatchMessage(&message);
            printf("DEBUG: MSG3\n");
        }
        //       Sleep(500);
    }
    printf("DEBUG: END\n");
    return success;
}

LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    printf("DEBUG: MHOOKFUNC\n");
    if (!checkForClick)
        goto kraj;
    printf("DEBUG: MHOOKFUNC2 nCode: %d wParam: %d\n", nCode, wParam);
    if (wParam == WM_LBUTTONDOWN)
    {
        printf("DEBUG: MHOOKFUNC3\n");
        success = GetCursorPos(&p);
        checkForClick = 0;
    }
kraj:
    if (nCode < 0)
        return CallNextHookEx(NULL, nCode, wParam, lParam);
}