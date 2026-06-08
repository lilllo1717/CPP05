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
#include "Form.hpp"

#define RED     "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE  "\033[35m"
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
            private:
                std::string _message;
            public:
                GradeTooHighException(int grade)
                {
                    _message = "Grade " + std::to_string(grade) + " is too high. Highest grade is 1.\n";
                }
                const char* what() const noexcept
                {
                    return _message.c_str();
                }
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string _message;
            public:
                GradeTooLowException(int grade)
                {
                    _message = "Grade " + std::to_string(grade) + " is too low. Lowest grade is 150.\n";
                }
                const char* what() const noexcept
                {
                    return _message.c_str();
                }
        };

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(Form& form);


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
