#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :
        AForm("RobotomyRequestForm", false, 72, 45),
        _target("Default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : 
        AForm("RobotomyRequestForm", false, 72, 45),
        _target(target)
{

}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :
        AForm(other),
        _target(other._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const 
{
    checksForExecution(executor);
    std::cout << "DRILLLLLINNNGGGG BZZZZZZZ....\n";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully.\n";
    else
        std::cout << "Failed to robotomize " << _target << ".\n";
}