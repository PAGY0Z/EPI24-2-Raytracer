/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cube
*/

#include "Cube.hpp"

#include <limits>

namespace raytracer
{
    Cube::Cube(const Point3D &center, const double &size, const TripleDouble &rotation, const IMaterial &material) : center(center), size(size), rotation(rotation), material(material)
    {
    }

    bool Cube::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        Point3D localOrigin = rotatePoint(ray.get_origin() - center, rotation * -1);
        Vector3D localDirection = rotateVector(ray.get_direction(), rotation * -1);

        double tMin = 0.0;
        double tMax = std::numeric_limits<double>::infinity();
        double t0, t1;

        double invDx = 1.0 / localDirection.get_x();
        t0 = (-(size / 2) - localOrigin.get_x()) * invDx;
        t1 = ((size / 2) - localOrigin.get_x()) * invDx;
        if (invDx < 0.0)
        {
            double tmp = t0;
            t0 = t1;
            t1 = tmp;
        }
        tMin = tMin > t0 ? tMin : t0;
        tMax = tMax < t1 ? tMax : t1;

        double invDy = 1.0 / localDirection.get_y();
        t0 = (-(size / 2) - localOrigin.get_y()) * invDy;
        t1 = ((size / 2) - localOrigin.get_y()) * invDy;
        if (invDy < 0.0)
        {
            double tmp = t0;
            t0 = t1;
            t1 = tmp;
        }
        tMin = tMin > t0 ? tMin : t0;
        tMax = tMax < t1 ? tMax : t1;

        double invDz = 1.0 / localDirection.get_z();
        t0 = (-(size / 2) - localOrigin.get_z()) * invDz;
        t1 = ((size / 2) - localOrigin.get_z()) * invDz;
        if (invDz < 0.0)
        {
            double tmp = t0;
            t0 = t1;
            t1 = tmp;
        }
        tMin = tMin > t0 ? tMin : t0;
        tMax = tMax < t1 ? tMax : t1;

        if (tMax < tMin || tMin < 0)
            return false;

        if (tMin < 0.0)
            tMin = tMax;
        if (tMin < 0.0)
            return false;

        Point3D localHitPoint = localOrigin + tMin * localDirection;

        normal = Vector3D(0, 0, 0);
        double epsilon = 1e-4;
        if (std::abs(localHitPoint.get_x() - (-size / 2)) < epsilon)
            normal.set_x(-1);
        else if (std::abs(localHitPoint.get_x() - (size / 2)) < epsilon)
            normal.set_x(1);
        else if (std::abs(localHitPoint.get_y() - (-size / 2)) < epsilon)
            normal.set_y(-1);
        else if (std::abs(localHitPoint.get_y() - (size / 2)) < epsilon)
            normal.set_y(1);
        else if (std::abs(localHitPoint.get_z() - (-size / 2)) < epsilon)
            normal.set_z(-1);
        else if (std::abs(localHitPoint.get_z() - (size / 2)) < epsilon)
            normal.set_z(1);

        normal = rotateVector(normal, rotation);

        distance = tMin;

        color = material.GetColor(localHitPoint);
        ambient = material.GetAmbientReflectivity();
        diffuse = material.GetDiffuseReflectivity();
        specular = material.GetSpecularReflectivity();
        shininess = material.GetShininess();

        return true;
    }
}