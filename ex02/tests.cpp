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
        Bureaucrat bur("Mark", 100);
        std::cout << bur;
        ShrubberyCreationForm form("Form 1");
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << PURPLE << "----- CAN be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Bob", 10);
        std::cout << bur;
        RobotomyRequestForm form("Form 2");
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << PURPLE << "----- CAN be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Coco", 5);
        std::cout << bur;
        PresidentialPardonForm form("Form 3");
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testGradeTooLowtoSignAndExecute()
{
        try
    {
        std::cout << PURPLE << "----- CANNOT be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Mark", 147);
        std::cout << bur;
        ShrubberyCreationForm form("Form 1");
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testGradeTooLowtoExecute()
{
        try
    {
        std::cout << PURPLE << "----- CANNOT be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Mark", 140);
        std::cout << bur;
        ShrubberyCreationForm form("Form 1");
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testFormNotSigned()
{
    try
    {
        std::cout << PURPLE << "----- CANNOT be signed and executed ------\n" << RESET ;
        Bureaucrat bur("Mark", 110);
        std::cout << bur;
        ShrubberyCreationForm form("Form 1");
        std::cout << form;
        // form.execute(bur);
        bur.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}