/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:20 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 23:23:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {	
	// - ShrubberyCreationForm: Required grades: sign 145, exec 137
	// - RobotomyRequestForm: Required grades: sign 72, exec 45
	// - PresidentialPardonForm: Required grades: sign 25, exec 5

	unsigned int grade = 145;

	try {
		Bureaucrat montenegro("Montenegro", grade);
		std::cout << montenegro << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm arvoreform("Formulario Arvore");
		std::cout << arvoreform << std::endl;
		montenegro.signForm(arvoreform);
		std::cout << arvoreform << std::endl;
		montenegro.signForm(arvoreform);
		montenegro.executeForm(arvoreform);
		std::cout << std::endl;

		RobotomyRequestForm robotform("Formulario Robot");
		std::cout << robotform << std::endl;
		montenegro.signForm(robotform);
		std::cout << robotform << std::endl;
		montenegro.executeForm(robotform);
		std::cout << std::endl;

		PresidentialPardonForm pardonform("Formulario Perdao");
		std::cout << pardonform << std::endl;
		montenegro.signForm(pardonform);
		std::cout << pardonform << std::endl;
		montenegro.executeForm(pardonform);
	}
	catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << "[BUREAUCRAT]: GradeTooHighException: " << exception.what()
			<< std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << "[BUREAUCRAT]: GradeTooLowException: " << exception.what()
			<< std::endl;
	}
	catch (AForm::GradeTooLowException &exception) {
		std::cerr << "[AFORM]: GradeTooLowException: " << exception.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &exception) {
		std::cerr << "[AFORM]: GradeTooHighException: " << exception.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "Standart exception: " << exception.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown exception caught!" << std::endl;
	}
}
