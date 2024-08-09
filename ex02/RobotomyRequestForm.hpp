/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:08:42 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 20:21:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib> 
# include <ctime>
# include "AForm.hpp"

const std::string YELLOW = "\033[33m";

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &otherRRForm);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &otherRRForm);
		~RobotomyRequestForm();

		std::string	getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm();
};

#endif
