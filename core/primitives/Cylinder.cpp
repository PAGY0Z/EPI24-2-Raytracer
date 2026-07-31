/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

namespace raytracer
{
    Cylinder::Cylinder(const Point3D &center, const double &radius, const double &height, const TripleDouble &rotation, const IMaterial &material) : center(center), radius(radius), height(height), rotation(rotation), material(material)
    {
    }

    bool Cylinder::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        Vector3D dir = rotateVector(ray.get_direction(), rotation * -1);
        Point3D orig = rotatePoint(ray.get_origin() - center, rotation * -1);

        double dx = orig.get_x();
        double dy = orig.get_y();

        double a = dir.get_x() * dir.get_x() + dir.get_y() * dir.get_y();
        double b = 2 * (dir.get_x() * dx + dir.get_y() * dy);
        double c = dx * dx + dy * dy - radius * radius;

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            return false;
        }

        double t0 = (-b - sqrt(discriminant)) / (2 * a);
        double t1 = (-b + sqrt(discriminant)) / (2 * a);

        if (t0 > t1)
            std::swap(t0, t1);

        double z0 = orig.get_z() + t0 * dir.get_z();
        double z1 = orig.get_z() + t1 * dir.get_z();

        bool withinBoundsT0 = (z0 >= 0 && z0 <= height && t0 >= 0);
        bool withinBoundsT1 = (z1 >= 0 && z1 <= height && t1 >= 0);

        if (!withinBoundsT0 && !withinBoundsT1)
            return false;

        if (withinBoundsT0)
        {
            distance = t0;
        }
        else if (withinBoundsT1)
        {
            distance = t1;
        }
        else
        {
            return false;
        }

        Point3D intersection = orig + distance * dir;
        normal = Vector3D(intersection.get_x(), intersection.get_y(), 0);
        normal.normalize();
        normal = rotateVector(normal, rotation);

        color = material.GetColor(intersection);
        ambient = material.GetAmbientReflectivity();
        diffuse = material.GetDiffuseReflectivity();
        specular = material.GetSpecularReflectivity();
        shininess = material.GetShininess();

        return true;
    }
}
