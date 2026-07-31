/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Point3D.hpp"
#include "TripleDouble.hpp"

namespace raytracer
{
    class Camera
    {
    public:
        Camera();
        ~Camera() = default;

        void set_position(const double &pos_x, const double &pos_y, const double &pos_z);
        void set_rotation(const double &rotation_x, const double &rotation_y, const double &rotation_z);
        void set_fov(double fov);

        void set_position(const Point3D &pos);
        void set_rotation(const TripleDouble &rotation);

        Point3D &get_position();
        TripleDouble &get_rotation();
        double get_fov() const;

    private:
        Point3D position;
        TripleDouble rotation;
        double fov;
    };
}

#endif /* !CAMERA_HPP_ */
