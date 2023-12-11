/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 21:44:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

static void testInvalidSpan(void);
static void testNegativeSpan(void);
static void testSmallSpan(void);
static void testBigSpan(void);

int main(void)
{
	testInvalidSpan();
	testNegativeSpan();
	testSmallSpan();
	testBigSpan();

	return 0;
}

static void testInvalidSpan(void)
{
	std::cout << "--------------- INVALID SPAN TESTS ---------------\n";
	try
	{
		Span invalid;
		invalid.addNumber(6);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span invalid(1);
		invalid.addNumber(2);
		invalid.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span invalid(1);
		invalid.addNumber(2);
		invalid.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span invalid(2);
		invalid.addNumber(2);
		invalid.addNumber(3);
		invalid.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void testNegativeSpan(void)
{
	std::cout << "---------------- NEGATIVE SPAN TESTS ----------------\n";

	Span negative_span(5);

	negative_span.addNumber(-6);
	negative_span.addNumber(3);
	negative_span.addNumber(-17);
	negative_span.addNumber(9);
	negative_span.addNumber(-11);
	std::cout << "shortest span: " << negative_span.shortestSpan() << "\n";
	std::cout << "longest span: " << negative_span.longestSpan() << "\n";
}

static void testSmallSpan(void)
{
	std::cout << "---------------- SMALL SPAN TESTS ----------------\n";

	Span small_span(5);

	small_span.addNumber(6);
	small_span.addNumber(3);
	small_span.addNumber(17);
	small_span.addNumber(9);
	small_span.addNumber(11);
	std::cout << "shortest span: " << small_span.shortestSpan() << "\n";
	std::cout << "longest span: " << small_span.longestSpan() << "\n";
}

static void testBigSpan(void)
{
	std::cout << "------------------ BIG SPAN TESTS ------------------\n";

	Span big_span(20000);

	big_span.fillWithRandom();
	std::cout << "shortest span: " << big_span.shortestSpan() << "\n";
	std::cout << "longest span: " << big_span.longestSpan() << "\n";
}
