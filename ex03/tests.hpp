#ifndef TESTS_HPP
#define TESTS_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test(const std::string& description, void (*testFunc)());
void testValid();
void testInvalidFormName();

#endif