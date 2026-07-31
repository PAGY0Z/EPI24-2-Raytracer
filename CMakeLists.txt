cmake_minimum_required(VERSION 3.17)

set(NAME raytracer)
project(${NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CORE_SRC
    core/default/AException.cpp
    core/default/AException.hpp
    core/factories/LightFactory.cpp
    core/factories/LightFactory.hpp
    core/factories/MaterialFactory.cpp
    core/factories/MaterialFactory.hpp
    core/factories/PrimitiveFactory.cpp
    core/factories/PrimitiveFactory.hpp
    core/lights/Directionnal.cpp
    core/lights/Directionnal.hpp
    core/lights/ILight.hpp
    core/lights/Point.cpp
    core/lights/Point.hpp
    core/materials/ChessBoard.cpp
    core/materials/ChessBoard.hpp
    core/materials/FlatColor.cpp
    core/materials/FlatColor.hpp
    core/materials/IMaterial.hpp
    core/parsing/Parser.cpp
    core/parsing/Parser.hpp
    core/parsing/ParserLights.cpp
    core/parsing/ParserMaterials.cpp
    core/parsing/ParserPrimitives.cpp
    core/primitives/Cone.cpp
    core/primitives/Cone.hpp
    core/primitives/Cube.cpp
    core/primitives/Cube.hpp
    core/primitives/Cylinder.cpp
    core/primitives/Cylinder.hpp
    core/primitives/IPrimitive.hpp
    core/primitives/Plane.cpp
    core/primitives/Plane.hpp
    core/primitives/Sphere.cpp
    core/primitives/Sphere.hpp
    core/primitives/Triangle.cpp
    core/primitives/Triangle.hpp
    core/rendering/Renderer.cpp
    core/rendering/Renderer.hpp
    core/rendering/RenderImage.cpp
    core/rendering/RenderImage.hpp
    core/scene/Scene.cpp
    core/scene/Scene.hpp
    core/utils/Color.cpp
    core/utils/Color.hpp
    core/utils/Point3D.cpp
    core/utils/Point3D.hpp
    core/utils/Ray.cpp
    core/utils/Ray.hpp
    core/utils/TripleDouble.cpp
    core/utils/TripleDouble.hpp
    core/utils/Vector3D.cpp
    core/utils/Vector3D.hpp
    core/Camera.cpp
    core/Camera.hpp
    core/Raytracer.cpp
    core/Raytracer.hpp
    main.cpp
)

set(INCLUDE_DIR
    core/default
    core/factories
    core/lights
    core/materials
    core/parsing
    core/primitives
    core/rendering
    core/scene
    core/utils
    core
)

add_executable(${NAME} ${CORE_SRC})

add_compile_options()

include(FetchContent)

FetchContent_Declare(
    libconfig_dep
    GIT_REPOSITORY https://github.com/hyperrealm/libconfig.git
    GIT_TAG        v1.8.1
)

FetchContent_MakeAvailable(libconfig_dep)

target_link_libraries(${NAME} PUBLIC libconfig++ libconfig)

install(TARGETS libconfig++ libconfig
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}
)

if(WIN32)
    add_custom_command(TARGET ${NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:libconfig++>
            $<TARGET_FILE:libconfig>
            $<TARGET_FILE_DIR:${NAME}>
    )
endif()

target_include_directories(${NAME} PUBLIC ${INCLUDE_DIR})
