#include "tests.hpp"

void test(const std::string& description, void (*testFunc)())
{
    std::cout << PURPLE << "\n ------- " << description << " ------- \n" << RESET << "\n";
    testFunc();
    std::cout << "\n";
}

void testGradeTooHigh()
{
    try
    {
        Bureaucrat bur("Mark", 0);
        std::cout << bur;
    }
    catch (const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    try
    {
        Bureaucrat bur1("Mark", -1);
        std::cout << bur1;
    }
    catch (const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
}

void testGradeTooLow()
{
    try
    {
        Bureaucrat bur("Mark", 151);
        std::cout << bur;
    }
    catch (const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    try
    {
        Bureaucrat bur1("Mark", 160);
        std::cout << bur1;
    }
    catch (const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    try
    {
        Bureaucrat bur("Mark", 'w' + 70);
        std::cout << bur;
    }
    catch (const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    
}

void testInvalidIncrement()
{
    try
    {
        Bureaucrat bur("Mark", 2);
        bur.incrementGrade();
        bur.incrementGrade();
        std::cout << bur;
    }
    catch(const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    
}


void testInvalidDecrement()
{
    try
    {
        Bureaucrat bur("Mark", 150);
        bur.decrementGrade();
        bur.decrementGrade();
        std::cout << bur;
    }
    catch(const std::exception& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    
}

void testValid()
{
    try
    {
        Bureaucrat bur;
        std::cout << bur;
        Bureaucrat bur1("Sam", 120);
        std::cout << bur1;
        Bureaucrat bur2("Coco", 55);
        std::cout << bur2;
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
        Bureaucrat bur;
        std::cout << bur;

        Bureaucrat bur1("Sam", 120);
        std::cout << "Before increment: "<< bur1;
        bur1.incrementGrade();
        bur1.incrementGrade();
        std::cout << "After increment: "<< bur1;


        Bureaucrat bur2("Coco", 55);
        std::cout << "Before increment: " << bur2;
        for (size_t i = 0; i < 10; i++)
            bur2.incrementGrade();
        std::cout << "After increment: "<< bur2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testValidDecrement()
{
    try
    {
        Bureaucrat bur;
        std::cout << bur;

        Bureaucrat bur1("Sam", 120);
        std::cout << "Before increment: "<< bur1;
        bur1.decrementGrade();
        bur1.decrementGrade();
        std::cout << "After increment: "<< bur1;


        Bureaucrat bur2("Coco", 55);
        std::cout << "Before increment: " << bur2;
        for (size_t i = 0; i < 10; i++)
            bur2.decrementGrade();
        std::cout << "After increment: "<< bur2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}