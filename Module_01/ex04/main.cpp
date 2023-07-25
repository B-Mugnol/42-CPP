/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:24:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/25 17:20:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
		return 1;

	std::string filename = argv[1];

	std::ifstream inputFile;
	inputFile.open(filename.c_str());
	if (inputFile.fail())
		return 1;

	std::ofstream outputFile;
	outputFile.open((filename + ".replace").c_str());
	if (outputFile.fail())
		return 1;

	std::string line;
	size_t pos;
	size_t found;
	size_t s1_len = std::string(argv[2]).length();
	while (getline(inputFile, line))
	{
		pos = 0;
		found = line.find(argv[2]);
		while (found != std::string::npos)
		{
			outputFile << line.substr(pos, found - pos) << argv[3];
			pos = found + s1_len;
			found = line.find(argv[2], pos);
		}
		outputFile << line.substr(pos);
		if (inputFile.eof() == false)
			outputFile << "\n";
	}

	inputFile.close();
	outputFile.close();
	if (inputFile.bad() || outputFile.bad())
		return 1;
	return 0;
}
