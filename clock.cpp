/**
 * \file
 * \brief Реализация методов класса Clock
 */


#include "clock.h"


Clock::Clock (int x, int y, int r)
  : x0_{ x }, y0_{ y }, radius_{ r } {
  if (r < 0) {
    throw std::runtime_error{"clock radius must be non-negative integer"};
  }
}

Clock::Clock (const Clock& c)
  : x0_{ c.x0() }, y0_{ c.y0() }, radius_{ c.radius() } { }


int Clock::radius () const { return this->radius_; }
int Clock::x0 () const { return this->x0_; }
int Clock::y0 () const { return this->y0_; }

void Clock::set_x0 (int x0) { this->x0_ = x0; }
void Clock::set_y0 (int y0) { this->y0_ = y0; }
void Clock::set_radius (int radius) {
  if (radius < 0) {
    throw std::runtime_error{"clock radius must be non-negative integer"};
  }
  this->radius_ = radius;
}

void Clock::draw (int window_width, int window_height) {
  if (window_width < 0 || window_height < 0) {
    throw std::runtime_error{"window width and height must be non-negative integer"};
  }

  // Pixels to fraction
  float x0 = 2.0 * this->x0_ / window_width;
  float y0 = 2.0 * this->y0_ / window_height;
  float rx = 2.0 * this->radius_ / window_width;
  float ry = 2.0 * this->radius_ / window_height;

  // Setting line color
  glColor3f(0.0f, 0.0f, 0.0f);

  // Setting line width for circle and ticks
  glLineWidth(2);

  // Drawing circle
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i += 5) {
      float angle = i * 2.0 * M_PI / 360;
      float x = rx * cos(angle);
      float y = ry * sin(angle);
      glVertex2f(x + x0, y + y0);
  }
  glEnd();

  // Drawing ticks
  glBegin(GL_LINES);

  int large_ticks_number = 12;
  int small_ticks_number = 60;

  float angle, x, y;

  for (int i = 0; i < large_ticks_number; ++i) {
    angle = i * 2.0 * M_PI / large_ticks_number;
    x = rx * cos(angle);
    y = ry * sin(angle);
    glVertex2f(x + x0, y + y0);
    x = 0.92 * rx * cos(angle);
    y = 0.92 * ry * sin(angle);
    glVertex2f(x + x0, y + y0);
  }

  for (int i = 0; i < small_ticks_number; ++i) {
    if (i % (small_ticks_number / large_ticks_number) == 0) continue;
    angle = i * 2.0 * M_PI / small_ticks_number;
    x = rx * cos(angle);
    y = ry * sin(angle);
    glVertex2f(x + x0, y + y0);
    x = 0.96 * rx * cos(angle);
    y = 0.96 * ry * sin(angle);
    glVertex2f(x + x0, y + y0);
  }

  glEnd();

  // Getting current time
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  struct tm* local_time = localtime(&time);

  // Calculation angles
  float second_angle = (local_time->tm_sec / 60.0) * 2.0 * M_PI;
  float minute_angle = (local_time->tm_min / 60.0) * 2.0 * M_PI;
  float hour_angle = ((local_time->tm_hour % 12) / 12.0) * 2.0 * M_PI;

  // Setting line width for arrows
  glLineWidth(3);

  // Drawing arrows
  glBegin(GL_LINES);

  float second_arrow_x = 0.9 * rx * sin(second_angle);
  float second_arrow_y = 0.9 * ry * cos(second_angle);
  glVertex2f(x0, y0);
  glVertex2f(second_arrow_x + x0, second_arrow_y + y0);

  float minute_arrow_x = 0.75 * rx * sin(minute_angle);
  float minute_arrow_y = 0.75 * ry * cos(minute_angle);
  glVertex2f(x0, y0);
  glVertex2f(minute_arrow_x + x0, minute_arrow_y + y0);

  float hour_arrow_x = 0.6 * rx * sin(hour_angle);
  float hour_arrow_y = 0.6 * ry * cos(hour_angle);
  glVertex2f(x0, y0);
  glVertex2f(hour_arrow_x + x0, hour_arrow_y + y0);

  glEnd();
}
