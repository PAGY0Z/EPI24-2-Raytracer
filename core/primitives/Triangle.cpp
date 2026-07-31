/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Triangle
*/

#include "Triangle.hpp"

namespace raytracer
{
    Triangle::Triangle(const Point3D &point1, const Point3D &point2, const Point3D &point3, const TripleDouble &rotation, const IMaterial &material) : point1(point1), point2(point2), point3(point3), rotation(rotation), material(material)
    {
    }

    bool Triangle::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        Point3D localOrigin = ray.get_origin();
        Vector3D localDirection = ray.get_direction();

        Vector3D edge1 = point2 - point1;
        Vector3D edge2 = point3 - point1;
        Vector3D h = localDirection.cross_product(edge2);
        double a = edge1.dot_product(h);
        if (a > -0.00001 && a < 0.00001)
            return false;
        double f = 1.0 / a;
        Vector3D s = localOrigin - point1;
        double u = f * s.dot_product(h);
        if (u < 0.0 || u > 1.0)
            return false;
        Vector3D q = s.cross_product(edge1);
        double v = f * localDirection.dot_product(q);
        if (v < 0.0 || u + v > 1.0)
            return false;
        double t = f * edge2.dot_product(q);
        if (t > 0.00001)
        {
            distance = t;
            normal = edge1.cross_product(edge2);
            normal.normalize();
            Point3D intersection = ray.get_origin() + ray.get_direction() * t;
            color = material.GetColor(intersection);
            ambient = material.GetAmbientReflectivity();
            diffuse = material.GetDiffuseReflectivity();
            specular = material.GetSpecularReflectivity();
            shininess = material.GetShininess();
            return true;
        }
        return false;
    }
}