/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:07:38 by amak              #+#    #+#             */
/*   Updated: 2024/08/13 01:10:07 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

const std::string RED = "\033[31m";

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const AForm &otherAForm);
		AForm &operator=(const AForm &otherAForm);
		virtual ~AForm();

		AForm(std::string name, unsigned int gradeSign,
			unsigned int gradeExecute);
		std::string		getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeSign() const;
		unsigned int	getGradeExecute() const;
		void			beSigned(const Bureaucrat &bureaucrat);

		virtual void	execute(Bureaucrat const &executor) const = 0;

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

std::ostream	&operator<<(std::ostream &output, const AForm &aform);

#endif
