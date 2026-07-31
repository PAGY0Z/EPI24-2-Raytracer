/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"

namespace raytracer
{
    class Point3D
    {
    public:
        Point3D();
        Point3D(const double &x, const double &y, const double &z);
        ~Point3D() = default;

        double get_x() const;
        double get_y() const;
        double get_z() const;

        void set_x(const double &x);
        void set_y(const double &y);
        void set_z(const double &z);

        double get_distance(const Point3D &other) const;

        Vector3D operator-(const Point3D &other);
        Point3D operator+(const Vector3D &other);

    private:
        double x;
        double y;
        double z;
    };
}

#endif /* !POINT3D_HPP_ */
