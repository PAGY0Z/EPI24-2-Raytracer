/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace raytracer
{
    Vector3D::Vector3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3D::Vector3D(const double &x, const double &y, const double &z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double Vector3D::get_x() const
    {
        return x;
    }

    double Vector3D::get_y() const
    {
        return y;
    }

    double Vector3D::get_z() const
    {
        return z;
    }

    void Vector3D::set_x(const double &x)
    {
        this->x = x;
    }

    void Vector3D::set_y(const double &y)
    {
        this->y = y;
    }

    void Vector3D::set_z(const double &z)
    {
        this->z = z;
    }

    void Vector3D::normalize()
    {
        double length = sqrt(x * x + y * y + z * z);
        x /= length;
        y /= length;
        z /= length;
    }

    Vector3D Vector3D::cross_product(const Vector3D &other)
    {
        Vector3D result;

        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    double Vector3D::dot_product(const Vector3D &other)
    {
        return x * other.x + y * other.y + z * other.z;
    }

    double Vector3D::length_squared()
    {
        return x * x + y * y + z * z;
    }

    Vector3D Vector3D::operator*(const double &scalar)
    {
        Vector3D result;

        result.x = x * scalar;
        result.y = y * scalar;
        result.z = z * scalar;
        return result;
    }

    Vector3D operator*(const double &scalar, const Vector3D &vector)
    {
        Vector3D result;

        result.x = vector.x * scalar;
        result.y = vector.y * scalar;
        result.z = vector.z * scalar;
        return result;
    }

    Vector3D Vector3D::operator*(const Vector3D &other)
    {
        Vector3D result;

        result.x = x * other.x;
        result.y = y * other.y;
        result.z = z * other.z;
        return result;
    }

    Vector3D Vector3D::operator+(const Vector3D &other)
    {
        Vector3D result;

        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    Vector3D Vector3D::operator-(const Vector3D &other)
    {
        Vector3D result;

        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }
}
