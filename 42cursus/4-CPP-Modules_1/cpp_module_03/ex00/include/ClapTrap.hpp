/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 21:49:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class ClapTrap {
    public:
        ClapTrap(void);
        ClapTrap(string name, int h_p, int e_p, int a_d);
        ClapTrap(const ClapTrap &src);
        ClapTrap &operator=(const ClapTrap &rs);
        ~ClapTrap(void);

        void attack(const string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        string _name;
        int    _hit_points;
        int    _energy_points;
        int    _attack_damage;
};
