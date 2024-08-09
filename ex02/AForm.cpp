/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:07:53 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:19:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : 
	_name("Untitled AForm"),
	_isSigned(false),
	_gradeSign(150),
	_gradeExecute(150) {
		std::cout << RED << "[AFORM]: default constructor called" << RESET
			<< std::endl;
}

AForm::AForm(const AForm &otherAForm) :
	_name(otherAForm._name),
	_isSigned(false),
	_gradeSign(otherAForm._gradeSign),
	_gradeExecute(otherAForm._gradeExecute) {
		std::cout << RED << "[AFORM]: copy constructor called" << RESET
		<< std::endl;
}

AForm &AForm::operator=(const AForm &otherAForm) {
	std::cout << RED << "[AFORM]: copy assigment constructor called" << RESET
		<< std::endl;
	if (this != &otherAForm)
		this->_isSigned = otherAForm._isSigned;
	return (*this);
}
	
AForm::~AForm() {
	std::cout << RED << "[AFORM]: destructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeSign,
		unsigned int gradeExecute) :
	_name(name),
	_isSigned(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute) {
		std::cout << RED << "[AFORM]: parameter constructor called" << RESET
			<< std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::getIsSigned() const {
	return (this->_isSigned);
}

unsigned int	AForm::getGradeSign() const {
	return (this->_gradeSign);
}

unsigned int	AForm::getGradeExecute() const {
	return (this->_gradeExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << RED << "[AFORM]: beSigned member function called" << RESET
		<< std::endl;
	if (!this->_isSigned)
		if (bureaucrat.getGrade() <= this->_gradeSign) {
			this->_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << this->_name
				<< std::endl;
		}
		else
			throw GradeTooLowException();
	else
		std::cout << this->_name << " is already signed!" << std::endl;
}

void	AForm::execute(Bureaucrat const &executor) const { 
	std::cout << RED << "[AFORM]: execute member function called" << RESET
		<< std::endl;
	if (!this->_isSigned)
		std::cout << this->_name << " isn't signed." << std::endl;
	(void)executor;
 }

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &output, const AForm &form) {
	output << form.getName();
	if (form.getIsSigned())
		output << " is signed, needed a minimum grade " << form.getGradeSign()
			<< " to be signed";
	else
		output << " isn't signed, needs a minimum grade " << form.getGradeSign()
			<< " to be signed";
	output << " and a minimum grade " << form.getGradeExecute() << " to be executed.";
	return output;	
}

