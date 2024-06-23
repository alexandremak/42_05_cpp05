/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:42:49 by amak              #+#    #+#             */
/*   Updated: 2024/06/23 15:55:14 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm(target, 145, 137) {
	std::cout << "[SHRUBBERYCREATINGFORM]: parameter constructor called"
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm
	&otherSCForm) : AForm(otherSCForm) {
	std::cout << "[SHRUBBERYCREATINGFORM]: copy constructor called"
		<< std::endl;	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const
	ShrubberyCreationForm &otherSCForm) {
	std::cout << "[SHRUBBERYCREATINGFORM]: copy assigment constructor called"
		<< std::endl;	
	if (this != &otherSCForm)
  		AForm::operator=(otherSCForm);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[SHRUBBERYCREATINGFORM]: destructor called" << std::endl;	
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->getName());
}
