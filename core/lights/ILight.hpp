/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "Color.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

namespace raytracer
{
    class ILightFactoryParameters
    {
    public:
        virtual ~ILightFactoryParameters() = default;
    };

    class ILight
    {
    public:
        virtual ~ILight() = default;

        virtual bool is_directional() const = 0;
        virtual Vector3D get_direction() const = 0;
        virtual Point3D get_position() const = 0;
        virtual Color get_color() const = 0;
        virtual double get_intensity(const Point3D &intersection_point) const = 0;
    };
}

#endif /* !ILIGHT_HPP_ */
