/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Color
*/

#include "Color.hpp"

namespace raytracer
{
    Color::Color()
    {
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }

    Color::Color(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    uint8_t Color::get_r() const
    {
        return r;
    }

    uint8_t Color::get_g() const
    {
        return g;
    }

    uint8_t Color::get_b() const
    {
        return b;
    }

    uint8_t Color::get_a() const
    {
        return a;
    }

    void Color::set_r(const uint8_t &r)
    {
        this->r = r;
    }

    void Color::set_g(const uint8_t &g)
    {
        this->g = g;
    }

    void Color::set_b(const uint8_t &b)
    {
        this->b = b;
    }

    void Color::set_a(const uint8_t &a)
    {
        this->a = a;
    }

    void Color::set_rgba(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    Color Color::operator+(const Color &color) const
    {
        Color new_color;
        new_color.r = std::min(255, (int)r + (int)color.r);
        new_color.g = std::min(255, (int)g + (int)color.g);
        new_color.b = std::min(255, (int)b + (int)color.b);
        new_color.a = std::min(255, (int)a + (int)color.a);
        return new_color;
    }

    Color Color::operator-(const Color &color) const
    {
        Color new_color;
        new_color.r = std::max(0, (int)r - (int)color.r);
        new_color.g = std::max(0, (int)g - (int)color.g);
        new_color.b = std::max(0, (int)b - (int)color.b);
        new_color.a = std::max(0, (int)a - (int)color.a);
        return new_color;
    }

    Color Color::operator*(const Color &color) const
    {
        Color new_color;
        new_color.r = std::min(255, (int)r * (int)color.r);
        new_color.g = std::min(255, (int)g * (int)color.g);
        new_color.b = std::min(255, (int)b * (int)color.b);
        new_color.a = std::min(255, (int)a * (int)color.a);
        return new_color;
    }

    Color Color::operator*(const float &value) const
    {
        Color new_color;
        new_color.r = std::min(255.F, (int)r * value);
        new_color.g = std::min(255.F, (int)g * value);
        new_color.b = std::min(255.F, (int)b * value);
        new_color.a = std::min(255.F, (int)a * value);
        return new_color;
    }

    Color Color::operator/(const Color &color) const
    {
        return Color(r / color.r, g / color.g, b / color.b, a / color.a);
    }

    Color Color::operator/(const float &value) const
    {
        return Color(r / value, g / value, b / value, a / value);
    }

    Color Color::operator+=(const Color &color)
    {
        r = std::min(255, (int)r + (int)color.r);
        g = std::min(255, (int)g + (int)color.g);
        b = std::min(255, (int)b + (int)color.b);
        a = std::min(255, (int)a + (int)color.a);
        return *this;
    }

    Color Color::operator-=(const Color &color)
    {
        r = std::max(0, (int)r - (int)color.r);
        g = std::max(0, (int)g - (int)color.g);
        b = std::max(0, (int)b - (int)color.b);
        a = std::max(0, (int)a - (int)color.a);
        return *this;
    }

    Color Color::operator*=(const Color &color)
    {
        r *= color.r;
        g *= color.g;
        b *= color.b;
        a *= color.a;
        return *this;
    }

    Color Color::operator*=(const float &value)
    {
        r *= value;
        g *= value;
        b *= value;
        a *= value;
        return *this;
    }

    Color Color::operator/=(const Color &color)
    {
        r /= color.r;
        g /= color.g;
        b /= color.b;
        a /= color.a;
        return *this;
    }

    Color Color::operator/=(const float &value)
    {
        r /= value;
        g /= value;
        b /= value;
        a /= value;
        return *this;
    }
}
