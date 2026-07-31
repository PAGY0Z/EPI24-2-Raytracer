/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Scene
*/

#include "Scene.hpp"

namespace raytracer
{
    Scene::Scene()
    {
    }

    void Scene::add_primitive(std::unique_ptr<IPrimitive> primitive)
    {
        _primitives.push_back(std::move(primitive));
    }

    void Scene::add_light(std::unique_ptr<ILight> light)
    {
        _lights.push_back(std::move(light));
    }

    void Scene::set_ambient_light_intensity(double &intensity)
    {
        _ambient_light_intensity = intensity;
    }

    void Scene::set_diffuse_light_intensity(double &intensity)
    {
        _diffuse_light_intensity = intensity;
    }

    Color Scene::cast_ray(const Ray &ray)
    {
        std::vector<Intersection> intersections;
        for (auto &primitive : _primitives)
        {
            double distance;
            Vector3D normal;
            Color color;
            double material_ambient;
            double material_diffuse;
            double material_specular;
            double material_shininess;

            if (primitive->intersect(ray, distance, normal, color, material_ambient, material_diffuse, material_specular, material_shininess))
            {
                intersections.push_back(Intersection{distance, normal, color, material_ambient, material_diffuse, material_specular, material_shininess});
            }
        }
        if (intersections.empty())
            return Color(0, 0, 0, 0);
        std::sort(intersections.begin(), intersections.end(), [](Intersection &a, Intersection &b)
                  { return a.distance < b.distance; });
        return compute_phong(ray, intersections[0]);
    }

    Vector3D Scene::reflect(const Vector3D &incident, const Vector3D &normal)
    {
        double dot = incident.get_x() * normal.get_x() + incident.get_y() * normal.get_y() + incident.get_z() * normal.get_z();
        Vector3D tmp = Vector3D(incident.get_x() - normal.get_x() * 2 * dot,
                                incident.get_y() - normal.get_y() * 2 * dot,
                                incident.get_z() - normal.get_z() * 2 * dot);
        return tmp;
    }

    Color Scene::compute_phong(const Ray &ray, const Intersection &intersection)
    {
        Point3D intersection_point = ray.get_origin() + ray.get_direction() * intersection.distance;
        Vector3D normal = intersection.normal;
        normal.normalize();
        TripleDouble color = TripleDouble((double)intersection.color.get_r() / 255.0F,
                                          (double)intersection.color.get_g() / 255.0F,
                                          (double)intersection.color.get_b() / 255.0F);

        TripleDouble ambient = TripleDouble(color.get_x() * _ambient_light_intensity * intersection.material_ambient,
                                            color.get_y() * _ambient_light_intensity * intersection.material_ambient,
                                            color.get_z() * _ambient_light_intensity * intersection.material_ambient);

        TripleDouble final_color = ambient;
        // TripleDouble final_color = TripleDouble(0.0, 0.0, 0.0);

        for (auto &light : _lights)
        {
            Vector3D light_dir;
            double light_distance = std::numeric_limits<double>::infinity();

            if (light->is_directional())
            {
                light_dir = light->get_direction();
                light_dir.normalize();
            }
            else
            {
                light_dir = light->get_position() - intersection_point;
                light_distance = sqrt(light_dir.get_x() * light_dir.get_x() + light_dir.get_y() * light_dir.get_y() + light_dir.get_z() * light_dir.get_z());
                light_dir.normalize();
            }

            if (!is_in_shadow(intersection_point + normal * 0.001, light_dir, light_distance))
            {
                double diffuse_intensity = std::max(light_dir.dot_product(normal), 0.0);
                TripleDouble light_color = TripleDouble((double)light->get_color().get_r() / 255.0F,
                                                        (double)light->get_color().get_g() / 255.0F,
                                                        (double)light->get_color().get_b() / 255.0F);

                TripleDouble diffuse = TripleDouble(color.get_x() * light_color.get_x() * intersection.material_diffuse * diffuse_intensity * light->get_intensity(intersection_point),
                                                    color.get_y() * light_color.get_y() * intersection.material_diffuse * diffuse_intensity * light->get_intensity(intersection_point),
                                                    color.get_z() * light_color.get_z() * intersection.material_diffuse * diffuse_intensity * light->get_intensity(intersection_point));

                Vector3D reflect_dir = reflect(light_dir, normal);
                double spec_intensity = pow(intersection.material_shininess, std::max(reflect_dir.dot_product(ray.get_direction()), 0.0));
                TripleDouble specular = TripleDouble(light_color.get_x() * intersection.material_specular * spec_intensity * light->get_intensity(intersection_point),
                                                     light_color.get_y() * intersection.material_specular * spec_intensity * light->get_intensity(intersection_point),
                                                     light_color.get_z() * intersection.material_specular * spec_intensity * light->get_intensity(intersection_point));

                final_color += diffuse;
                final_color += specular;
            }
        }

        final_color.set_x(std::min(final_color.get_x(), 1.0));
        final_color.set_y(std::min(final_color.get_y(), 1.0));
        final_color.set_z(std::min(final_color.get_z(), 1.0));
        final_color.set_x(std::max(final_color.get_x(), 0.0));
        final_color.set_y(std::max(final_color.get_y(), 0.0));
        final_color.set_z(std::max(final_color.get_z(), 0.0));
        Color final_color_color = Color((uint8_t)(final_color.get_x() * 255.0),
                                        (uint8_t)(final_color.get_y() * 255.0),
                                        (uint8_t)(final_color.get_z() * 255.0),
                                        255);
        return final_color_color;
    }

    bool Scene::is_in_shadow(const Point3D &point, const Vector3D &light_direction, double &light_distance)
    {
        Ray shadow_ray(point, light_direction);
        for (auto &primitive : _primitives)
        {
            double distance;
            Vector3D normal;
            Color color;
            double material_ambient, material_diffuse, material_specular, material_shininess;
            if (primitive->intersect(shadow_ray, distance, normal, color, material_ambient, material_diffuse, material_specular, material_shininess) && distance < light_distance)
            {
                return true;
            }
        }
        return false;
    }
}
