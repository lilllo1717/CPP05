#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"

int main(void)
{
    test("Valid tests: ", testValid);
    test("Invalid form name test: ", testInvalidFormName);

    return 0;
}