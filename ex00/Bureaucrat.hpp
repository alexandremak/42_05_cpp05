/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:50:56 by amak              #+#    #+#             */
/*   Updated: 2024/06/11 22:01:24 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &otherBureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &otherBureaucrat);
		~Bureaucrat();
		std::string	getName();
		std::string	getGrade();
		void		GradeTooHighException();
		void		GradeTooLowException();
		
	private:
		const std::string	_name;
		unsigned int		_grade;	
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &otherBureaucrat);

#endif