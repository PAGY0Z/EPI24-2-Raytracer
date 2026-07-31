/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Raytracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include <string>
#include <memory>
#include <cmath>
#include <thread>

#include "AException.hpp"
#include "RenderImage.hpp"
#include "Renderer.hpp"
#include "Parser.hpp"
#include "Scene.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Color.hpp"

namespace raytracer
{
    class Raytracer
    {
    public:
        Raytracer(const std::string &scene_file_path);
        ~Raytracer() = default;

        int render();

    private:
        Parser _parser;
        Camera _camera;
        Scene _scene;
        Renderer _renderer;
        RenderImage _render_image;

        void renderRow(const unsigned int &start_row, const unsigned int &end_row);
    };

    namespace raytracerExceptions
    {
        class RaytracerException : public AException
        {
        public:
            RaytracerException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~RaytracerException() = default;
        };
    }
}

#endif /* !RAYTRACER_HPP_ */
