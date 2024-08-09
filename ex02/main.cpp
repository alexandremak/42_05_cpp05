/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:20 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 20:14:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {	
	// unsigned int grade = 150;
	// unsigned int grade = 1;
	unsigned int grade = 20;


	try {
		Bureaucrat montenegro("Montenegro", grade);
		std::cout << montenegro << std::endl;

		ShrubberyCreationForm arvoreform("Formulario Arvore");
		std::cout << arvoreform << std::endl;

		montenegro.signForm(arvoreform);
		std::cout << arvoreform << std::endl;

		arvoreform.execute(montenegro);

		RobotomyRequestForm robotform("Formulario Robot");
		std::cout << robotform << std::endl;

		montenegro.signForm(robotform);
		std::cout << robotform << std::endl;
		
		robotform.execute(montenegro);
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
