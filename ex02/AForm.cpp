/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:41:33 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:16 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

//--------------------Construcotrs And Destructors--------------------//

AForm::AForm() : name("default"), GradeToSign(1), GradeToExecute(1)
{
    signd = false;
}

AForm::AForm(std::string N, int Gs, int Ge) : name(N), GradeToSign(Gs), GradeToExecute(Ge)
{
    this->signd = false;
    if (this->GradeToExecute > 150 || this->GradeToSign > 150)
        throw(GradeTooHighException());
    if (this->GradeToExecute < 1 || this->GradeToSign < 1)
        throw(GradeTooLowException());
}

AForm::AForm(AForm &obj) : name(obj.name), GradeToSign(obj.GradeToSign), GradeToExecute(obj.GradeToExecute)
{
    *this = obj;
}

AForm::~AForm()
{
}

//-------------------------------Getters-------------------------------//

bool        AForm::GetSignBoolean() const
{
    return (this->signd);
}

int         AForm::GetSignGrade() const
{
    return (this->GradeToSign);
}

int         AForm::GetExecuteGrade() const
{
    return (this->GradeToExecute);
}

std::string AForm::GetName() const
{
    return (this->name);
}

//--------------------------Membre function--------------------------//

void    AForm::beSigned(Bureaucrat &obj)
{
    if (this->GetSignGrade() <= obj.getGrade()) // this mean that the grade of the Aform is greater and higher that the grade of the bureaucrate
        this->signd = true;
}

//-------------------------Exceptions functions-------------------------//

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("It seems that you entered a grade higher than the bounds");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("It seems that you entered a grade lower than the bounds");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("An error appearse, it seems that the form isn't signed");
}

const char *AForm::GradeDontPermit::what() const throw()
{
    return ("An error appearse, it seems that the grade of the bureaucrat dont permit to sing the form");
}

//---------------------operators assignement---------------------//

AForm &AForm::operator=(AForm &obj)
{
    this->signd = obj.signd;
    return *this;
}

std::ostream & operator<<( std::ostream & o, const AForm & rhs)
{
    std::string TF;
    if (rhs.GetSignBoolean())
        TF = "True";
    else
        TF = "False";
	o << "AForm " << rhs.GetName() << " has a signing grade of " << rhs.GetSignGrade()
    << " and an execution grade of " << rhs.GetExecuteGrade() << " and the signed boolean is " << TF;
	return (o);
}
