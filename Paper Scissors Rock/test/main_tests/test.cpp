#include "gtest/gtest.h"

#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"

#include <iostream>

//#define DEBUG_TESTS

namespace TestHelper {

std::string StringFromEnumResult(const Result& r) {
	switch(r) {
		case Result::WIN :
			return "WIN";
		case Result::LOOSE :
			return "LOOSE";
		case Result::TIE :
			return "TIE";
		default :
			return "";
	};
}

template<class T>
void print_comparable(const T& expected, const T& actual) {
#ifdef DEBUG_TESTS
	std::cout 	<< "expected = " << StringFromEnumResult(expected) 
        		<< "\nactual = " << StringFromEnumResult(actual) << '\n';
#endif
}

}  // namespace

TEST(PaperScissorsRockTest, PaperPaper) {
	Paper first;
	Paper second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::TIE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, PaperRock) {
	Paper first;
	Rock second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::WIN;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, PaperScissors) {
	Paper first;
	Scissors second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::LOOSE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, ScissorsPScissors) {
	Scissors first;
	Scissors second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::TIE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, ScissorsRock) {
	Scissors first;
	Rock second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::LOOSE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, ScissorsPaper) {
	Scissors first;
	Paper second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::WIN;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, RockRock) {
	Rock first;
	Rock second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::TIE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, RockScissors) {
	Rock first;
	Scissors second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::WIN;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

TEST(PaperScissorsRockTest, RockPaper) {
	Rock first;
	Paper second;

	const Result actual = first.IsBeat(second);
	const Result expected = Result::LOOSE;

	TestHelper::print_comparable(actual, expected);

	EXPECT_EQ(expected, actual);
}

/* TODO(Pavel)
It worth to test Player and ConsoleDrawer clases
*/
