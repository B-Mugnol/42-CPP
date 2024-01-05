/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:29:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/05 14:10:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

static double getTimeInMS(std::clock_t time);
static double testVector(int size, char **input, PmergeMe &pmerge);
static double testDeque(int size, char **input, PmergeMe &pmerge);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Invalid Input\n";
		return 1;
	}

	std::cout << "Unordered List:\n";
	for (int i = 1; i < argc && i < 19; i++)
	{
		std::cout << argv[i] << " ";
	}
	if (argc > 19)
		std::cout << "[...]";
	std::cout << "\n";

	PmergeMe pmerge;
	std::clock_t vector_sort_time = testVector(argc, argv, pmerge);
	std::clock_t deque_sort_time = testDeque(argc, argv, pmerge);

	std::cout << "-------------------- SORTING TIME --------------------\n";
	std::cout << "Vector sorting took " << getTimeInMS(vector_sort_time)
			  << " ms\n";
	std::cout << "Deque sorting took " << getTimeInMS(deque_sort_time) << " ms\n";
}

static double getTimeInMS(std::clock_t time)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	double time_in_ms = time / clock_per_ms;

	return time_in_ms;
}

static double testVector(int size, char **input, PmergeMe &pmerge)
{
	std::clock_t start_time = std::clock();
	std::vector<int> vector_seq = pmerge.mergeSortVector(size, input);
	std::clock_t delta_time = std::clock() - start_time;

	std::cout << "Ordered List using Vector:\n";
	for (std::size_t i = 0; i < vector_seq.size() && i < 19; i++)
	{
		std::cout << vector_seq[i] << " ";
	}
	if (vector_seq.size() > 19)
		std::cout << "[...]";
	std::cout << "\n";

	return delta_time;
}

static double testDeque(int size, char **input, PmergeMe &pmerge)
{
	std::clock_t start_time = std::clock();
	std::deque<int> deque_seq = pmerge.mergeSortDeque(size, input);
	std::clock_t delta_time = std::clock() - start_time;

	std::cout << "Ordered List using Deque:\n";
	for (std::size_t i = 0; i < deque_seq.size() && i < 19; i++)
	{
		std::cout << deque_seq[i] << " ";
	}
	if (deque_seq.size() > 19)
		std::cout << "[...]";
	std::cout << "\n";

	return delta_time;
}
