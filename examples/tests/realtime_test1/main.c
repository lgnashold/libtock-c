#include <timer.h>
#include <stdio.h>
#include <spinwait.h>


int main(void) {
    while(1) {
        int start = alarm_read();
        printf("read alarm\n");
        volatile int dontoptimize = 0;
        int num_loops = 10000000;
        for (int i =0; i < num_loops; i++) {
            dontoptimize++;
            if (i % 100000 == 0) {
                printf("in loop\n");
            }
        }

        printf("out of loop\n");
        int end = alarm_read();
        printf("Start: %d, Time: %d\n", start, end - start);

        printf("num loops: %d\n", num_loops);
        delay_ms(15);
    } 
    return 0;
}

