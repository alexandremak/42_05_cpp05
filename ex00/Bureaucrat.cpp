/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:10 by amak              #+#    #+#             */
/*   Updated: 2024/06/19 02:08:08 by amak             ###   ########.fr       */
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
	std::cout << BLUE << "[BUREAUCRAT]: copy assignement constructor called"
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
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}

std::string	Bureaucrat::getName() const {
	return(this->_name);
}

unsigned int	Bureaucrat::getGrade() const {
	return(this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooHighException();
	this->_grade += 1;
}

void	Bureaucrat::decrememtGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade value is higher than 150");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade value is lower than 1");
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << "bureaucrat grade "
		<< bureaucrat.getGrade() << "." << std::endl;
}
