#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    :
        _name("Default"),
        _signed(false),
        _gradeNeededToSign(80),
        _gradeNeededToExecute(20)
{

}

AForm::AForm(const std::string& name, bool sign, const int gradeToSign, const int gradeToExecute)
    :
        _name(name),
        _signed(sign),
        _gradeNeededToSign(gradeToSign),
        _gradeNeededToExecute(gradeToExecute)
{
    if (gradeToSign > 150)
        throw GradeTooLowException(gradeToSign);
    if (gradeToSign < 1)
        throw GradeTooHighException(gradeToSign);
    if (gradeToExecute > 150)
        throw GradeTooLowException(gradeToSign);
    if (gradeToExecute < 1)
        throw GradeTooHighException(gradeToSign);

}

AForm::AForm(const AForm& other)
    :
        _name(other._name),
        _signed(other._signed),
        _gradeNeededToSign(other._gradeNeededToSign),
        _gradeNeededToExecute(other._gradeNeededToExecute)
{

}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{

}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getSignedStatus() const
{
    return _signed;
}

int AForm::getGradeNeededToSign() const
{
    return _gradeNeededToSign;
}

int AForm::getGradeNeededToExecute() const
{
    return _gradeNeededToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeNeededToSign)
        throw GradeTooLowToSignException(bureaucrat.getGrade(), _gradeNeededToSign);
    
    _signed = true;
}

void AForm::checksForExecution(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeNeededToExecute)
        throw GradeTooLowToExecuteException(executor.getGrade(), _gradeNeededToExecute);
    std::cout << GREEN << "Form can be executed.\n" << RESET;
}


std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form name: " << form.getName() << RESET
        << "\nSign status:  " << (form.getSignedStatus() ? GREEN : RED)  << (form.getSignedStatus() ? "signed" : "not signed") << RESET
        << "\nGrade needed to sign: " << form.getGradeNeededToSign()
        << "\nGrade needed to execute: " << form.getGradeNeededToExecute() << RESET << ".\n\n";
    return os;
}

