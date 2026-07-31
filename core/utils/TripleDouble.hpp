/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-pierre-alexandre.grosset
** File description:
** TripleDouble
*/

#ifndef TRIPLEDOUBLE_HPP_
#define TRIPLEDOUBLE_HPP_

namespace raytracer
{
    class TripleDouble
    {
    public:
        TripleDouble() = default;
        TripleDouble(const double &x, const double &y, const double &z);
        ~TripleDouble() = default;

        double get_x() const;
        double get_y() const;
        double get_z() const;

        void set_x(const double &x);
        void set_y(const double &y);
        void set_z(const double &z);

        TripleDouble operator+(const TripleDouble &triple_double) const;
        TripleDouble operator+=(const TripleDouble &triple_double);
        TripleDouble operator*(const double &value) const;

    private:
        double x = 0;
        double y = 0;
        double z = 0;
    };
}

#endif /* !TRIPLEDOUBLE_HPP_ */
