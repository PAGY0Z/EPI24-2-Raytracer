/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Point
*/

#include "Point.hpp"

namespace raytracer
{
    Point::Point(const Point3D &position, const Color &color, const double &intensity) : position(position), color(color), intensity(intensity)
    {
    }

    bool Point::is_directional() const
    {
        return false;
    }

    Vector3D Point::get_direction() const
    {
        return Vector3D(0, 0, 0);
    }

    Point3D Point::get_position() const
    {
        return position;
    }

    Color Point::get_color() const
    {
        return color;
    }

    double Point::get_intensity(const Point3D &intersection_point) const
    {
        (void)intersection_point;
        return intensity;
    }
}
