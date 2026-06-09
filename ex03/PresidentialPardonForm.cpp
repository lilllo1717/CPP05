#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :
        AForm("PresidentialPardonForm", false, 25, 5),
        _target("Default")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : 
        AForm("PresidentialPardonForm", false, 25, 5),
        _target(target)
{

}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    :
        AForm(other),
        _target(other._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const 
{
    checksForExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
