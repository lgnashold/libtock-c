#include <led.h>
#include <timer.h>
#include <stdio.h>
#include <spinwait.h>
static bool met_deadline = false;

static void timer_cb( int now,
                     __attribute__ ((unused)) int expiration,
                     __attribute__ ((unused)) int unused, void* ud) {
  //printf("Timer callback! Time: %d\n", now);
  if (!met_deadline) {
      printf("Prog 2 Missed Deadline :(\n");
  } else {
      printf("Prog 2 Met Deadline :)\n");
  }
  *((bool*)ud) = true;
}

int main(void) {
  while(1) {
    met_deadline = false;
    bool done = false;
    tock_timer_t timer;

    // 1s deadline
    deadline(1000);

    printf("Hi\n");

    // 1s timer
    timer_in(1000, timer_cb, &done, &timer);

    // 500 ms deadline. Repeat every 500ms
    led_on(0);
    
    // simulates 400ms of work
    spin_ms(400); 

    led_off(0);
    // hit deadline
    met_deadline = true;

    // yield until timer is done
    yield_for_with_timeout(&done, 1000);
  }
}
