/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:23:17 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:33:30 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", 72, 45) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: parameter constructor called"
		<< RESET << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm
	&otherRRForm) : AForm(otherRRForm) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: copy constructor called"
		<< RESET << std::endl;
	this->_target = otherRRForm.getTarget();	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const
	RobotomyRequestForm &otherRRForm) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: copy assigment constructor called"
		<< RESET << std::endl;
	if (this != &otherRRForm) {
		AForm::operator=(otherRRForm);
		this->_target = otherRRForm.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: destructor called" << RESET
		<< std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: execute member function called"
		<< RESET << std::endl;
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " isn't signed." << std::endl;
		return;
	}	
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << "Bzzzzzz Bzzzzzz... <Drilling noises>\n";
	srand(static_cast<unsigned int>(time(0)));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!\n";
	else
    	std::cout << "Robotomy on " << this->_target << " failed!\n";
	std::cout << executor.getName() << " executed "  << this->getName()
		<< std::endl;
}
