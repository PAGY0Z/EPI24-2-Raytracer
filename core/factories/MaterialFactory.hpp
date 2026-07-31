/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** MaterialFactory
*/

#ifndef MATERIALFACTORY_HPP_
#define MATERIALFACTORY_HPP_

#include "IMaterial.hpp"
#include "FlatColor.hpp"
#include "ChessBoard.hpp"
#include "AException.hpp"

#include <memory>
#include <functional>
#include <map>

namespace raytracer
{
    class MaterialFactory
    {
    public:
        MaterialFactory();
        ~MaterialFactory() = default;

        std::unique_ptr<IMaterial> CreateMaterial(const std::string &type, const IMaterialFactoryParameters &params);

    private:
        std::map<std::string, std::function<std::unique_ptr<IMaterial>(const IMaterialFactoryParameters &params)>> _material_creators;
    };

    namespace raytracerExceptions
    {
        class MaterialFactoryException : public AException
        {
        public:
            MaterialFactoryException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~MaterialFactoryException() = default;
        };
    }
}

#endif /* !MATERIALFACTORY_HPP_ */
