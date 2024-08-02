/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:20 by amak              #+#    #+#             */
/*   Updated: 2024/08/02 21:09:38 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {	
	// unsigned int grade = 150;
	// unsigned int grade = 1;
	unsigned int grade = 149;


	try {
		Bureaucrat montenegro("Montenegro", grade);
		std::cout << montenegro << std::endl;

		montenegro.incrementGrade();
		std::cout << montenegro << std::endl;

		montenegro.decrementGrade();
		std::cout << montenegro << std::endl;

		ShrubberyCreationForm arvore("Arvore");
		std::cout << arvore << std::endl;

		montenegro.signForm(arvore);
		std::cout << arvore << std::endl;

		ShrubberyCreationForm copiaFormulario(arvore);
		std::cout << copiaFormulario << std::endl;

		arvore.execute(montenegro);
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
