/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "AException.hpp"
#include "Scene.hpp"
#include "RenderImage.hpp"
#include "Camera.hpp"
#include <libconfig.h++>
#include <map>

#include "MaterialFactory.hpp"
#include "PrimitiveFactory.hpp"
#include "LightFactory.hpp"

namespace raytracer
{
    using namespace libconfig;

    class MaterialCommonParameters
    {
    public:
        MaterialCommonParameters(const double &ambient, const double &diffuse, const double &specular, const double &shininess) : ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {}
        MaterialCommonParameters() : ambient(0), diffuse(0), specular(0), shininess(0) {}
        ~MaterialCommonParameters() = default;

        double ambient;
        double diffuse;
        double specular;
        double shininess;
    };

    class Parser
    {
    public:
        Parser(const std::string &config_file_path);
        ~Parser() = default;

        void ParsePrimitives(Scene &scene);
        void ParseMaterials();
        void ParseLights(Scene &scene);
        void ParseRenderImage(RenderImage &render_image);
        void ParseCamera(Camera &camera);

    private:
        MaterialFactory _material_factory;
        PrimitiveFactory _primitive_factory;
        LightFactory _light_factory;

        const std::string &_config_file_path;
        Config _cfg;
        std::map<std::string, std::unique_ptr<IMaterial>> _materials;

        void ParseChessBoard(const Setting &setting);
        void ParseFlatColor(const Setting &setting);

        void ParseSphere(const Setting &setting, Scene &scene);
        void ParsePlane(const Setting &setting, Scene &scene);
        void ParseCone(const Setting &setting, Scene &scene);
        void ParseCylinder(const Setting &setting, Scene &scene);
        void ParseCube(const Setting &setting, Scene &scene);
        void ParseTriangle(const Setting &setting, Scene &scene);

        void ParsePoint(const Setting &setting, Scene &scene);
        void ParseDirectional(const Setting &setting, Scene &scene);

        Color ParseColor(const Setting &setting);
        Point3D ParsePoint3D(const Setting &setting);
        TripleDouble ParseTripleDouble(const Setting &setting);
        Vector3D ParseVector3D(const Setting &setting);
        MaterialCommonParameters ParseMaterialCommonParameters(const Setting &setting);
    };

    namespace raytracerExceptions
    {
        class ParserException : public AException
        {
        public:
            ParserException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~ParserException() = default;
        };
    }
}

#endif /* !PARSER_HPP_ */
