#include "pch.h"
#include <gtest/gtest.h>
#include "Calc.h"

TEST(CalcTest, EmptyStringShouldBeZero)
{
	Calc calc;
	int expected = 0;
	int actual = calc.sum("");
	ASSERT_EQ(expected, actual);
}
