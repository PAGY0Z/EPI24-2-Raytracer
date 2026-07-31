/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** AException
*/

#ifndef AEXCEPTION_HPP_
#define AEXCEPTION_HPP_

#include <exception>
#include <string>
#include <iostream>

#define FILE_DATA "In " + std::string(__FILE__) + " at line n°" + std::to_string(__LINE__) + " in function " + std::string(__func__) + "()"

namespace raytracer
{
    class AException : public std::exception
    {
    public:
        AException(const std::string &message, const std::string &additionnal_message, const std::string &file_data);
        virtual ~AException() = default;
        virtual const char *what() const noexcept override;
        int getReturnValue() const noexcept;

    protected:
        std::string _message;

    private:
        const int return_value = 84;
    };

    namespace raytracerExceptions
    {
        class MainException : public AException
        {
        public:
            MainException(const std::string &additionnal_message, const std::string &file_data);
            virtual ~MainException() = default;
        };
    }
}

#endif /* !AEXCEPTION_HPP_ */
