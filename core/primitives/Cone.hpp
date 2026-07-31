/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "IPrimitive.hpp"
#include "TripleDouble.hpp"

namespace raytracer
{
    class ConeFactoryParameters : public IPrimitiveFactoryParameters
    {
    public:
        ConeFactoryParameters(const Point3D &base_center, const double &height, const double &radius, const TripleDouble &rotation, const IMaterial &material) : base_center(base_center), height(height), radius(radius), rotation(rotation), material(material) {}
        ~ConeFactoryParameters() = default;

        Point3D base_center;
        double height;
        double radius;
        TripleDouble rotation;
        const IMaterial &material;
    };

    class Cone : public IPrimitive
    {
    public:
        Cone(const Point3D &base_center, const double &height, const double &radius, const TripleDouble &rotation, const IMaterial &material);
        ~Cone() = default;

        bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

    private:
        Point3D base_center;
        double height;
        double radius;
        TripleDouble rotation;
        const IMaterial &material;
    };
}

#endif /* !CONE_HPP_ */
