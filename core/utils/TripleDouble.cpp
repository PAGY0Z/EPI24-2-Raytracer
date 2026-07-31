/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** TripleDouble
*/

#include "TripleDouble.hpp"

namespace raytracer
{
    TripleDouble::TripleDouble(const double &x, const double &y, const double &z) : x(x), y(y), z(z)
    {
    }

    double TripleDouble::get_x() const
    {
        return x;
    }

    double TripleDouble::get_y() const
    {
        return y;
    }

    double TripleDouble::get_z() const
    {
        return z;
    }

    void TripleDouble::set_x(const double &x)
    {
        this->x = x;
    }

    void TripleDouble::set_y(const double &y)
    {
        this->y = y;
    }

    void TripleDouble::set_z(const double &z)
    {
        this->z = z;
    }

    TripleDouble TripleDouble::operator+(const TripleDouble &triple_double) const
    {
        return TripleDouble(x + triple_double.x, y + triple_double.y, z + triple_double.z);
    }

    TripleDouble TripleDouble::operator+=(const TripleDouble &triple_double)
    {
        x += triple_double.x;
        y += triple_double.y;
        z += triple_double.z;
        return *this;
    }

    TripleDouble TripleDouble::operator*(const double &value) const
    {
        return TripleDouble(x * value, y * value, z * value);
    }
}
