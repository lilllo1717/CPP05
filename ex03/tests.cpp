#include "tests.hpp"

void test(const std::string& description, void (*testFunc)())
{
    std::cout << PURPLE << "\n ------- " << description << " ------- \n" << RESET << "\n";
    testFunc();
    std::cout << "\n";
}


void testValid()
{
    try
    {
        std::cout << PURPLE << "----- CAN be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Mark", 10);
        std::cout << bur;
        Intern intern;
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Alice");
        std::cout << *form1;
        std::cout << *form2;
        std::cout << *form3;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testInvalidFormName()
{
    try
    {
        std::cout << PURPLE << "----- CANNOT create form with invalid name ------\n" << RESET ;
        Intern intern;
        AForm* form = intern.makeForm("invalid form name", "target");
        if (form == nullptr)
            std::cout << "Form creation failed as expected.\n";
        else
            std::cout << "Unexpectedly created a form: " << *form << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}