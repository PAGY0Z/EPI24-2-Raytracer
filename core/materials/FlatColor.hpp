/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** FlatColor
*/

#ifndef FLATCOLOR_HPP_
#define FLATCOLOR_HPP_

#include "IMaterial.hpp"

namespace raytracer
{
    class FlatColorFactoryParameters : public IMaterialFactoryParameters
    {
    public:
        FlatColorFactoryParameters(const Color &color, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess)
            : color(color), ambient_reflectivity(ambient_reflectivity), diffuse_reflectivity(diffuse_reflectivity), specular_reflectivity(specular_reflectivity), shininess(shininess) {}
        ~FlatColorFactoryParameters() = default;

        Color color;
        double ambient_reflectivity;
        double diffuse_reflectivity;
        double specular_reflectivity;
        double shininess;
    };

    class FlatColor : public IMaterial
    {
    public:
        FlatColor(const Color &color, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess);
        ~FlatColor() = default;

        Color GetColor(Point3D &intersection) const override;
        double GetAmbientReflectivity() const override;
        double GetDiffuseReflectivity() const override;
        double GetSpecularReflectivity() const override;
        double GetShininess() const override;

    private:
        Color _color;
        double _ambient_reflectivity;
        double _diffuse_reflectivity;
        double _specular_reflectivity;
        double _shininess;
    };
}

#endif /* !FLATCOLOR_HPP_ */
