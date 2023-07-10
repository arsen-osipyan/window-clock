#include "clock_app.h"
#include "clock.h"


int main (int argc, char **argv) {
  ClockApp clock_app = ClockApp(1200, 800);

  clock_app.add_clock(Clock(-400, +200, 150));
  clock_app.add_clock(Clock(  +0, +200, 150));
  clock_app.add_clock(Clock(+400, +200, 150));
  clock_app.add_clock(Clock(-400, -200, 150));
  clock_app.add_clock(Clock(  +0, -200, 150));
  clock_app.add_clock(Clock(+400, -200, 150));

  clock_app.run();

  return 0;
}
