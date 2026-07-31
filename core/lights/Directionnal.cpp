/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Directionnal
*/

#include "Directionnal.hpp"

namespace raytracer
{
    Directionnal::Directionnal(const Vector3D &direction, const Color &color, const double &intensity) : direction(direction), color(color), intensity(intensity)
    {
    }

    bool Directionnal::is_directional() const
    {
        return true;
    }

    Vector3D Directionnal::get_direction() const
    {
        return direction;
    }

    Point3D Directionnal::get_position() const
    {
        return Point3D(0, 0, 0);
    }

    Color Directionnal::get_color() const
    {
        return color;
    }

    double Directionnal::get_intensity(const Point3D &intersection_point) const
    {
        (void)intersection_point;
        return intensity;
    }
}
