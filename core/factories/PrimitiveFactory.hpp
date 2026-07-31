/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
#define PRIMITIVEFACTORY_HPP_

#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "Cube.hpp"
#include "Triangle.hpp"
#include "AException.hpp"

#include <memory>
#include <functional>
#include <map>

namespace raytracer
{
    class PrimitiveFactory
    {
    public:
        PrimitiveFactory();
        ~PrimitiveFactory() = default;

        std::unique_ptr<IPrimitive> CreatePrimitive(const std::string &type, const IPrimitiveFactoryParameters &params);

    private:
        std::map<std::string, std::function<std::unique_ptr<IPrimitive>(const IPrimitiveFactoryParameters &params)>> _primitive_creators;
    };

    namespace raytracerExceptions
    {
        class PrimitiveFactoryException : public AException
        {
        public:
            PrimitiveFactoryException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~PrimitiveFactoryException() = default;
        };
    }
}

#endif /* !PRIMITIVEFACTORY_HPP_ */
