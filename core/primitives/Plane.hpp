/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "IPrimitive.hpp"

namespace raytracer
{
    class PlaneFactoryParameters : public IPrimitiveFactoryParameters
    {
    public:
        PlaneFactoryParameters(const Point3D &point, const Vector3D &normal, const IMaterial &material) : point(point), normal(normal), material(material) {}
        ~PlaneFactoryParameters() = default;

        Point3D point;
        Vector3D normal;
        const IMaterial &material;
    };

    class Plane : public IPrimitive
    {
    public:
        Plane(const Point3D &point, const Vector3D &normal, const IMaterial &material);
        ~Plane() = default;

        bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

    private:
        Point3D point;
        Vector3D normal;
        const IMaterial &material;
    };
}

#endif /* !PLANE_HPP_ */
