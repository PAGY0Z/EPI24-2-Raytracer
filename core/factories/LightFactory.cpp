/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** LightFactory
*/

#include "LightFactory.hpp"

namespace raytracer
{
    std::unique_ptr<ILight> CreateDirectionnal(const ILightFactoryParameters &params)
    {
        try
        {
            auto &directionnal_params = dynamic_cast<const DirectionnalFactoryParameters &>(params);
            return std::make_unique<Directionnal>(directionnal_params.direction, directionnal_params.color, directionnal_params.intensity);
        }
        catch (const std::exception &except)
        {
            throw raytracerExceptions::LightFactoryException("Invalid parameters for Directionnal light", FILE_DATA);
        }
    }

    std::unique_ptr<ILight> CreatePoint(const ILightFactoryParameters &params)
    {
        try
        {
            auto &point_params = dynamic_cast<const PointFactoryParameters &>(params);
            return std::make_unique<Point>(point_params.position, point_params.color, point_params.intensity);
        }
        catch (const std::exception &except)
        {
            throw raytracerExceptions::LightFactoryException("Invalid parameters for Point light", FILE_DATA);
        }
    }

    LightFactory::LightFactory()
    {
        _light_creators["Directionnal"] = CreateDirectionnal;
        _light_creators["Point"] = CreatePoint;
    }

    std::unique_ptr<ILight> LightFactory::createLight(const std::string &type, ILightFactoryParameters &params)
    {
        if (_light_creators.find(type) == _light_creators.end())
            throw raytracerExceptions::LightFactoryException("Light type \"" + type + "\" not found", FILE_DATA);
        return _light_creators[type](params);
    }

    namespace raytracerExceptions
    {
        LightFactoryException::LightFactoryException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "LightFactoryException: " + _message;
        }
    }
}
