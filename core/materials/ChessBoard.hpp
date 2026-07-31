/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** ChessBoard
*/

#ifndef CHESSBOARD_HPP_
#define CHESSBOARD_HPP_

#include "IMaterial.hpp"

namespace raytracer
{
    class ChessBoardFactoryParameters : public IMaterialFactoryParameters
    {
    public:
        ChessBoardFactoryParameters(const Color &color1, const Color &color2, double block_size, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess)
            : color1(color1), color2(color2), block_size(block_size), ambient_reflectivity(ambient_reflectivity), diffuse_reflectivity(diffuse_reflectivity), specular_reflectivity(specular_reflectivity), shininess(shininess) {}
        ~ChessBoardFactoryParameters() = default;

        Color color1;
        Color color2;
        double block_size;
        double ambient_reflectivity;
        double diffuse_reflectivity;
        double specular_reflectivity;
        double shininess;
    };

    class ChessBoard : public IMaterial
    {
    public:
        ChessBoard(const Color &color1, const Color &color2, double block_size, double ambient_reflectivity, double diffuse_reflectivity, double specular_reflectivity, double shininess);
        ~ChessBoard() = default;

        Color GetColor(Point3D &intersection) const override;
        double GetAmbientReflectivity() const override;
        double GetDiffuseReflectivity() const override;
        double GetSpecularReflectivity() const override;
        double GetShininess() const override;

    private:
        Color _color1;
        Color _color2;
        double block_size;
        double _ambient_reflectivity;
        double _diffuse_reflectivity;
        double _specular_reflectivity;
        double _shininess;
    };
}

#endif /* !CHESSBOARD_HPP_ */
