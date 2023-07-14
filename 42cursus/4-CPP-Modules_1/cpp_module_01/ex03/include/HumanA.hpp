/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:32:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include "Weapon.hpp"

// Class ---------------------------------------------------------------------->

class HumanA
{
	public:
		HumanA(string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void);
	private:
		string	_name;
		Weapon	&_weapon;
};
