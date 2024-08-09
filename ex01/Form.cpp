/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:52:36 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:48:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : 
	_name("Untitled Form"),
	_isSigned(false),
	_gradeSign(150),
	_gradeExecute(150) {
		std::cout << RED << "[FORM]: default constructor called" << RESET
			<< std::endl;
}

Form::Form(const Form &otherForm) :
	_name(otherForm._name),
	_isSigned(false),
	_gradeSign(otherForm._gradeSign),
	_gradeExecute(otherForm._gradeExecute) {
		std::cout << RED << "[FORM]: copy constructor called" << RESET
		<< std::endl;
}

Form &Form::operator=(const Form &otherForm) {
	std::cout << RED << "[FORM]: copy assigment constructor called" << RESET
		<< std::endl;
	if (this != &otherForm)
		this->_isSigned = otherForm._isSigned;
	return (*this);
}
	
Form::~Form() {
	std::cout << RED << "[FORM]: destructor called" << RESET << std::endl;
}

Form::Form(std::string name, unsigned int gradeSign,
		unsigned int gradeExecute) :
	_name(name),
	_isSigned(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute) {
		std::cout << RED << "[FORM]: parameter constructor called" << RESET
			<< std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::getIsSigned() const {
	return (this->_isSigned);
}

unsigned int	Form::getGradeSign() const {
	return (this->_gradeSign);
}

unsigned int	Form::getGradeExecute() const {
	return (this->_gradeExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << RED << "[FORM]: beSigned member function called" << RESET
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

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &output, const Form &form) {
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

