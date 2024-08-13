/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 23:55:16 by amak              #+#    #+#             */
/*   Updated: 2024/08/13 00:16:55 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

const std::string MAGENTA = "\033[35m";

class Intern {
	public:
		Intern();
		Intern(const Intern &otherIntern);
		Intern	&operator=(const Intern &otherIntern);
		~Intern();
		
		AForm	*makeForm(const std::string form, const std::string target);
	
	private:
		
};

#endif
