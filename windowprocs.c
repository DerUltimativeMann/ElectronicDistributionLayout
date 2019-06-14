#include "windowprocs.h"

LRESULT CALLBACK appWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

    switch(msg) {
        case WM_CREATE:
        MoveWindow(hwnd, 50, 50, 640, 480, TRUE);
        return 0;

        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wp, lp);
}
