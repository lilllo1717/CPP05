#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
    };

    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern cannot create the form. Form name  '" << formName << "' is unknown.\n" ;
    return nullptr;
}