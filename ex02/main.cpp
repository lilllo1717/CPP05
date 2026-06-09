#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"

int main(void)
{
    test("Valid tests: ", testValid);
    test("Grade too low to sign and execute: ", testGradeTooLowtoSignAndExecute);
    test("Grade too low to execute: ", testGradeTooLowtoExecute);
    test("Form not signed: ", testFormNotSigned);

    return 0;
}