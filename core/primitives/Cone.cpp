/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Cone
*/

#include "Cone.hpp"

#define M_PI 3.14159265358979323846

namespace raytracer
{
    Cone::Cone(const Point3D &base_center, const double &height, const double &radius, const TripleDouble &rotation, const IMaterial &material) : base_center(base_center), height(height), radius(radius), rotation(rotation), material(material)
    {
    }

    Vector3D rotateVector(const Vector3D &vector, const TripleDouble &rotation)
    {
        double alpha = rotation.get_x() * M_PI / 180;
        double beta = rotation.get_y() * M_PI / 180;
        double gamma = rotation.get_z() * M_PI / 180;

        double cosA = cos(alpha), sinA = sin(alpha);
        double cosB = cos(beta), sinB = sin(beta);
        double cosG = cos(gamma), sinG = sin(gamma);

        double m11 = cosB * cosG;
        double m12 = cosG * sinA * sinB - cosA * sinG;
        double m13 = sinA * sinG + cosA * cosG * sinB;

        double m21 = cosB * sinG;
        double m22 = cosA * cosG + sinA * sinB * sinG;
        double m23 = cosA * sinB * sinG - cosG * sinA;

        double m31 = -sinB;
        double m32 = cosB * sinA;
        double m33 = cosA * cosB;

        Vector3D transformedVector;
        transformedVector.set_x(m11 * vector.get_x() + m12 * vector.get_y() + m13 * vector.get_z());
        transformedVector.set_y(m21 * vector.get_x() + m22 * vector.get_y() + m23 * vector.get_z());
        transformedVector.set_z(m31 * vector.get_x() + m32 * vector.get_y() + m33 * vector.get_z());

        return transformedVector;
    }

    Point3D rotatePoint(const Vector3D &vector, const TripleDouble &rotation)
    {
        double alpha = rotation.get_x() * M_PI / 180;
        double beta = rotation.get_y() * M_PI / 180;
        double gamma = rotation.get_z() * M_PI / 180;

        double cosA = cos(alpha), sinA = sin(alpha);
        double cosB = cos(beta), sinB = sin(beta);
        double cosG = cos(gamma), sinG = sin(gamma);

        double m11 = cosB * cosG;
        double m12 = cosG * sinA * sinB - cosA * sinG;
        double m13 = sinA * sinG + cosA * cosG * sinB;

        double m21 = cosB * sinG;
        double m22 = cosA * cosG + sinA * sinB * sinG;
        double m23 = cosA * sinB * sinG - cosG * sinA;

        double m31 = -sinB;
        double m32 = cosB * sinA;
        double m33 = cosA * cosB;

        Point3D transformedPoint;
        transformedPoint.set_x(m11 * vector.get_x() + m12 * vector.get_y() + m13 * vector.get_z());
        transformedPoint.set_y(m21 * vector.get_x() + m22 * vector.get_y() + m23 * vector.get_z());
        transformedPoint.set_z(m31 * vector.get_x() + m32 * vector.get_y() + m33 * vector.get_z());

        return transformedPoint;
    }

    bool Cone::intersect(const Ray &ray, double &distance, Vector3D &normal, Color &color, double &ambient, double &diffuse, double &specular, double &shininess)
    {
        Point3D localOrigin = rotatePoint(ray.get_origin() - base_center, rotation * -1);
        Vector3D localDirection = rotateVector(ray.get_direction(), rotation * -1);

        Ray localRay = Ray(localOrigin, localDirection);

        double k = radius / height;
        k = k * k;

        Point3D local_Ray_Origin = localRay.get_origin();
        Vector3D local_Ray_Direction = localRay.get_direction();

        double A = local_Ray_Direction.get_x() * local_Ray_Direction.get_x() + local_Ray_Direction.get_y() * local_Ray_Direction.get_y() - k * local_Ray_Direction.get_z() * local_Ray_Direction.get_z();
        double B = 2 * (local_Ray_Origin.get_x() * local_Ray_Direction.get_x() + local_Ray_Origin.get_y() * local_Ray_Direction.get_y() - k * local_Ray_Origin.get_z() * local_Ray_Direction.get_z());
        double C = local_Ray_Origin.get_x() * local_Ray_Origin.get_x() + local_Ray_Origin.get_y() * local_Ray_Origin.get_y() - k * local_Ray_Origin.get_z() * local_Ray_Origin.get_z();

        double discriminant = B * B - 4 * A * C;
        if (discriminant < 0)
        {
            return false;
        }

        double t1 = (-B - sqrt(discriminant)) / (2 * A);
        double t2 = (-B + sqrt(discriminant)) / (2 * A);

        double t = t1 < t2 ? t1 : t2;

        if (t < 0)
        {
            t = t1 > t2 ? t1 : t2;
            if (t < 0)
            {
                t = t1 < t2 ? t1 : t2;
            }
        }

        Point3D point = localRay.get_origin() + t * localRay.get_direction();

        if (point.get_z() < 0 || point.get_z() > height)
        {
            return false;
        }

        normal = Vector3D(2 * k * point.get_x(), 2 * point.get_y(), -2 * k * point.get_z());
        normal.normalize();

        distance = t;
        color = material.GetColor(point);
        ambient = material.GetAmbientReflectivity();
        diffuse = material.GetDiffuseReflectivity();
        specular = material.GetSpecularReflectivity();
        shininess = material.GetShininess();

        return true;
    }
}
