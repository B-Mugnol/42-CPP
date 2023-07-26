/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:29:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/26 14:20:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

typedef enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	RANDOM,
	INVALID
} t_level;

class Harl
{
public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
	static std::string const levelString[INVALID];

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void random(void);
	void invalid(void);
};

#endif
