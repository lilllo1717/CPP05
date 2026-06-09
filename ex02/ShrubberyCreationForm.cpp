#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    :
        AForm("ShrubberyCreationForm", false, 145, 137),
        _target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : 
        AForm("ShrubberyCreationForm", false, 145, 137),
        _target(target)
{

}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    :
        AForm(other),
        _target(other._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const 
{
    checksForExecution(executor);
    std::ofstream outFile(_target + "_shrubbery.txt");
    outFile << R"(
                  \_/
                --(_)--
            .'.   / \
           / . \
          |  |. | ,-'-.
     ,-'-.\ \|  /(  .  )
    /  .  \  |, (  \|   )
   |  .|/  |_|_(    |/   )
    \._|,_/  |  '--.|..-'
 ______|_____|______|______ 

)";

    outFile << R"(

                                   .         ;
      .              .              ;%     ;;
        ,           ,                :;%  %;
         :         ;                   :;%;'     .,
,.        %;     %;            ;        %;'    ,;
  ;       ;%;  %%;        ,     %;    ;%;    ,%'
   %;       %;%;      ,  ;       %;  ;%;   ,%;'
    ;%;      %;        ;%;        % ;%;  ,%;'
     `%;.     ;%;     %;'         `;%%;.%;'
      `:;%.    ;%%. %@;        %; ;@%;%'
         `:%;.  :;bd%;          %;@%;'
           `@%:.  :;%.         ;@@%;'
             `@%.  `;@%.      ;@@%;
               `@%%. `@%%    ;@@%;
                 ;@%. :@%%  %@@%;
                   %@bd%%%bd%%:;
                     #@%%%%%:;;
                     %@@%%%::;
                     %@@@%(o);  . '
                     %@@@o%;:(.,'
                 `.. %@@@o%::;
                    `)@@@o%::;
                     %@@(o)::;
                    .%@@@@%::;
                    ;%@@@@%::;.
                   ;%@@@@%%:;;;.
               ...;%@@@@@%%:;;;;,..    
------------------------------------------------

    )";

}