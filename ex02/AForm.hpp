#ifndef AFORM_HPP
#define AFORM_HPP

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
#include <fstream>


#define RED     "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE  "\033[35m"
#define RESET   "\033[0m"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeNeededToSign;
        const int _gradeNeededToExecute;

    public:
        AForm();
        AForm(const std::string& name, bool sign, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

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
        class GradeTooLowToSignException : public std::exception
        {
            private:
                std::string _message;
            public:
                GradeTooLowToSignException(int grade, int required)
                {
                    _message = "Grade " + std::to_string(grade) + " is too low to sign. Min required grade is " + std::to_string(required) + "\n";
                }
                const char* what() const noexcept
                {
                    return _message.c_str();
                }
        };

        class GradeTooLowToExecuteException : public std::exception
        {
            private:
                std::string _message;
            public:
                GradeTooLowToExecuteException(int grade, int required)
                {
                    _message = "Grade " + std::to_string(grade) + " is too low to execute. Min required grade is " + std::to_string(required) + "\n";
                }
                const char* what() const noexcept
                {
                    return _message.c_str();
                }
        };

        class FormNotSignedException : public std::exception
        {
            private:
                std::string _message;
            public:
                FormNotSignedException()
                {
                    _message = "Form is not signed and cannot be executed.\n";
                }
                const char* what() const noexcept
                {
                    return _message.c_str();
                }
        };

        const std::string& getName() const;
        bool getSignedStatus() const;
        int getGradeNeededToSign() const;
        int getGradeNeededToExecute() const;

        void beSigned(Bureaucrat& bureaucrat);

        virtual void execute(Bureaucrat const & executor) const = 0;
        void checksForExecution(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif