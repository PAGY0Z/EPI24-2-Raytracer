/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>

namespace raytracer
{
    class Vector3D
    {
    public:
        Vector3D();
        Vector3D(const double &x, const double &y, const double &z);
        ~Vector3D() = default;

        double get_x() const;
        double get_y() const;
        double get_z() const;

        void set_x(const double &x);
        void set_y(const double &y);
        void set_z(const double &z);

        void normalize();

        Vector3D cross_product(const Vector3D &other);
        double dot_product(const Vector3D &other);
        double length_squared();

        Vector3D operator*(const double &scalar);
        friend Vector3D operator*(const double &scalar, const Vector3D &vector);
        Vector3D operator*(const Vector3D &other);
        Vector3D operator+(const Vector3D &other);
        Vector3D operator-(const Vector3D &other);

    private:
        double x;
        double y;
        double z;
    };
}

#endif /* !VECTOR3D_HPP_ */
