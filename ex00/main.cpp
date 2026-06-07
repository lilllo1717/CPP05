#include "Bureaucrat.hpp"


int main(void)
{
    try
    {
        Bureaucrat bur1("Mark", 120);
        std::cout << bur1;
        Bureaucrat bur2("Mark", 160);
        std::cout << bur2;

    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << RED <<  e.what() << RESET << "\n";
    }
}