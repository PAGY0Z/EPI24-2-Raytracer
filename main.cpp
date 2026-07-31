/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** main
*/

#include "AException.hpp"
#include "Raytracer.hpp"
#include <string>
#include <iostream>

#define USAGE "USAGE\n\t./raytracer ('-h' || path/to/file/scene.cfg)\n\nDESCRIPTION\n\tThis program is a raytracer that takes a scene file as argument and generates a ppm file."

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw raytracer::raytracerExceptions::MainException("Invalid arguments number\n" + std::string(USAGE), FILE_DATA);
        if (std::string(argv[1]) == "-h")
        {
            std::cout << USAGE << std::endl;
            return 0;
        }
        if (std::string(argv[1]).substr(std::string(argv[1]).find_last_of(".") + 1) != "cfg")
            throw raytracer::raytracerExceptions::MainException("Invalid file extension '" + std::string(argv[1]) + "'\n" + std::string(USAGE), FILE_DATA);
        return raytracer::Raytracer(std::string(argv[1])).render();
    }
    catch (const raytracer::AException &except)
    {
        std::cerr << except.what() << std::endl;
        return except.getReturnValue();
    }
}
