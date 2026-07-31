/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** AException
*/

#include "AException.hpp"

namespace raytracer
{
    AException::AException(const std::string &message, const std::string &additionnal_message = "", const std::string &file_data = "") : _message(message)
    {
        _message += (!additionnal_message.empty()) ? additionnal_message : "";
        _message += (!file_data.empty()) ? "\n>>> " + file_data : "";
    }

    const char *AException::what() const noexcept
    {
        return _message.c_str();
    }

    int AException::getReturnValue() const noexcept
    {
        return return_value;
    }

    namespace raytracerExceptions
    {
        MainException::MainException(const std::string &additionnal_message = "", const std::string &file_data = "") : AException("", additionnal_message, file_data)
        {
            _message = "MainException: " + _message;
        }
    }
}
