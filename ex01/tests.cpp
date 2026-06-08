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
        std::cout << PURPLE << "----- CAN be signed ------\n" << RESET ;
        std::cout << PURPLE << "Before sign:\n" << RESET ;
        Bureaucrat bur("Mark", 30);
        std::cout << bur;
        Form form("Form 1", false, 80, 10);
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur);
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << PURPLE << "----- CANNOT be signed ------\n" << RESET ;

        std::cout << PURPLE << "Before sign:\n" << RESET ;
        Bureaucrat bur1("Bob", 90);
        std::cout << bur1;
        Form form("Form 1", false, 80, 10);
        std::cout << form;
        std::cout << PURPLE << "After sign:\n" << RESET ;
        form.beSigned(bur1);
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testValidIncrement()
{
    try
    {
        std::cout << PURPLE << "----- CAN be signed ------\n" << RESET ;
        std::cout << PURPLE << "Before trying to sign:\n" << RESET ;
        Bureaucrat bur1("Mark", 82);
        std::cout << bur1;
        Form form("Form 1", false, 80, 10);
        std::cout << form;

        std::cout << PURPLE << "Trying to sign after incrementing:\n" << RESET ;
        bur1.incrementGrade();
        bur1.incrementGrade();
        form.beSigned(bur1);
        std::cout << bur1;
        std::cout << form;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void testInvalidConstructor()
{
    try
    {
        Bureaucrat bur1("Bob", 90);
        std::cout << bur1;
        Form form("Form 1", false, 160, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bur1("Bob", 90);
        std::cout << bur1;
        Form form("Form 1", false, 70, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

void testInvalidDecrement()
{
    try
    {
        std::cout << PURPLE << "Trying to sign before decrementing:\n" << RESET ;
        Bureaucrat bur1("Mark", 80);
        std::cout << bur1;
        Form form("Form 1", false, 80, 10);
        form.beSigned(bur1);
        std::cout << form;

        std::cout << PURPLE << "Trying to sign after decrementing:\n" << RESET ;
        bur1.decrementGrade();
        bur1.decrementGrade();
        form.beSigned(bur1);
        std::cout << bur1;
        std::cout << form;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}