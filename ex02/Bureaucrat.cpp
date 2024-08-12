/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:10 by amak              #+#    #+#             */
/*   Updated: 2024/08/12 23:46:52 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {
	std::cout << BLUE << "[BUREAUCRAT]: default constructor called" << RESET
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &otherBureaucrat) : 
	_name(otherBureaucrat._name),
	_grade(otherBureaucrat._grade) {
	std::cout << BLUE << "[BUREAUCRAT]: copy constructor called" << RESET
		<< std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &otherBureaucrat) {
	std::cout << BLUE << "[BUREAUCRAT]: copy assignment constructor called"
		<< RESET << std::endl;
	if (this != &otherBureaucrat)
		this->_grade = otherBureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << BLUE << "[BUREAUCRAT]: destructor called" << RESET
		<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : 
	_name(name), _grade(grade) {
	std::cout << BLUE << "[BUREAUCRAT]: parameters constructor called" << RESET
		<< std::endl;	
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::string	Bureaucrat::getName() const {
	return(this->_name);
}

unsigned int	Bureaucrat::getGrade() const {
	return(this->_grade);
}

void	Bureaucrat::incrementGrade() {
	std::cout << BLUE << "[BUREAUCRAT]: incrementGrade() member function called"
		<< RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	std::cout << BLUE << "[BUREAUCRAT]: decrementGrade() member function called"
		<< RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw GradeTooHighException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		std::cout << BLUE << "[BUREAUCRAT]: signForm member function called"
			<< RESET << std::endl;
		form.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException &exception) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because his "
			<< exception.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		std::cout << BLUE << "[BUREAUCRAT]: executeForm member function called"
			<< RESET << std::endl;
		form.execute(*this);
	}
	catch (const AForm::GradeTooLowException &exception) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because his "
			<< exception.what() << "." << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade cannot be lower than 150");
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << " bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return output;
}
