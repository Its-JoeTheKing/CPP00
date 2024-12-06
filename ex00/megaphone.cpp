/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:09:35 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/06 11:09:37 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *argv[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string mega = argv[i];
		for (size_t j = 0; j < mega.size(); j++)
		{
			std::cout << (char)std::toupper(mega[j]);
		}
	}
	std::cout << "\n";
	return 0;
}
