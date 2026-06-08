#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : 
        _name("Peter"),
        _grade(150)
{
    // std::cout << "Default constructor called." << "\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :
        _name(name),
        _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException(grade);
    if (grade > 150)
        throw GradeTooLowException(grade);
    // std::cout << "Constructor called." << "\n";
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Destructor called." << "\n";
}

const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException(_grade + 1);
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET << ".\n";
    return os;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << _name << " signed " << form.getName() << "\n.";
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << "\n";
    }
    
}