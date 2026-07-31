/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace raytracer
{
    Point3D::Point3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Point3D::Point3D(const double &x, const double &y, const double &z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double Point3D::get_x() const
    {
        return x;
    }

    double Point3D::get_y() const
    {
        return y;
    }

    double Point3D::get_z() const
    {
        return z;
    }

    void Point3D::set_x(const double &x)
    {
        this->x = x;
    }

    void Point3D::set_y(const double &y)
    {
        this->y = y;
    }

    void Point3D::set_z(const double &z)
    {
        this->z = z;
    }

    double Point3D::get_distance(const Point3D &other) const
    {
        return sqrt(pow(x - other.get_x(), 2) + pow(y - other.get_y(), 2) + pow(z - other.get_z(), 2));
    }

    Vector3D Point3D::operator-(const Point3D &other)
    {
        return Vector3D(x - other.get_x(), y - other.get_y(), z - other.get_z());
    }

    Point3D Point3D::operator+(const Vector3D &other)
    {
        return Point3D(x + other.get_x(), y + other.get_y(), z + other.get_z());
    }
}
