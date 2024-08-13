/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:45:33 by amak              #+#    #+#             */
/*   Updated: 2024/08/09 22:10:51 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


const std::string CYAN = "\033[36m";

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &otherPPForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &otherPPForm);
		~PresidentialPardonForm();
	
		std::string	getTarget() const;

		virtual void	execute(Bureaucrat const &executor) const;

		private:
			std::string	_target;
			
			PresidentialPardonForm();
};

#endif
