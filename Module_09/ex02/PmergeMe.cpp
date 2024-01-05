/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/05 13:47:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

/*
** ------------------------------ VECTOR METHODS ------------------------------
*/

std::vector<int> PmergeMe::mergeSortVector(int length, char **input)
{
	std::vector<int> sequence;
	for (int i = 1; i < length; i++)
	{
		sequence.push_back(std::atoi(input[i]));
	}
	sort(sequence, 0, sequence.size() - 1);
	return sequence;
}

void PmergeMe::merge(std::vector<int> &sequence, int begin, int middle, int end)
{
	std::vector<int> left_vector(sequence.begin() + begin, sequence.begin() + middle + 1);
	std::vector<int> right_vector(sequence.begin() + middle + 1, sequence.begin() + end + 1);
	size_t right_index = 0;
	size_t left_index = 0;
	size_t length = left_vector.size() + right_vector.size();
	for (size_t i = begin; i < begin + length; i++)
	{
		if (right_index == right_vector.size())
		{
			sequence[i] = left_vector[left_index];
			left_index++;
		}
		else if (left_index == left_vector.size())
		{
			sequence[i] = right_vector[right_index];
			right_index++;
		}
		else if (right_vector[right_index] > left_vector[left_index])
		{
			sequence[i] = left_vector[left_index];
			left_index++;
		}
		else
		{
			sequence[i] = right_vector[right_index];
			right_index++;
		}
	}
}

void PmergeMe::insertionSort(std::vector<int> &sequence, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int temp = sequence[i + 1];
		int j = i + 1;
		while (j > begin && sequence[j - 1] > temp)
		{
			sequence[j] = sequence[j - 1];
			j--;
		}
		sequence[j] = temp;
	}
}

void PmergeMe::sort(std::vector<int> &sequence, int begin, int end)
{
	if (end - begin > 5)
	{
		int middle = (begin + end) / 2;
		sort(sequence, begin, middle);
		sort(sequence, middle + 1, end);
		merge(sequence, begin, middle, end);
	}
	else
	{
		insertionSort(sequence, begin, end);
	}
}

/*
** ------------------------------- DEQUE METHODS ------------------------------
*/

std::deque<int> PmergeMe::mergeSortDeque(int length, char **input)
{
	std::deque<int> sequence;
	for (int i = 1; i < length; i++)
	{
		sequence.push_back(std::atoi(input[i]));
	}
	sort(sequence, 0, sequence.size() - 1);
	return sequence;
}

void PmergeMe::merge(std::deque<int> &sequence, int begin, int middle, int end)
{
	std::deque<int> left_deque(sequence.begin() + begin, sequence.begin() + middle + 1);
	std::deque<int> right_deque(sequence.begin() + middle + 1, sequence.begin() + end + 1);
	size_t right_index = 0;
	size_t left_index = 0;
	size_t length = left_deque.size() + right_deque.size();
	for (size_t i = begin; i < begin + length; i++)
	{
		if (right_index == right_deque.size())
		{
			sequence[i] = left_deque[left_index];
			left_index++;
		}
		else if (left_index == left_deque.size())
		{
			sequence[i] = right_deque[right_index];
			right_index++;
		}
		else if (right_deque[right_index] > left_deque[left_index])
		{
			sequence[i] = left_deque[left_index];
			left_index++;
		}
		else
		{
			sequence[i] = right_deque[right_index];
			right_index++;
		}
	}
}

void PmergeMe::insertionSort(std::deque<int> &sequence, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int temp = sequence[i + 1];
		int j = i + 1;
		while (j > begin && sequence[j - 1] > temp)
		{
			sequence[j] = sequence[j - 1];
			j--;
		}
		sequence[j] = temp;
	}
}

void PmergeMe::sort(std::deque<int> &sequence, int begin, int end)
{
	if (end - begin > 5)
	{
		int middle = (begin + end) / 2;
		sort(sequence, begin, middle);
		sort(sequence, middle + 1, end);
		merge(sequence, begin, middle, end);
	}
	else
	{
		insertionSort(sequence, begin, end);
	}
}

/* ************************************************************************** */
