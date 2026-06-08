#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    :
        _name("Default"),
        _signed(false),
        _gradeNeededToSign(80),
        _gradeNeededToExecute(20)
{

}

Form::Form(const std::string& name, bool sign, const int gradeToSign, const int gradeToExecute)
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

Form::~Form()
{

}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getSignedStatus() const
{
    return _signed;
}

int Form::getGradeNeededToSign() const
{
    return _gradeNeededToSign;
}

int Form::getGradeNeededToExecute() const
{
    return _gradeNeededToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeNeededToSign)
        throw GradeTooLowToSignException(bureaucrat.getGrade(), _gradeNeededToSign);
    
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form name: " << form.getName() << RESET
        << "\nSign status:  " << (form.getSignedStatus() ? GREEN : RED)  << (form.getSignedStatus() ? "signed" : "not signed") << RESET
        << "\nGrade needed to sign: " << form.getGradeNeededToSign()
        << "\nGrade needed to execute: " << form.getGradeNeededToExecute() << RESET << ".\n\n";
    return os;
}