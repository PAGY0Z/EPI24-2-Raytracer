/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "IPrimitive.hpp"
#include "ILight.hpp"
#include "Color.hpp"
#include "Ray.hpp"
#include "TripleDouble.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <limits>

#include "Sphere.hpp"
#include "Plane.hpp"
#include "Point.hpp"

namespace raytracer
{
    struct Intersection
    {
        double distance;
        Vector3D normal;
        Color color;
        double material_ambient;
        double material_diffuse;
        double material_specular;
        double material_shininess;
    };

    class Scene
    {
    public:
        Scene();
        ~Scene() = default;

        void add_primitive(std::unique_ptr<IPrimitive> primitive);
        void add_light(std::unique_ptr<ILight> light);
        void set_ambient_light_intensity(double &intensity);
        void set_diffuse_light_intensity(double &intensity);

        Color cast_ray(const Ray &ray);

    private:
        std::vector<std::unique_ptr<IPrimitive>> _primitives;
        std::vector<std::unique_ptr<ILight>> _lights;
        double _ambient_light_intensity;
        double _diffuse_light_intensity;

        Color compute_phong(const Ray &ray, const Intersection &intersection);
        bool is_in_shadow(const Point3D &point, const Vector3D &light_direction, double &light_distance);
        Vector3D reflect(const Vector3D &incident, const Vector3D &normal);
    };
}

#endif /* !SCENE_HPP_ */
