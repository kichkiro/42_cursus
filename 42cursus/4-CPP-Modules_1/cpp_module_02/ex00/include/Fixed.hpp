/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 20:09:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Fixed
{
    public:

        Fixed(void);
        Fixed(const Fixed &src);
        Fixed &operator = (const Fixed &rhs);
        ~Fixed(void);

        int   getRawBits(void) const;
        void  setRawBits(int const raw);

    private:

        int 			 _fp_nbr;
        static const int _f_bits = 8;		
};
