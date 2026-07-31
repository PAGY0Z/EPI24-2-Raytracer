/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Camera
*/

#include "Camera.hpp"

namespace raytracer
{
    Camera::Camera()
    {
        position = Point3D();
        rotation = TripleDouble();
        fov = 0;
    }

    void Camera::set_position(const double &pos_x, const double &pos_y, const double &pos_z)
    {
        position.set_x(pos_x);
        position.set_y(pos_y);
        position.set_z(pos_z);
    }

    void Camera::set_rotation(const double &rotation_x, const double &rotation_y, const double &rotation_z)
    {
        rotation.set_x(rotation_x);
        rotation.set_y(rotation_y);
        rotation.set_z(rotation_z);
    }

    void Camera::set_position(const Point3D &pos)
    {
        position = pos;
    }

    void Camera::set_rotation(const TripleDouble &rotation)
    {
        this->rotation = rotation;
    }

    void Camera::set_fov(double fov)
    {
        this->fov = fov;
    }

    Point3D &Camera::get_position()
    {
        return position;
    }

    TripleDouble &Camera::get_rotation()
    {
        return rotation;
    }

    double Camera::get_fov() const
    {
        return fov;
    }
}
