/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace raytracer
{
    Sphere::Sphere(const Point3D &center, const double &radius, const IMaterial &material) : center(center), radius(radius), material(material)
    {
    }

    bool Sphere::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        double a = ray.get_direction().dot_product(ray.get_direction());
        double b = 2 * ray.get_direction().dot_product(ray.get_origin() - center);
        double c = (ray.get_origin() - center).dot_product(ray.get_origin() - center) - radius * radius;
        double delta = b * b - 4 * a * c;

        if (delta < 0)
            return false;
        double t1 = (-b - sqrt(delta)) / (2 * a);
        double t2 = (-b + sqrt(delta)) / (2 * a);
        if (t1 < 0 && t2 < 0)
            return false;
        if (t1 < 0)
            distance = t2;
        else if (t2 < 0)
            distance = t1;
        else
            distance = std::min(t1, t2);

        Point3D intersection = ray.get_origin() + ray.get_direction() * distance;
        normal = (intersection - center);
        normal.normalize();
        color = material.GetColor(intersection);
        ambient = material.GetAmbientReflectivity();
        diffuse = material.GetDiffuseReflectivity();
        specular = material.GetSpecularReflectivity();
        shininess = material.GetShininess();
        return true;
    }
}
