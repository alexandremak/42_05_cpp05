/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:50:56 by amak              #+#    #+#             */
/*   Updated: 2024/06/19 02:12:36 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &otherBureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &otherBureaucrat);
		~Bureaucrat();

		Bureaucrat(std::string name, unsigned int grade);
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		
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
		unsigned int		_grade;	
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif