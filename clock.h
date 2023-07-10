/**
 * \file
 * \brief Инициализация класса Clock
 */


#ifndef CLOCK_H
#define CLOCK_H 1


#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <chrono>
#include <stdexcept>
#include <cmath>


/**
 * \brief Класс, реализующий отрисовку аналаговых часов
 */
class Clock {
public:
  /**
   * \brief Конструктор класса Clock по координатам центра и радусу
   * \param x x-координата центра циферблата (начальная точка СК в центре окна) в пикселях
   * \param y y-координата центра циферблата (начальная точка СК в центре окна) в пикселях
   * \param r Радиус циферблата в пикселях
   * \throw std::runtime_error Если r отрицателен
   */
  Clock (int x, int y, int r);

  /**
   * \brief Конструктор копирования класса Clock
   * \param c Экземпляр класса Clock для копирования
   */
  Clock (const Clock& c);

  /**
   * \brief Отрисовка аналаговых часов библиотекой OpenGL
   * \param window_width Ширина окна приложения
   * \param window_height Высота окна приложения
   * \throw std::runtime_error Если window_width или window_height отрицательны
   */
  void draw (int window_width, int window_height);

  /**
   * \brief Получение радиуса аналаговых часов
   * \return Радиус аналаговых часов
   */
  int radius () const;

  /**
   * \brief Получение x-координаты центра аналаговых часов
   * \return x-координата центра аналаговых часов
   */
  int x0 () const;

  /**
   * \brief Получение y-координаты центра аналаговых часов
   * \return y-координата центра аналаговых часов
   */
  int y0 () const;

  /**
   * \brief Установка нового значения x-координаты центра аналаговых часов
   * \param x0 Новая x-координата центра аналаговых часов
   */
  void set_x0 (int x0);

  /**
   * \brief Установка нового значения y-координаты центра аналаговых часов
   * \param y0 Новая y-координата центра аналаговых часов
   */
  void set_y0 (int y0);

  /**
   * \brief Установка нового значения радиуса аналаговых часов
   * \param radius Новый радиус аналаговых часов
   * \throw std::runtime_error Если radius отрицателен
   */
  void set_radius (int radius);

private:
  int x0_;
  int y0_;
  int radius_;
};


#endif // CLOCK_H
