/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <cstdint>
#include <algorithm>

namespace raytracer
{
    class Color
    {
    public:
        Color();
        Color(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a);
        ~Color() = default;

        uint8_t get_r() const;
        uint8_t get_g() const;
        uint8_t get_b() const;
        uint8_t get_a() const;

        void set_r(const uint8_t &r);
        void set_g(const uint8_t &g);
        void set_b(const uint8_t &b);
        void set_a(const uint8_t &a);
        void set_rgba(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a);

        Color operator+(const Color &color) const;
        Color operator-(const Color &color) const;
        Color operator*(const Color &color) const;
        Color operator*(const float &value) const;
        Color operator/(const Color &color) const;
        Color operator/(const float &value) const;
        Color operator+=(const Color &color);
        Color operator-=(const Color &color);
        Color operator*=(const Color &color);
        Color operator*=(const float &value);
        Color operator/=(const Color &color);
        Color operator/=(const float &value);

    private:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
}

#endif /* !COLOR_HPP_ */
