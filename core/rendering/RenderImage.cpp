/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** RenderImage
*/

#include "RenderImage.hpp"

namespace raytracer
{
    RenderImage::RenderImage()
    {
        _width = 1920;
        _height = 1080;
        _ssaa = 1;
        _output_file_path = "output";
        _output_file_extension = "ppm";
        _pixels = std::make_unique<uint8_t[]>(_width * _height * 4);
    }

    bool RenderImage::set_width(const unsigned int &width)
    {
        try
        {
            _width = width;
            _pixels = std::make_unique<uint8_t[]>(_width * _height * 4);
            return true;
        }
        catch (const std::exception &except)
        {
            throw raytracerExceptions::RenderImageException(std::string(except.what()), FILE_DATA);
            return false;
        }
    }

    bool RenderImage::set_height(const unsigned int &height)
    {
        try
        {
            _height = height;
            _pixels = std::make_unique<uint8_t[]>(_width * _height * 4);
            return true;
        }
        catch (const std::exception &except)
        {
            throw raytracerExceptions::RenderImageException(std::string(except.what()), FILE_DATA);
            return false;
        }
    }

    bool RenderImage::set_ssaa(const unsigned int &ssaa)
    {
        _ssaa = ssaa;
        return true;
    }

    bool RenderImage::set_output_file_path(const std::string &output_file_path)
    {
        _output_file_path = output_file_path;
        return true;
    }

    bool RenderImage::set_output_file_extension(const std::string &output_file_extension)
    {
        _output_file_extension = output_file_extension;
        return true;
    }

    bool RenderImage::set_pixel(const unsigned int &x, const unsigned int &y, const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a)
    {
        if (x >= _width || y >= _height)
        {
            throw raytracerExceptions::RenderImageException("Pixel out of bounds", FILE_DATA);
            return false;
        }
        _pixels[(y * _width + x) * 4 + 0] = r;
        _pixels[(y * _width + x) * 4 + 1] = g;
        _pixels[(y * _width + x) * 4 + 2] = b;
        _pixels[(y * _width + x) * 4 + 3] = a;
        return true;
    }

    unsigned int RenderImage::get_width() const
    {
        return _width;
    }

    unsigned int RenderImage::get_height() const
    {
        return _height;
    }

    unsigned int RenderImage::get_ssaa() const
    {
        return _ssaa;
    }

    std::string RenderImage::get_output_file_path() const
    {
        return _output_file_path;
    }

    std::string RenderImage::get_output_file_extension() const
    {
        return _output_file_extension;
    }

    std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> RenderImage::get_pixel(const unsigned int &x, const unsigned int &y) const
    {
        if (x >= _width || y >= _height)
        {
            throw raytracerExceptions::RenderImageException("Pixel out of bounds", FILE_DATA);
            return std::make_tuple(0, 0, 0, 0);
        }
        return std::make_tuple(_pixels[(y * _width + x) * 4 + 0], _pixels[(y * _width + x) * 4 + 1], _pixels[(y * _width + x) * 4 + 2], _pixels[(y * _width + x) * 4 + 3]);
    }

    namespace raytracerExceptions
    {
        RenderImageException::RenderImageException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "RenderImageException: " + _message;
        }
    }
}
