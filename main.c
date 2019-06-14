#include "windowprocs.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int iCmdShow) {

    WNDCLASS wndc;

    /* setup the window class */
    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInst;
    wndc.lpfnWndProc = appWndProc;
    wndc.lpszMenuName = NULL;
    wndc.lpszClassName = APP_NAME;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    /* register window class */
    if(!RegisterClass(&wndc)) {
        printf("Window class registration failed: %s\n", APP_NAME);
    }
    else {
        HWND hwnd;
        MSG msg;

        /* create window */
        hwnd = CreateWindow(APP_NAME, "Electric Distributor Layout - EDL", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, hInst, NULL);
        UpdateWindow(hwnd);
        ShowWindow(hwnd, iCmdShow);

        while(GetMessage(&msg, NULL, 0, 0) != 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}
