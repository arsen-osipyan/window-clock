/**
 * \file
 * \brief Реализация методов класса ClockApp
 */


#include "clock_app.h"


ClockApp::ClockApp (int w, int h)
  : width_{ w }, height_{ h }, clocks_{ } {
  if (w < 0 || h < 0) {
    throw std::runtime_error{"window width and height must be non-negative integer"};
  }
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw std::runtime_error{"SDL_Init() failed"};
  }

  this->window_ = SDL_CreateWindow("Clock App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_OPENGL);
  this->context_ = SDL_GL_CreateContext(this->window_);
}

ClockApp::~ClockApp () {
  SDL_GL_DeleteContext(this->context_);
  SDL_DestroyWindow(this->window_);
  SDL_Quit();
}


int ClockApp::height () const { return this->height_; }
int ClockApp::width () const { return this->width_; }

void ClockApp::add_clock (const Clock& c) { this->clocks_.push_back(c); }

void ClockApp::run () {
  bool quit = false;
  while (!quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
    this->draw();
    SDL_GL_SwapWindow(this->window_);
  }
}

void ClockApp::draw () {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < this->clocks_.size(); ++i) {
    this->clocks_[i].draw(this->width_, this->height_);
  }
}
