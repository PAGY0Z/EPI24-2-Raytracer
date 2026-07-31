/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** LightFactory
*/

#ifndef LIGHTFACTORY_HPP_
#define LIGHTFACTORY_HPP_

#include "ILight.hpp"
#include "Directionnal.hpp"
#include "Point.hpp"
#include "AException.hpp"

#include <memory>
#include <functional>
#include <map>

namespace raytracer
{
    class LightFactory
    {
    public:
        LightFactory();
        ~LightFactory() = default;

        std::unique_ptr<ILight> createLight(const std::string &type, ILightFactoryParameters &params);

    private:
        std::map<std::string, std::function<std::unique_ptr<ILight>(ILightFactoryParameters &params)>> _light_creators;
    };

    namespace raytracerExceptions
    {
        class LightFactoryException : public AException
        {
        public:
            LightFactoryException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~LightFactoryException() = default;
        };
    }
}

#endif /* !LIGHTFACTORY_HPP_ */
