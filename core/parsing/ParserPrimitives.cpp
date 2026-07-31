/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ParserPrimitives
*/

#include "Parser.hpp"

namespace raytracer
{
    void Parser::ParsePrimitives(Scene &scene)
    {
        try
        {
            const libconfig::Setting &rootSetting = _cfg.getRoot();
            const libconfig::Setting &sceneSetting = rootSetting["scene"];
            const libconfig::Setting &primitivesSetting = sceneSetting["primitives"];

            int primitive_count = primitivesSetting.getLength();

            for (int i = 0; i < primitive_count; i++)
            {
                const libconfig::Setting &primitiveSetting = primitivesSetting[i];
                std::string primitive_type = "";

                if (primitiveSetting.lookupValue("type", primitive_type) == false)
                    throw raytracerExceptions::ParserException("Primitive type not found in configuration file", FILE_DATA);

                if (primitive_type == "Sphere")
                    ParseSphere(primitiveSetting, scene);
                else if (primitive_type == "Plane")
                    ParsePlane(primitiveSetting, scene);
                else if (primitive_type == "Cone")
                    ParseCone(primitiveSetting, scene);
                else if (primitive_type == "Cylinder")
                    ParseCylinder(primitiveSetting, scene);
                else if (primitive_type == "Cube")
                    ParseCube(primitiveSetting, scene);
                else if (primitive_type == "Triangle")
                    ParseTriangle(primitiveSetting, scene);
                else
                    throw raytracerExceptions::ParserException("Primitive type not recognized", FILE_DATA);
            }
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseSphere(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &positionSetting = primitiveSetting["position"];
            std::string material_name = "";
            double radius = 0;

            Point3D position = ParsePoint3D(positionSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("radius", radius) == false)
                throw raytracerExceptions::ParserException("Radius not found in configuration file", FILE_DATA);

            if (radius <= 0)
                throw raytracerExceptions::ParserException("Radius must be greater than 0", FILE_DATA);
            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            SphereFactoryParameters params(position, radius, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Sphere", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParsePlane(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &positionSetting = primitiveSetting["position"];
            const libconfig::Setting &normalSetting = primitiveSetting["normal"];
            std::string material_name = "";

            Point3D position = ParsePoint3D(positionSetting);
            Vector3D normal = ParseVector3D(normalSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);

            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            PlaneFactoryParameters params(position, normal, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Plane", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseCone(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &baseCenterSetting = primitiveSetting["base_center"];
            const libconfig::Setting &rotationSetting = primitiveSetting["rotation"];
            std::string material_name = "";
            double radius = 0;
            double height = 0;

            Point3D baseCenter = ParsePoint3D(baseCenterSetting);
            TripleDouble rotation = ParseTripleDouble(rotationSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("height", height) == false)
                throw raytracerExceptions::ParserException("Height not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("radius", radius) == false)
                throw raytracerExceptions::ParserException("Radius not found in configuration file", FILE_DATA);

            if (radius <= 0)
                throw raytracerExceptions::ParserException("Radius must be greater than 0", FILE_DATA);
            if (height <= 0)
                throw raytracerExceptions::ParserException("Height must be greater than 0", FILE_DATA);
            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            ConeFactoryParameters params(baseCenter, height, radius, rotation, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Cone", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseCylinder(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &centerSetting = primitiveSetting["base_center"];
            const libconfig::Setting &rotationSetting = primitiveSetting["rotation"];
            std::string material_name = "";
            double radius = 0;
            double height = 0;

            Point3D center = ParsePoint3D(centerSetting);
            TripleDouble rotation = ParseTripleDouble(rotationSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("height", height) == false)
                throw raytracerExceptions::ParserException("Height not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("radius", radius) == false)
                throw raytracerExceptions::ParserException("Radius not found in configuration file", FILE_DATA);

            if (radius <= 0)
                throw raytracerExceptions::ParserException("Radius must be greater than 0", FILE_DATA);
            if (height <= 0)
                throw raytracerExceptions::ParserException("Height must be greater than 0", FILE_DATA);
            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            CylinderFactoryParameters params(center, radius, height, rotation, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Cylinder", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseCube(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &centerSetting = primitiveSetting["center"];
            const libconfig::Setting &rotationSetting = primitiveSetting["rotation"];
            std::string material_name = "";
            double size = 0;

            Point3D center = ParsePoint3D(centerSetting);
            TripleDouble rotation = ParseTripleDouble(rotationSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);
            if (primitiveSetting.lookupValue("size", size) == false)
                throw raytracerExceptions::ParserException("Size not found in configuration file", FILE_DATA);

            if (size <= 0)
                throw raytracerExceptions::ParserException("Size must be greater than 0", FILE_DATA);
            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            CubeFactoryParameters params(center, size, rotation, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Cube", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseTriangle(const Setting &primitiveSetting, Scene &scene)
    {
        try
        {
            const libconfig::Setting &point1Setting = primitiveSetting["point1"];
            const libconfig::Setting &point2Setting = primitiveSetting["point2"];
            const libconfig::Setting &point3Setting = primitiveSetting["point3"];
            const libconfig::Setting &rotationSetting = primitiveSetting["rotation"];
            std::string material_name = "";

            Point3D point1 = ParsePoint3D(point1Setting);
            Point3D point2 = ParsePoint3D(point2Setting);
            Point3D point3 = ParsePoint3D(point3Setting);
            TripleDouble rotation = ParseTripleDouble(rotationSetting);

            if (primitiveSetting.lookupValue("material", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);

            if (_materials.find(material_name) == _materials.end())
                throw raytracerExceptions::ParserException("Material name not found", FILE_DATA);

            const IMaterial *material = _materials[material_name].get();
            TriangleFactoryParameters params(point1, point2, point3, rotation, *material);
            std::unique_ptr<IPrimitive> primitive = _primitive_factory.CreatePrimitive("Triangle", params);
            scene.add_primitive(std::move(primitive));
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }
}
