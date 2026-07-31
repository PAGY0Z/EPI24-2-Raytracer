/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "IPrimitive.hpp"

namespace raytracer
{
    class CubeFactoryParameters : public IPrimitiveFactoryParameters
    {
    public:
        CubeFactoryParameters(const Point3D &center, const double &size, const TripleDouble &rotation, const IMaterial &material) : center(center), size(size), rotation(rotation), material(material) {}
        ~CubeFactoryParameters() = default;

        Point3D center;
        double size;
        TripleDouble rotation;
        const IMaterial &material;
    };

    class Cube : public IPrimitive
    {
    public:
        Cube(const Point3D &center, const double &size, const TripleDouble &rotation, const IMaterial &material);
        ~Cube() = default;

        bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

    private:
        Point3D center;
        double size;
        TripleDouble rotation;
        const IMaterial &material;
    };
}

#endif /* !CUBE_HPP_ */
