#include "Bureaucrat.hpp"
#include "tests.hpp"

int main(void)
{
    test("Valid tests", testValid);
    test("Valid increment", testValidIncrement);
    test("Valid decrement", testValidDecrement);
    test("Grade too high", testGradeTooHigh);
    test("Grade too low", testGradeTooLow);
    test("Invalid increment", testInvalidIncrement);
    test("Invalid decrement", testInvalidDecrement);

    return 0;
}