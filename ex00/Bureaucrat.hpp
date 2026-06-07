#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>
#include <charconv>
#include <ostream>

#define RED     "\033[31m"
#define GREEN    "\033[32m"
#define RESET   "\033[0m"


class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept
                {
                    return "Grade is too high.\n";
                }
        };


        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept
                {
                    return "Grade is too low.\n";
                }
        };

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
