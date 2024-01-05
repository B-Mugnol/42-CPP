/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/05 13:35:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <vector>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);

	PmergeMe &operator=(PmergeMe const &rhs);

	std::vector<int> mergeSortVector(int length, char **input);
	std::deque<int> mergeSortDeque(int length, char **input);

private:
	void merge(std::vector<int> &sequence, int begin, int middle, int end);
	void insertionSort(std::vector<int> &sequence, int begin, int end);
	void sort(std::vector<int> &sequence, int begin, int end);

	void merge(std::deque<int> &sequence, int begin, int middle, int end);
	void insertionSort(std::deque<int> &sequence, int begin, int end);
	void sort(std::deque<int> &sequence, int begin, int end);
};

#endif
