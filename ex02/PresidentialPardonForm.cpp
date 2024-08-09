/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:56:30 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:33:04 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", 25, 5) {
	std::cout << CYAN << "[PRESIDENCTIALPARDONFORM]: parameter constructor called"
		<< RESET << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
	&otherPPForm) : AForm(otherPPForm) {
	std::cout << CYAN << "[PRESIDENCTIALPARDONFORM]: copy constructor called"
		<< RESET << std::endl;
	this->_target = otherPPForm.getTarget();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const
	PresidentialPardonForm &otherPPForm) {
	std::cout << CYAN << "[PRESIDENCTIALPARDONFORM]: copy assigment constructor called"
		<< RESET << std::endl;
	if (this != &otherPPForm) {
		AForm::operator=(otherPPForm);
		this->_target = otherPPForm.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << CYAN << "[PRESIDENCTIALPARDONFORM]: destructor called" << RESET
		<< std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	std::cout << CYAN << "[PRESIDENCTIALPARDONFORM]: execute member function called"
		<< RESET << std::endl;
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " isn't signed." << std::endl;
		return;
	}	
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
	std::cout << executor.getName() << " executed "  << this->getName()
		<< std::endl;
}
