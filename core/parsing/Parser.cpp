/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Parser
*/

#include "Parser.hpp"

namespace raytracer
{
    Parser::Parser(const std::string &config_file_path) : _material_factory(), _config_file_path(config_file_path), _cfg()
    {
        try
        {
            _cfg.readFile(_config_file_path.c_str());
        }
        catch (const libconfig::FileIOException &fioex)
        {
            throw raytracerExceptions::ParserException("I/O error while reading file.", FILE_DATA);
        }
        catch (const libconfig::ParseException &pex)
        {
            throw raytracerExceptions::ParserException("Parse error at " + std::to_string(pex.getLine()) + ": " + pex.getError(), FILE_DATA);
        }
    }

    void Parser::ParseCamera(Camera &camera)
    {
        try
        {
            const libconfig::Setting &rootSetting = _cfg.getRoot();
            const libconfig::Setting &sceneSetting = rootSetting["scene"];
            const libconfig::Setting &cameraSetting = sceneSetting["camera"];

            const libconfig::Setting &positionSetting = cameraSetting["position"];
            const libconfig::Setting &RotationSetting = cameraSetting["rotation"];

            double fov = 0;

            Point3D position = ParsePoint3D(positionSetting);
            TripleDouble rotation = ParseTripleDouble(RotationSetting);

            if (cameraSetting.lookupValue("fov", fov) == false)
                throw raytracerExceptions::ParserException("Fov not found in configuration file", FILE_DATA);
            if (fov < 0 || 180 < fov)
                throw raytracerExceptions::ParserException("Fov must be between 0 and 180", FILE_DATA);

            camera.set_position(position);
            camera.set_rotation(rotation);
            camera.set_fov(fov);
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseRenderImage(RenderImage &render_image)
    {
        try
        {
            const libconfig::Setting &root = _cfg.getRoot();
            const libconfig::Setting &renderImage = root["render_image"];

            std::string output_file_path_str = "";
            unsigned int width_int, height_int, ssaa_int = 1;

            if (renderImage.lookupValue("output_file_path", output_file_path_str) == false)
                throw raytracerExceptions::ParserException("Output file path not found in configuration file", FILE_DATA);

            if (renderImage.lookupValue("width", width_int) == false)
                throw raytracerExceptions::ParserException("Width not found in configuration file", FILE_DATA);
            if (renderImage.lookupValue("height", height_int) == false)
                throw raytracerExceptions::ParserException("Height not found in configuration file", FILE_DATA);
            if (renderImage.lookupValue("ssaa", ssaa_int) == false)
                throw raytracerExceptions::ParserException("SSAA not found in configuration file", FILE_DATA);

            if (width_int <= 0 || height_int <= 0)
                throw raytracerExceptions::ParserException("Width and height must be greater than 0", FILE_DATA);
            if (ssaa_int < 1 || 16 < ssaa_int)
                throw raytracerExceptions::ParserException("SSAA must be between 1 and 16", FILE_DATA);

            render_image.set_output_file_path(output_file_path_str);
            render_image.set_width(width_int);
            render_image.set_height(height_int);
            render_image.set_ssaa(ssaa_int);
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    Color Parser::ParseColor(const Setting &setting)
    {
        unsigned int r, g, b = 0;

        if (setting.lookupValue("r", r) == false)
            throw raytracerExceptions::ParserException("Color r not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("g", g) == false)
            throw raytracerExceptions::ParserException("Color g not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("b", b) == false)
            throw raytracerExceptions::ParserException("Color b not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        if (255 < r || 255 < g || 255 < b)
            throw raytracerExceptions::ParserException("Color values must be between 0 and 255 at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        return Color(r, g, b, 255);
    }

    Point3D Parser::ParsePoint3D(const Setting &setting)
    {
        double x, y, z = 0;

        if (setting.lookupValue("x", x) == false)
            throw raytracerExceptions::ParserException("Point x not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("y", y) == false)
            throw raytracerExceptions::ParserException("Point y not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("z", z) == false)
            throw raytracerExceptions::ParserException("Point z not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        return Point3D(x, y, z);
    }

    TripleDouble Parser::ParseTripleDouble(const Setting &setting)
    {
        double x, y, z = 0;

        if (setting.lookupValue("x", x) == false)
            throw raytracerExceptions::ParserException("TripleDouble x not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("y", y) == false)
            throw raytracerExceptions::ParserException("TripleDouble y not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("z", z) == false)
            throw raytracerExceptions::ParserException("TripleDouble z not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        return TripleDouble(x, y, z);
    }

    Vector3D Parser::ParseVector3D(const Setting &setting)
    {
        double x, y, z = 0;

        if (setting.lookupValue("x", x) == false)
            throw raytracerExceptions::ParserException("Vector3D x not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("y", y) == false)
            throw raytracerExceptions::ParserException("Vector3D y not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("z", z) == false)
            throw raytracerExceptions::ParserException("Vector3D z not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        return Vector3D(x, y, z);
    }

    MaterialCommonParameters Parser::ParseMaterialCommonParameters(const Setting &setting)
    {
        double ambient, diffuse, specular, shininess = 0;

        if (setting.lookupValue("ambient_reflectivity", ambient) == false)
            throw raytracerExceptions::ParserException("Ambient not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("diffuse_reflectivity", diffuse) == false)
            throw raytracerExceptions::ParserException("Diffuse not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("specular_reflectivity", specular) == false)
            throw raytracerExceptions::ParserException("Specular not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (setting.lookupValue("shininess", shininess) == false)
            throw raytracerExceptions::ParserException("Shininess not found in configuration file at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        if (ambient < 0 || 1 < ambient || diffuse < 0 || 1 < diffuse || specular < 0 || 1 < specular)
            throw raytracerExceptions::ParserException("Reflectivity values must be between 0 and 1 at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);
        if (shininess < 0)
            throw raytracerExceptions::ParserException("Shininess must be greater than 0 at line n°" + std::to_string(setting.getSourceLine()), FILE_DATA);

        return MaterialCommonParameters(ambient, diffuse, specular, shininess);
    }

    namespace raytracerExceptions
    {
        ParserException::ParserException(const std::string &additionnal_message, const std::string &file_data) : AException("", additionnal_message, file_data)
        {
            _message = "ParserException: " + _message;
        }
    }
}
