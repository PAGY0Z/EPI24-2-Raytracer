/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IPrimitive.hpp"

namespace raytracer
{
    class SphereFactoryParameters : public IPrimitiveFactoryParameters
    {
    public:
        SphereFactoryParameters(const Point3D &center, const double &radius, const IMaterial &material) : center(center), radius(radius), material(material) {}
        ~SphereFactoryParameters() = default;

        Point3D center;
        double radius;
        const IMaterial &material;
    };

    class Sphere : public IPrimitive
    {
    public:
        Sphere(const Point3D &center, const double &radius, const IMaterial &material);
        ~Sphere() = default;

        bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

    private:
        Point3D center;
        double radius;
        const IMaterial &material;
    };
}

#endif /* !SPHERE_HPP_ */
