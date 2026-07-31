/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

#include "ILight.hpp"

namespace raytracer
{
    class PointFactoryParameters : public ILightFactoryParameters
    {
    public:
        PointFactoryParameters(const Point3D &position, const Color &color, const double &intensity) : position(position), color(color), intensity(intensity) {}
        ~PointFactoryParameters() = default;

        Point3D position;
        Color color;
        double intensity;
    };

    class Point : public ILight
    {
    public:
        Point(const Point3D &position, const Color &color, const double &intensity);
        ~Point() = default;

        bool is_directional() const override;
        Vector3D get_direction() const override;
        Point3D get_position() const override;
        Color get_color() const override;
        double get_intensity(const Point3D &intersection_point) const override;

    private:
        Point3D position;
        Color color;
        double intensity;
    };
};

#endif /* !POINT_HPP_ */
