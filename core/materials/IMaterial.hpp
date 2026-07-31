/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "Color.hpp"
#include "Point3D.hpp"

namespace raytracer
{
    class IMaterialFactoryParameters
    {
    public:
        virtual ~IMaterialFactoryParameters() = default;
    };

    class IMaterial
    {
    public:
        ~IMaterial() = default;

        virtual Color GetColor(Point3D &intersection) const = 0;
        virtual double GetAmbientReflectivity() const = 0;
        virtual double GetDiffuseReflectivity() const = 0;
        virtual double GetSpecularReflectivity() const = 0;
        virtual double GetShininess() const = 0;
    };
}

#endif /* !IMATERIAL_HPP_ */
