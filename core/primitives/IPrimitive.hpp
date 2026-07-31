/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "Color.hpp"
#include "Ray.hpp"
#include "IMaterial.hpp"
#include "TripleDouble.hpp"

namespace raytracer
{
    Vector3D rotateVector(const Vector3D &vector, const TripleDouble &rotation);
    Point3D rotatePoint(const Vector3D &vector, const TripleDouble &rotation);

    class IPrimitiveFactoryParameters
    {
    public:
        virtual ~IPrimitiveFactoryParameters() = default;
    };

    class IPrimitive
    {
    public:
        virtual ~IPrimitive() = default;

        virtual bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) = 0;
    };
}

#endif /* !IPRIMITIVE_HPP_ */
