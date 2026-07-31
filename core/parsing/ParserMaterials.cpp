/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ParserMaterials
*/

#include "Parser.hpp"

namespace raytracer
{
    void Parser::ParseMaterials()
    {
        try
        {
            const libconfig::Setting &rootSetting = _cfg.getRoot();
            const libconfig::Setting &sceneSetting = rootSetting["scene"];
            const libconfig::Setting &materialsSetting = sceneSetting["materials"];

            int material_count = materialsSetting.getLength();

            for (int i = 0; i < material_count; i++)
            {
                const libconfig::Setting &materialSetting = materialsSetting[i];
                std::string material_type = "";

                if (materialSetting.lookupValue("type", material_type) == false)
                    throw raytracerExceptions::ParserException("Material type not found in configuration file", FILE_DATA);

                if (material_type == "ChessBoard")
                    ParseChessBoard(materialSetting);
                else if (material_type == "FlatColor")
                    ParseFlatColor(materialSetting);
                else
                    throw raytracerExceptions::ParserException("Material type not recognized", FILE_DATA);
            }
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseChessBoard(const Setting &materialSetting)
    {
        try
        {
            const libconfig::Setting &color1Setting = materialSetting["color1"];
            const libconfig::Setting &color2Setting = materialSetting["color2"];
            std::string material_name = "";
            double block_size = 0;

            if (materialSetting.lookupValue("name", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);

            Color color1 = ParseColor(color1Setting);
            Color color2 = ParseColor(color2Setting);
            MaterialCommonParameters commonParams = ParseMaterialCommonParameters(materialSetting);

            if (materialSetting.lookupValue("block_size", block_size) == false)
                throw raytracerExceptions::ParserException("Block size not found in configuration file", FILE_DATA);

            if (block_size <= 0)
                throw raytracerExceptions::ParserException("Block size must be greater than 0", FILE_DATA);

            ChessBoardFactoryParameters params(color1, color2, block_size, commonParams.ambient, commonParams.diffuse, commonParams.specular, commonParams.shininess);
            std::unique_ptr<IMaterial> material = _material_factory.CreateMaterial("ChessBoard", params);
            if (_materials.find(material_name) != _materials.end())
                throw raytracerExceptions::ParserException("Material name already exists", FILE_DATA);
            _materials[material_name] = std::move(material);
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }

    void Parser::ParseFlatColor(const Setting &materialSetting)
    {
        try
        {
            const libconfig::Setting &colorSetting = materialSetting["color"];
            std::string material_name = "";

            Color color = ParseColor(colorSetting);
            MaterialCommonParameters commonParams = ParseMaterialCommonParameters(materialSetting);

            if (materialSetting.lookupValue("name", material_name) == false)
                throw raytracerExceptions::ParserException("Material name not found in configuration file", FILE_DATA);

            FlatColorFactoryParameters params(color, commonParams.ambient, commonParams.diffuse, commonParams.specular, commonParams.shininess);
            std::unique_ptr<IMaterial> material = _material_factory.CreateMaterial("FlatColor", params);
            if (_materials.find(material_name) != _materials.end())
                throw raytracerExceptions::ParserException("Material name already exists", FILE_DATA);
            _materials[material_name] = std::move(material);
        }
        catch (const libconfig::SettingNotFoundException &except)
        {
            throw raytracerExceptions::ParserException("Setting not found in configuration file : " + std::string(except.what()), FILE_DATA);
        }
    }
}
