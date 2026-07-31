/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Plane
*/

#include "Plane.hpp"

namespace raytracer
{
    Plane::Plane(const Point3D &point, const Vector3D &normal, const IMaterial &material) : point(point), normal(normal), material(material)
    {
    }

    bool Plane::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        double denom = ray.get_direction().dot_product(this->normal);
        if (std::abs(denom) > 1e-6)
        {
            Vector3D p0l0 = this->point - ray.get_origin();
            distance = p0l0.dot_product(this->normal) / denom;
            if (distance >= 0)
            {
                Point3D intersection = ray.get_origin() + ray.get_direction() * distance;
                normal = this->normal;
                color = material.GetColor(intersection);
                ambient = material.GetAmbientReflectivity();
                diffuse = material.GetDiffuseReflectivity();
                specular = material.GetSpecularReflectivity();
                shininess = material.GetShininess();
                return true;
            }
        }
        return false;
    }
}
