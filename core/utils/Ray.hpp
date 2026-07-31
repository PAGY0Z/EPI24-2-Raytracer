/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace raytracer
{
    class Ray
    {
    public:
        Ray();
        Ray(const Point3D &origin, const Vector3D &direction);
        ~Ray() = default;

        Point3D get_origin() const;
        Vector3D get_direction() const;

        void set_origin(const Point3D &origin);
        void set_direction(const Vector3D &direction);

    private:
        Point3D origin;
        Vector3D direction;
    };
}

#endif /* !RAY_HPP_ */
