/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:27:32 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 21:33:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATINGFORM_HPP
# define SHRUBBERYCREATINGFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

const std::string GREEN = "\033[32m";

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &otherSCForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm
			&otherSCForm);
		~ShrubberyCreationForm();
		
		std::string	getTarget() const;

		virtual void	execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
		
		ShrubberyCreationForm();
};

# endif
