#include "pch.h"
#include <gtest/gtest.h>
#include "Calc.h"

// Ноль параметров
TEST(CalcTest, EmptyStringShouldBeZero)
{
	Calc calc;
	int expected = 0;
	int actual = calc.sum("");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, Sum0ShouldBe0)
{
	Calc calc;
	int expected = 0;
	int actual = calc.sum("0");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, Sum1MShouldBe1M)
{
	Calc calc;
	int expected = 1000000;
	int actual = calc.sum("1000000");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, Val75and125ShouldBe200)
{
	Calc calc;
	int expected = 200;
	int actual = calc.sum("75,125");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigVal_1)
{
	Calc calc;
	int expected = std::numeric_limits<int>::max();
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2 + 1);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigVal_2)
{
	Calc calc;
	int expected = std::numeric_limits<int>::max();
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2 + 1);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, AnyNegValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, AnyNegValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-1000000");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, AnyNegValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-10,10");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, AnyNegValIsError4)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,-10");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, StringValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, StringValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,10");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, StringValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,val2");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, StringValIsError4)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,val2");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, StringValIsError5)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,val2");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FloatingPointValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10.0,20");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FloatingPointValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,20.0");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FloatingPointValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10.0,20.0");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigValIsError1)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum((expr+",10").c_str());
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigValIsError2)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum(("10," + expr).c_str());
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigValIsError3)
{
	Calc calc;
	int expected = -1;
	std::string expr1 = std::to_string(std::numeric_limits<int>::max()/2 + 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max()/2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, VeryBigValIsError4)
{
	Calc calc;
	int expected = -1;
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2 + 2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}
