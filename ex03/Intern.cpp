/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:08:29 by amak              #+#    #+#             */
/*   Updated: 2024/08/13 00:42:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << MAGENTA << "[INTERN]: default constructor called" << RESET
		<< std::endl;
}

Intern::Intern(const Intern &otherIntern) {
	std::cout << MAGENTA << "[INTERN]: copy constructor called" << RESET
		<< std::endl;
	*this = otherIntern;
}

Intern	&Intern::operator=(const Intern &otherIntern) {
	std::cout << MAGENTA << "[INTERN]: copy assignment constructor called" << RESET
		<< std::endl;
	(void)otherIntern;
	return(*this);
}

Intern::~Intern() {
	std::cout << MAGENTA << "[INTERN]: destructor called" << RESET
		<< std::endl;
}

AForm	*Intern::makeForm(const std::string form, const std::string target) {
	std::string	forms[3];
	int			i;

	forms[0] = "ShrubberyCreationForm";
	forms[1] = "RobotomyRequestForm";
	forms[2] = "PresidentialPardonForm";

	for (i = 0; i < 3; i++)
		if (!forms[i].compare(form)) {
			std::cout << "Intern creates " << forms[i] << std::endl; 
			break;
		}
	
	switch (i) {
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "Intern cannot create a form called " << form << std::endl;
			return (NULL);
	}
}
