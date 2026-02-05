#include <stdio.h>
#include <stdlib.h>     
#include <unistd.h>
#include <time.h>        
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>

int main() {
    struct libevdev *dev = libevdev_new();
    struct libevdev_uinput *uidev = NULL;

    // setting hardware
    libevdev_set_name(dev, "logitech fake moused");


    // relative axes
    libevdev_enable_event_type(dev, EV_REL);
    libevdev_enable_event_code(dev, EV_REL, REL_X, NULL);
    libevdev_enable_event_code(dev, EV_REL, REL_Y, NULL);

    libevdev_enable_event_type(dev, EV_KEY);
    libevdev_enable_event_code(dev, EV_KEY, BTN_LEFT, NULL);
    
    libevdev_enable_event_type(dev, EV_SYN);

    // create uinput device
    int code = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);

    if (code != 0) {
        perror("Error creating uinput device (Check /dev/uinput permissions or use sudo)");
        libevdev_free(dev);
        return -1;
    }

    srand(time(NULL));

    while (1) {
        // random move distance -10 to 10
        int dx = (rand() % 21) - 10;
        int dy = (rand() % 21) - 10;

        printf("Moving by: X=%d, Y=%d\n", dx, dy);

        // write X displacement
        libevdev_uinput_write_event(uidev, EV_REL, REL_X, dx);
        // write Y displacement
        libevdev_uinput_write_event(uidev, EV_REL, REL_Y, dy);
        // send sync signal
        libevdev_uinput_write_event(uidev, EV_SYN, SYN_REPORT, 0);

        // move once per second, don't move too fast
        usleep(5000);
    }


    return 0;
}