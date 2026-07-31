/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** PrimitiveFactory
*/

#include "PrimitiveFactory.hpp"

namespace raytracer
{
    std::unique_ptr<IPrimitive> CreateSphere(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const SphereFactoryParameters &sphere_params = dynamic_cast<const SphereFactoryParameters &>(params);
            return std::make_unique<Sphere>(sphere_params.center, sphere_params.radius, sphere_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Sphere", __FILE__);
        }
    }

    std::unique_ptr<IPrimitive> CreatePlane(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const PlaneFactoryParameters &plane_params = dynamic_cast<const PlaneFactoryParameters &>(params);
            return std::make_unique<Plane>(plane_params.point, plane_params.normal, plane_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Plane", __FILE__);
        }
    }

    std::unique_ptr<IPrimitive> CreateCone(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const ConeFactoryParameters &cone_params = dynamic_cast<const ConeFactoryParameters &>(params);
            return std::make_unique<Cone>(cone_params.base_center, cone_params.height, cone_params.radius, cone_params.rotation, cone_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Cone", __FILE__);
        }
    }

    std::unique_ptr<IPrimitive> CreateCylinder(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const CylinderFactoryParameters &cylinder_params = dynamic_cast<const CylinderFactoryParameters &>(params);
            return std::make_unique<Cylinder>(cylinder_params.center, cylinder_params.radius, cylinder_params.height, cylinder_params.rotation, cylinder_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Cylinder", __FILE__);
        }
    }

    std::unique_ptr<IPrimitive> CreateCube(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const CubeFactoryParameters &cube_params = dynamic_cast<const CubeFactoryParameters &>(params);
            return std::make_unique<Cube>(cube_params.center, cube_params.size, cube_params.rotation, cube_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Cube", __FILE__);
        }
    }

    std::unique_ptr<IPrimitive> CreateTriangle(const IPrimitiveFactoryParameters &params)
    {
        try
        {
            const TriangleFactoryParameters &triangle_params = dynamic_cast<const TriangleFactoryParameters &>(params);
            return std::make_unique<Triangle>(triangle_params.point1, triangle_params.point2, triangle_params.point3, triangle_params.rotation, triangle_params.material);
        }
        catch (std::bad_cast &except)
        {
            throw raytracerExceptions::PrimitiveFactoryException("Invalid parameters for Triangle", __FILE__);
        }
    }

    PrimitiveFactory::PrimitiveFactory()
    {
        _primitive_creators["Sphere"] = CreateSphere;
        _primitive_creators["Plane"] = CreatePlane;
        _primitive_creators["Cone"] = CreateCone;
        _primitive_creators["Cylinder"] = CreateCylinder;
        _primitive_creators["Cube"] = CreateCube;
        _primitive_creators["Triangle"] = CreateTriangle;
    }

    std::unique_ptr<IPrimitive> PrimitiveFactory::CreatePrimitive(const std::string &type, const IPrimitiveFactoryParameters &params)
    {
        if (_primitive_creators.find(type) == _primitive_creators.end())
            throw raytracerExceptions::PrimitiveFactoryException("Primitive type \"" + type + "\" not found", __FILE__);
        return _primitive_creators[type](params);
    }

    namespace raytracerExceptions
    {
        PrimitiveFactoryException::PrimitiveFactoryException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "PrimitiveFactoryException: " + _message;
        }
    }
}
