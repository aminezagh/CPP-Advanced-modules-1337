#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private :
        std::string Target;
    public :

//---------------------Construcotrs And Destructors---------------------//
        PresidentialPardonForm();
        PresidentialPardonForm(std::string N);
        PresidentialPardonForm(PresidentialPardonForm &obj);
        ~PresidentialPardonForm();

//-------------------------------Getters-------------------------------//
        std::string GetTarget() const;

//---------------------------Membre function---------------------------//
        void    execute(Bureaucrat const &obj) const;

//------------------------Exceptions functions------------------------//
        // class   FormNotSigned : public std::exception
        // {
        //     public :
        //         virtual const char *what() const throw();
        // };
        
        // class   GradeDontPermit : public std::exception
        // {
        //     public :
        //         virtual const char *what() const throw();
        // };

//-----------------------operators assignement-----------------------//
        PresidentialPardonForm &operator=(PresidentialPardonForm &obj);
};

#endif