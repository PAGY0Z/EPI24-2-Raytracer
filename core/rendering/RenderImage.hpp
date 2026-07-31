/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** RenderImage
*/

#ifndef RENDERIMAGE_HPP_
#define RENDERIMAGE_HPP_

#include "AException.hpp"
#include <cstdint>
#include <tuple>
#include <memory>

namespace raytracer
{
    class RenderImage
    {
    public:
        RenderImage();
        ~RenderImage() = default;

        bool set_width(const unsigned int &width);
        bool set_height(const unsigned int &height);
        bool set_ssaa(const unsigned int &ssaa);
        bool set_output_file_path(const std::string &output_file_path);
        bool set_output_file_extension(const std::string &output_file_extension);
        bool set_pixel(const unsigned int &x, const unsigned int &y, const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a);

        unsigned int get_width() const;
        unsigned int get_height() const;
        unsigned int get_ssaa() const;
        std::string get_output_file_path() const;
        std::string get_output_file_extension() const;
        std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> get_pixel(const unsigned int &x, const unsigned int &y) const;

    protected:
    private:
        unsigned int _width;
        unsigned int _height;
        unsigned int _ssaa;
        std::string _output_file_path;
        std::string _output_file_extension;
        std::unique_ptr<uint8_t[]> _pixels;
    };

    namespace raytracerExceptions
    {
        class RenderImageException : public AException
        {
        public:
            RenderImageException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~RenderImageException() = default;
        };
    }
}

#endif /* !RENDERIMAGE_HPP_ */
