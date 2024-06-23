/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:51:20 by amak              #+#    #+#             */
/*   Updated: 2024/06/22 22:57:44 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {	
	// unsigned int grade = 150;
	// unsigned int grade = 1;
	unsigned int grade = 150;


	try {
		Bureaucrat montenegro("Montenegro", grade);
		std::cout << montenegro << std::endl;
		
		montenegro.incrementGrade();
		std::cout << montenegro << std::endl;

		montenegro.decrementGrade();
		std::cout << montenegro << std::endl;
		
		Form formulario("Autorizacao", 150, 150);
		std::cout << formulario << std::endl;

		montenegro.signForm(formulario);

		std::cout << formulario << std::endl;

		Form copiaFormulario(formulario);
		std::cout << copiaFormulario << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << "[BUREAUCRAT]: GradeTooHighException: " << exception.what()
			<< std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << "[BUREAUCRAT]: GradeTooLowException: " << exception.what()
			<< std::endl;
	}
	catch (Form::GradeTooLowException &exception) {
		std::cerr << "[FORM]: GradeTooLowException: " << exception.what() << std::endl;
	}
	catch (Form::GradeTooHighException &exception) {
		std::cerr << "[FORM]: GradeTooHighException: " << exception.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "Standart exception: " << exception.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown exception caught!" << std::endl;
	}
}
