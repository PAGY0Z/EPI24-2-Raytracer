/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "IPrimitive.hpp"

namespace raytracer {
    class TriangleFactoryParameters : public IPrimitiveFactoryParameters {
        public:
            TriangleFactoryParameters(const Point3D &point1, const Point3D &point2, const Point3D &point3, const TripleDouble &rotation, const IMaterial &material) : point1(point1), point2(point2), point3(point3), rotation(rotation), material(material) {}
            ~TriangleFactoryParameters() = default;

            Point3D point1;
            Point3D point2;
            Point3D point3;
            TripleDouble rotation;
            const IMaterial &material;
    };

    class Triangle : public IPrimitive {
        public:
            Triangle(const Point3D &point1, const Point3D &point2, const Point3D &point3, const TripleDouble &rotation, const IMaterial &material);
            ~Triangle() = default;

            bool intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess) override;

        private:
            Point3D point1;
            Point3D point2;
            Point3D point3;
            TripleDouble rotation;
            const IMaterial &material;
    };
}

#endif /* !TRIANGLE_HPP_ */
