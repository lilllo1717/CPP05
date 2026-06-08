#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

int main(void)
{
    test("Valid tests: ", testValid);
    test("Valid increment test", testValidIncrement);
    test("Invalid Form constructor", testInvalidConstructor);
    test("Invalid decrement test", testInvalidDecrement);


    return 0;
}