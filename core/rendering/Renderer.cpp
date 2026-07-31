/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Renderer
*/

#include "Renderer.hpp"

namespace raytracer
{
    bool Renderer::saveImage(RenderImage &_render_image) const
    {
        std::ofstream file(_render_image.get_output_file_path() + "." + _render_image.get_output_file_extension());
        if (!file.is_open())
            throw raytracerExceptions::RendererException("Cannot open file", FILE_DATA);
        const int _width = _render_image.get_width();
        const int _height = _render_image.get_height();
        std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> pixel;

        file << "P3\n";
        file << _width << " " << _height << "\n";
        file << "255\n";
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                pixel = _render_image.get_pixel(x, y);
                file << (int)(std::get<0>(pixel) & 0xFF) << " " << (int)(std::get<1>(pixel) & 0xFF) << " " << (int)(std::get<2>(pixel) & 0xFF) << "\n";
            }
        }
        file.close();
        return true;
    }

    namespace raytracerExceptions
    {
        RendererException::RendererException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "RendererException: " + _message;
        }
    }
}
