/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Raytracer
*/

#include "Raytracer.hpp"

#define M_PI 3.14159265358979323846

namespace raytracer
{
    Raytracer::Raytracer(const std::string &scene_file_path) : _parser(scene_file_path), _camera(), _scene(), _renderer(), _render_image()
    {
        _parser.ParseRenderImage(_render_image);
        _parser.ParseCamera(_camera);
        _parser.ParseMaterials();
        _parser.ParsePrimitives(_scene);
        _parser.ParseLights(_scene);
        
        std::cout << "Scene loaded successfully." << std::endl;
    }

    void Raytracer::renderRow(const unsigned int &start_row, const unsigned int &end_row)
    {
        Point3D camera_position = _camera.get_position();
        TripleDouble camera_rotation = _camera.get_rotation();
        double camera_fov_radian = _camera.get_fov() * M_PI / 180.F;

        double aspect_ratio = static_cast<double>(_render_image.get_width()) / static_cast<double>(_render_image.get_height());

        double rotation_x = camera_rotation.get_x() * M_PI / 180.0;
        double rotation_y = camera_rotation.get_y() * M_PI / 180.0;
        double rotation_z = camera_rotation.get_z() * M_PI / 180.0;

        Ray ray;
        Color pixel_color;
        Vector3D ray_direction;
        double new_x, new_y;
        unsigned int color_count, color_sum_r, color_sum_g, color_sum_b, color_sum_a = 0;

        for (unsigned int y = start_row; y < end_row && y < _render_image.get_height(); y++)
        {
            for (unsigned int x = 0; x < _render_image.get_width(); x++)
            {
                color_count = 0, color_sum_r = 0, color_sum_g = 0, color_sum_b = 0, color_sum_a = 0;
                for (unsigned int i = 0; i < _render_image.get_ssaa(); i++)
                {
                    for (unsigned int j = 0; j < _render_image.get_ssaa(); j++)
                    {
                        new_x = (x + (i + 0.5) / _render_image.get_ssaa()) / _render_image.get_width();
                        new_y = -(y + (j + 0.5) / _render_image.get_ssaa()) / _render_image.get_height();

                        new_x = (new_x - 0.5) * sqrt(aspect_ratio) * 2.0 * tan(camera_fov_radian / 2);
                        new_y = (new_y + 0.5) / sqrt(aspect_ratio) * 2.0 * tan(camera_fov_radian / 2);

                        ray_direction.set_x(new_x);
                        ray_direction.set_y(1.0);
                        ray_direction.set_z(new_y);

                        double rotate_x = cos(rotation_z) * ray_direction.get_x() - sin(rotation_z) * ray_direction.get_y();
                        double rotate_y = sin(rotation_z) * ray_direction.get_x() + cos(rotation_z) * ray_direction.get_y();
                        ray_direction.set_x(rotate_x);
                        ray_direction.set_y(rotate_y);

                        rotate_x = cos(rotation_y) * ray_direction.get_x() + sin(rotation_y) * ray_direction.get_z();
                        double rotate_z = -sin(rotation_y) * ray_direction.get_x() + cos(rotation_y) * ray_direction.get_z();
                        ray_direction.set_x(rotate_x);
                        ray_direction.set_z(rotate_z);

                        rotate_y = cos(rotation_x) * ray_direction.get_y() - sin(rotation_x) * ray_direction.get_z();
                        rotate_z = sin(rotation_x) * ray_direction.get_y() + cos(rotation_x) * ray_direction.get_z();
                        ray_direction.set_y(rotate_y);
                        ray_direction.set_z(rotate_z);

                        ray_direction.normalize();

                        ray.set_direction(ray_direction);

                        ray.set_direction(ray_direction);
                        ray.set_origin(camera_position);
                        pixel_color = _scene.cast_ray(ray);
                        color_sum_r += pixel_color.get_r();
                        color_sum_g += pixel_color.get_g();
                        color_sum_b += pixel_color.get_b();
                        color_sum_a += pixel_color.get_a();
                        color_count++;
                    }
                }
                pixel_color.set_rgba(color_sum_r / color_count, color_sum_g / color_count, color_sum_b / color_count, color_sum_a / color_count);
                _render_image.set_pixel(x, y, pixel_color.get_r(), pixel_color.get_g(), pixel_color.get_b(), pixel_color.get_a());
            }
        }
    }

    int Raytracer::render()
    {
        int thread_count = std::thread::hardware_concurrency();
        std::vector<std::thread> threads;
        unsigned int total_rows = _render_image.get_height();
        unsigned int start_row = 0;
        unsigned int end_row = 0;
        unsigned int rows_per_thread = total_rows / thread_count;
        for (int i = 0; i < thread_count; i++)
        {
            start_row = i * rows_per_thread;
            end_row = (i + 1) * rows_per_thread;
            if (i == thread_count - 1)
                end_row = total_rows;
            threads.push_back(std::thread(&Raytracer::renderRow, this, start_row, end_row));
        }
        for (int i = 0; i < thread_count; i++)
        {
            threads[i].join();
        }
        _renderer.saveImage(_render_image);
        return 0;
    }

    namespace raytracerExceptions
    {
        RaytracerException::RaytracerException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "RaytracerException: " + _message;
        }
    }
}
