/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 23:54:58 by amak              #+#    #+#             */
/*   Updated: 2024/08/13 01:07:31 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {	
	// - ShrubberyCreationForm: Required grades: sign 145, exec 137
	// - RobotomyRequestForm: Required grades: sign 72, exec 45
	// - PresidentialPardonForm: Required grades: sign 25, exec 5

	unsigned int grade = 1;

	try {
		Bureaucrat	montenegro("Montenegro", grade);
		std::cout << montenegro << std::endl;
		std::cout << std::endl;

		Intern		interno;
		std::cout << std::endl;

		AForm *untitledform;
		AForm *arvoreform;
		AForm *robotform;
		AForm *pardonform;
		std::cout << "AForm pointers created!" << std::endl;
		std::cout << std::endl;

		untitledform = interno.makeForm("UntitledForm", "Unknown");
		arvoreform = interno.makeForm("ShrubberyCreationForm", "ficheiro");
		robotform = interno.makeForm("RobotomyRequestForm", "Ventura");
		pardonform = interno.makeForm("PresidentialPardonForm", "Marcelo");
		std::cout << std::endl;


		montenegro.signForm(*arvoreform);
		montenegro.executeForm(*arvoreform);
		std::cout << std::endl;

		montenegro.executeForm(*robotform);
		montenegro.signForm(*robotform);
		montenegro.executeForm(*robotform);
		std::cout << std::endl;

		montenegro.signForm(*pardonform);
		montenegro.executeForm(*pardonform);
		std::cout << std::endl;

		delete untitledform;
		delete arvoreform;
		delete robotform;
		delete pardonform;
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
