/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:52:36 by amak              #+#    #+#             */
/*   Updated: 2024/06/20 00:44:00 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : 
	_name("Untitled Form"),
	_isSigned(false),
	_gradeSign(150),
	_gradeExecute(150) {
		std::cout << RED << "[FORM]: default constructor called" << RESET
			<< std::endl;
}

Form::Form(const Form &otherForm) :
	_name(otherForm._name),
	_isSigned(otherForm._isSigned),
	_gradeSign(otherForm._gradeSign),
	_gradeExecute(otherForm._gradeExecute) {
		std::cout << RED << "[FORM]: copy constructor called" << RESET
		<< std::endl;
}

Form &Form::operator=(const Form &otherForm) {
	std::cout << RED << "[FORM]: copy assigment constructor called" << RESET
		<< std::endl;
	if (this != &otherForm)
		this->_isSigned = otherForm._isSigned;
	return (*this);
}
	
Form::~Form() {
	std::cout << RED << "[FORM]: destructor called" << RESET << std::endl;
}
