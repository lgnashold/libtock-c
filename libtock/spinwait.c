#include <spinwait.h>
#include <stdio.h>
static void timer_cb( __attribute__ ((unused)) int now,
                     __attribute__ ((unused)) int expiration,
                     __attribute__ ((unused)) int unused, void* ud) {
    *((bool*)ud) = true;
}

void spin_ms(int ms) {
        printf("Started spinning\n");
        tock_timer_t timer;
        bool done = false;
        volatile int i = 0;
        timer_every(ms, timer_cb, &done, &timer);
        while (!done) {
            i++;
        }
        printf("Stopped spinning\n");
}


