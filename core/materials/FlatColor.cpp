/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** FlatColor
*/

#include "FlatColor.hpp"

namespace raytracer
{
    FlatColor::FlatColor(const Color &color, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess)
        : _color(color), _ambient_reflectivity(ambient_reflectivity), _diffuse_reflectivity(diffuse_reflectivity), _specular_reflectivity(specular_reflectivity), _shininess(shininess)
    {
    }

    Color FlatColor::GetColor(Point3D &intersection) const
    {
        (void)intersection;
        return _color;
    }

    double FlatColor::GetAmbientReflectivity() const
    {
        return _ambient_reflectivity;
    }

    double FlatColor::GetDiffuseReflectivity() const
    {
        return _diffuse_reflectivity;
    }

    double FlatColor::GetSpecularReflectivity() const
    {
        return _specular_reflectivity;
    }

    double FlatColor::GetShininess() const
    {
        return _shininess;
    }
}
