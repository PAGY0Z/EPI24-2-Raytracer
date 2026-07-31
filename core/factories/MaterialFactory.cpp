/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** MaterialFactory
*/

#include "MaterialFactory.hpp"

namespace raytracer
{
    std::unique_ptr<IMaterial> CreateFlatColor(const IMaterialFactoryParameters &params)
    {
        try {
            auto &flat_color_params = dynamic_cast<const FlatColorFactoryParameters &>(params);
            return std::make_unique<FlatColor>(flat_color_params.color, flat_color_params.ambient_reflectivity, flat_color_params.diffuse_reflectivity, flat_color_params.specular_reflectivity, flat_color_params.shininess);
        } catch (const std::bad_cast &except) {
            throw raytracerExceptions::MaterialFactoryException("Invalid parameters for FlatColor", __FILE__);
        }
    }

    std::unique_ptr<IMaterial> CreateChessBoard(const IMaterialFactoryParameters &params)
    {
        try {
            auto &chess_board_params = dynamic_cast<const ChessBoardFactoryParameters &>(params);
            return std::make_unique<ChessBoard>(chess_board_params.color1, chess_board_params.color2, chess_board_params.block_size, chess_board_params.ambient_reflectivity, chess_board_params.diffuse_reflectivity, chess_board_params.specular_reflectivity, chess_board_params.shininess);
        } catch (const std::bad_cast &except) {
            throw raytracerExceptions::MaterialFactoryException("Invalid parameters for ChessBoard", __FILE__);
        }    
    }

    MaterialFactory::MaterialFactory()
    {
        _material_creators["FlatColor"] = CreateFlatColor;
        _material_creators["ChessBoard"] = CreateChessBoard;
    }

    std::unique_ptr<IMaterial> MaterialFactory::CreateMaterial(const std::string &type, const IMaterialFactoryParameters &params)
    {
        if (_material_creators.find(type) == _material_creators.end())
            throw raytracerExceptions::MaterialFactoryException("Material type \"" + type + "\" not found", __FILE__);
        return _material_creators[type](params);
    }

    namespace raytracerExceptions
    {
        MaterialFactoryException::MaterialFactoryException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "MaterialFactoryException: " + _message;
        }
    }
}