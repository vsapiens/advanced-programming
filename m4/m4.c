#include <stdio.h>
#include <X11/Xlib.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *out;
    Display *display;
    XEvent xevent;
    Window window;
    int i = 0;
    out = fopen("output.txt", "w+");
    if ((display = XOpenDisplay(NULL)) == NULL)
        return -1;

    window = DefaultRootWindow(display);
    XAllowEvents(display, AsyncBoth, CurrentTime);

    XGrabPointer(display,
                 window,
                 1,
                 PointerMotionMask | ButtonPressMask | ButtonReleaseMask,
                 GrabModeAsync,
                 GrabModeAsync,
                 None,
                 None,
                 CurrentTime);

    while (i < 10)
    {
        XNextEvent(display, &xevent);
        switch (xevent.type)
        {
        case ButtonPress:
            fprintf(out, "[x: %d,y: %d]\n", xevent.xmotion.x_root, xevent.xmotion.y_root);
            i++;
            break;
        }
    }
    fclose(out);
    return 0;
}
