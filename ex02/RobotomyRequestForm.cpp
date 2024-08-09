/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:23:17 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 20:21:57 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(target, 72, 45) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: parameter constructor called"
		<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm
	&otherRRForm) : AForm(otherRRForm) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: copy constructor called"
		<< RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const
	RobotomyRequestForm &otherRRForm) {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: copy assigment constructor called"
		<< RESET << std::endl;
	if (this != &otherRRForm)
		AForm::operator=(otherRRForm);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: destructor called" << RESET
		<< std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->getName());
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	std::cout << YELLOW << "[ROBOTOMYREQUESTFORM]: execute member function called"
		<< RESET << std::endl;
	if (!this->getIsSigned()) {
		std::cout << "The form isn't signed." << std::endl;
		return;
	}	
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << "Bzzzzzz Bzzzzzz... <Drilling noises>\n";
	srand(static_cast<unsigned int>(time(0)));
	int randomval = rand();
	std::cout << randomval << std::endl;
	if (randomval % 2)
		std::cout << executor.getName() << " has been robotomized successfully!\n";
	else
    	std::cout << "Robotomy on " << executor.getName() << " failed!\n";
}
