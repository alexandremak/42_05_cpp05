/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:40:07 by amak              #+#    #+#             */
/*   Updated: 2024/06/22 16:52:53 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

const std::string RED = "\033[31m";

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const Form &otherForm);
		Form &operator=(const Form &otherForm);
		~Form();

		Form(std::string name, unsigned int gradeSign,
			unsigned int gradeExecute);
		std::string		getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeSign() const;
		unsigned int	getGradeExecute() const;
		void			beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;	
};

std::ostream	&operator<<(std::ostream &output, const Form &form);

#endif
