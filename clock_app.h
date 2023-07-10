/**
 * \file
 * \brief Инициализация класса ClockApp
 */


#ifndef CLOCK_APP_H
#define CLOCK_APP_H 1


#include "clock.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <vector>
#include <stdexcept>


class ClockApp {
public:
  /**
   * \brief Конструктор класса ClockApp
   * \param w Ширина окна приложения
   * \param h Высота окна приложения
   * \throw std::runtime_error Если w или h отрицательны
   * \throw std::runtime_error Если не удалось инициализировать SDL
   */
  ClockApp (int w, int h);


  /**
   * \brief Добавляет аналаговые часы в окно приложения
   * \param c Экземпляр класса Clock для добавления
   */
  void add_clock (const Clock& c);

  /**
   * \brief Отрисовывает приложение и все добавленные аналаговые часы
   */
  void draw ();

  /**
   * \brief Запускает приложение и его отрисовку
   */
  void run ();

  /**
   * \brief Получение высоты окна приложения
   * \return Высота окна приложения
   */
  int height () const;

  /**
   * \brief Получение ширины окна приложения
   * \return Ширина окна приложения
   */
  int width () const;


  /**
   * \brief Деструктор, закрывающий приложение и очищающий память
   */
  ~ClockApp ();

private:
  std::vector<Clock> clocks_;
  int height_;
  int width_;

  SDL_Window* window_;
  SDL_GLContext context_;
};


#endif // CLOCK_APP_H
