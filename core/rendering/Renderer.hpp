/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "AException.hpp"
#include "RenderImage.hpp"
#include <string>
#include <fstream>

namespace raytracer
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        bool saveImage(RenderImage &render_image) const;
    };

    namespace raytracerExceptions
    {
        class RendererException : public AException
        {
        public:
            RendererException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~RendererException() = default;
        };
    }
}

#endif /* !RENDERER_HPP_ */
