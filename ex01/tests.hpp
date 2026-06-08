#ifndef TESTS_HPP
#define TESTS_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(const std::string& description, void (*testFunc)());
void testValid();
void testGradeTooHigh();
void testGradeTooLow();
void testInvalidIncrement();
void testInvalidDecrement();
void testValidIncrement();
void testValidDecrement();
void testInvalidConstructor();

#endif