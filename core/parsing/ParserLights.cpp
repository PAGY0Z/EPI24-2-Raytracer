/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ParserLights
*/

#include "Parser.hpp"

namespace raytracer
{
    void Parser::ParseLights(Scene &scene)
    {
        try
        {
            const libconfig::Setting &rootSetting = _cfg.getRoot();
            const libconfig::Setting &sceneSetting = rootSetting["scene"];
            const libconfig::Setting &lightsSetting = sceneSetting["lights"];
            const libconfig::Setting &physicalLightsSetting = lightsSetting["physical_lights"];

            double ambient_light, diffuse = 0;

            int light_count = physicalLightsSetting.getLength();

            if (lightsSetting.lookupValue("ambient_light", ambient_light) == false)
                throw raytracerExceptions::ParserException("Ambient light not found in configuration file", FILE_DATA);
            if (lightsSetting.lookupValue("diffuse", diffuse) == false)
                throw raytracerExceptions::ParserException("Diffuse not found in configuration file", FILE_DATA);

            for (int i = 0; i < light_count; i++)
            {
                const libconfig::Setting &lightSetting = physicalLightsSetting[i];
                std::string light_type = "";

                if (lightSetting.lookupValue("type", light_type) == false)
                    throw raytracerExceptions::ParserException("Light type not found in configuration file", FILE_DATA);

                if (light_type == "Point")
                {
                    ParsePoint(lightSetting, scene);
                }
                else if (light_type == "Directional")
                {
                    ParseDirectional(lightSetting, scene);
                }
                else
                {
                    throw raytracerExceptions::ParserException("Light type not recognized", FILE_DATA);
                }
            }
            scene.set_ambient_light_intensity(ambient_light);
            scene.set_diffuse_light_intensity(diffuse);
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParsePoint(const Setting &lightSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &positionSetting = lightSetting["position"];
            const libconfig::Setting &colorSetting = lightSetting["color"];
            double intensity = 0;

            Point3D position = ParsePoint3D(positionSetting);
            Color color = ParseColor(colorSetting);

            if (lightSetting.lookupValue("intensity", intensity) == false)
                throw raytracerExceptions::ParserException("Intensity not found in configuration file", FILE_DATA);

            if (intensity < 0)
                throw raytracerExceptions::ParserException("Intensity must be greater than 0", FILE_DATA);

            PointFactoryParameters params(position, color, intensity);
            std::unique_ptr<ILight> light = _light_factory.createLight("Point", params);
            scene.add_light(std::move(light));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseDirectional(const Setting &lightSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &vectorSetting = lightSetting["vector"];
            const libconfig::Setting &colorSetting = lightSetting["color"];
            double intensity = 0;

            Vector3D vector = ParseVector3D(vectorSetting);
            Color color = ParseColor(colorSetting);

            if (lightSetting.lookupValue("intensity", intensity) == false)
                throw raytracerExceptions::ParserException("Intensity not found in configuration file", FILE_DATA);
            if (intensity < 0)
                throw raytracerExceptions::ParserException("Intensity must be greater than 0", FILE_DATA);

            DirectionnalFactoryParameters params(vector, color, intensity);
            std::unique_ptr<ILight> light = _light_factory.createLight("Directionnal", params);
            scene.add_light(std::move(light));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }
}
