/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "IPrimitive.hpp"
#include "TripleDouble.hpp"

namespace raytracer
{
    class CylinderFactoryParameters : public IPrimitiveFactoryParameters
    {
    public:
        CylinderFactoryParameters(const Point3D &center, const double &radius, const double &height, const TripleDouble &rotation, const IMaterial &material) : center(center), radius(radius), height(height), rotation(rotation), material(material) {}
        ~CylinderFactoryParameters() = default;

        Point3D center;
        double radius;
        double height;
        TripleDouble rotation;
        const IMaterial &material;
    };

    class Cylinder : public IPrimitive
    {
    public:
        Cylinder(const Point3D &center, const double &radius, const double &height, const TripleDouble &rotation, const IMaterial &material);
        ~Cylinder() = default;

        bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

    private:
        Point3D center;
        double radius;
        double height;
        TripleDouble rotation;
        const IMaterial &material;
    };
}

#endif /* !CYLINDER_HPP_ */
