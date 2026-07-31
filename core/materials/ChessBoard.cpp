/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ChessBoard
*/

#include "ChessBoard.hpp"

namespace raytracer
{
    ChessBoard::ChessBoard(const Color &color1, const Color &color2, double block_size, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess)
        : _color1(color1), _color2(color2), block_size(block_size), _ambient_reflectivity(ambient_reflectivity), _diffuse_reflectivity(diffuse_reflectivity), _specular_reflectivity(specular_reflectivity), _shininess(shininess)
    {
    }

    Color ChessBoard::GetColor(Point3D &intersection) const
    {
        int block_x = static_cast<int>(std::floor((intersection.get_x() / block_size) + 0.5));
        int block_y = static_cast<int>(std::floor((intersection.get_y() / block_size) + 0.5));
        int block_z = static_cast<int>(std::floor((intersection.get_z() / block_size) + 0.5));

        int sum = block_x + block_y + block_z;

        if (sum % 2 == 0)
            return _color1;
        return _color2;
    }

    double ChessBoard::GetAmbientReflectivity() const
    {
        return _ambient_reflectivity;
    }

    double ChessBoard::GetDiffuseReflectivity() const
    {
        return _diffuse_reflectivity;
    }

    double ChessBoard::GetSpecularReflectivity() const
    {
        return _specular_reflectivity;
    }

    double ChessBoard::GetShininess() const
    {
        return _shininess;
    }
}
