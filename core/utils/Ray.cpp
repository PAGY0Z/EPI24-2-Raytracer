/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Ray
*/

#include "Ray.hpp"

namespace raytracer
{
    Ray::Ray()
    {
        origin = Point3D();
        direction = Vector3D();
    }

    Ray::Ray(const Point3D &origin, const Vector3D &direction)
    {
        this->origin = origin;
        this->direction = direction;
    }

    Point3D Ray::get_origin() const
    {
        return origin;
    }

    Vector3D Ray::get_direction() const
    {
        return direction;
    }

    void Ray::set_origin(const Point3D &origin)
    {
        this->origin = origin;
    }

    void Ray::set_direction(const Vector3D &direction)
    {
        this->direction = direction;
    }
}
