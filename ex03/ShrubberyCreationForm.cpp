/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:42:49 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:33:48 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", 145, 137) {
	std::cout << GREEN << "[SHRUBBERYCREATINGFORM]: parameter constructor called"
		<< RESET << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm
	&otherSCForm) : AForm(otherSCForm) {
	std::cout << GREEN << "[SHRUBBERYCREATINGFORM]: copy constructor called"
		<< RESET << std::endl;
	this->_target = otherSCForm.getTarget();	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const
	ShrubberyCreationForm &otherSCForm) {
	std::cout << GREEN << "[SHRUBBERYCREATINGFORM]: copy assigment constructor called"
		<< RESET << std::endl;
	if (this != &otherSCForm) {
		AForm::operator=(otherSCForm);
		this->_target = otherSCForm.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << GREEN << "[SHRUBBERYCREATINGFORM]: destructor called" << RESET
		<< std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::cout << GREEN << "[SHRUBBERYCREATINGFORM]: execute member function called"
		<< RESET << std::endl;
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " isn't signed." << std::endl;
		return;
	}	
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open()) {
	std::cerr << "Error opening file" << std::endl;
		return;
 	}
	file << "           \\/ |    |/                     &&& &&  & &&          " << std::endl;
	file << "        \\/ / \\||/  /_/___/_           && &\\/&\\|& ()|/ @, &&     " << std::endl;
	file << "         \\/   |/ \\/                   &\\/(/&/&||/& /_/)_&/_&    " << std::endl;
	file << "    _\\__\\_\\   |  /_____/_          &() &\\/&|()|/&\\/ '%' & ()    " << std::endl;
	file << "           \\  | /          /      &_\\_&&_\\ |& |&&/&__%_/_& &&   " << std::endl;
	file << "  __ _-----`  |{,-----------~   &&   && & &| &| /& & % ()& /&&  " << std::endl;
	file << "            \\ }{                 ()&_---()&\\&\\|&&-&&--%---()~   " << std::endl;
	file << "             }{{                     &&     \\|||                " << std::endl;
	file << "             }}{                             |||                " << std::endl;
	file << "             {{}                             |||                " << std::endl;
	file << "       , -=-~{ .-^- _                  , -=-~  .-^- _           " << std::endl;
	file.close();
	std::cout << executor.getName() << " executed "  << this->getName() << std::endl;
}
