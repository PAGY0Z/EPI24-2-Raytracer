/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Directionnal
*/

#ifndef DIRECTIONNAL_HPP_
#define DIRECTIONNAL_HPP_

#include "ILight.hpp"

namespace raytracer
{
    class DirectionnalFactoryParameters : public ILightFactoryParameters
    {
    public:
        DirectionnalFactoryParameters(const Vector3D &direction, const Color &color, const double &intensity) : direction(direction), color(color), intensity(intensity) {}
        ~DirectionnalFactoryParameters() = default;

        Vector3D direction;
        Color color;
        double intensity;
    };

    class Directionnal : public ILight
    {
    public:
        Directionnal(const Vector3D &direction, const Color &color, const double &intensity);
        ~Directionnal() = default;

        bool is_directional() const override;
        Vector3D get_direction() const override;
        Point3D get_position() const override;
        Color get_color() const override;
        double get_intensity(const Point3D &intersection_point) const override;

    private:
        Vector3D direction;
        Color color;
        double intensity;
    };
}

#endif /* !DIRECTIONNAL_HPP_ */
