#include "pch.h"
#include <gtest/gtest.h>
#include "Calc.h"

class CalcTest : public ::testing::Test {
public:
	CalcTest();
	~CalcTest();
	void SetUp();
	void TearDown();
};

CalcTest::CalcTest() {
	std::cout << "CalcTest::CalcTEST_F()" << std::endl;
}

CalcTest::~CalcTest() {
	std::cout << "CalcTest::~CalcTEST_F()" << std::endl;
}

void CalcTest::SetUp() {
	std::cout << "CalcTest::SetUp()" << std::endl;
}

void CalcTest::TearDown() {
	std::cout << "CalcTest::TearDown()" << std::endl;
}


// Ноль параметров
TEST_F(CalcTest, EmptyStringShouldBeZero)
{
	Calc calc;
	int expected = 0;
	int actual = calc.sum("");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, Sum0ShouldBe0)
{
	Calc calc;
	int expected = 0;
	int actual = calc.sum("0");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, Sum1MShouldBe1M)
{
	Calc calc;
	int expected = 1000000;
	int actual = calc.sum("1000000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, Val75and125ShouldBe200)
{
	Calc calc;
	int expected = 200;
	int actual = calc.sum("75,125");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigVal_1)
{
	Calc calc;
	int expected = std::numeric_limits<int>::max();
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2 + 1);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigVal_2)
{
	Calc calc;
	int expected = std::numeric_limits<int>::max();
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2 + 1);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, AnyNegValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-1");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, AnyNegValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-1000000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, AnyNegValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("-10,10");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, AnyNegValIsError4)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,-10");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, StringValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, StringValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,10");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, StringValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,val2");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, StringValIsError4)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,val2");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, StringValIsError5)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("val1,val2");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FloatingPointValIsError1)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10.0,20");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FloatingPointValIsError2)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10,20.0");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FloatingPointValIsError3)
{
	Calc calc;
	int expected = -1;
	int actual = calc.sum("10.0,20.0");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigValIsError1)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum((expr+",10").c_str());
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigValIsError2)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum(("10," + expr).c_str());
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigValIsError3)
{
	Calc calc;
	int expected = -1;
	std::string expr1 = std::to_string(std::numeric_limits<int>::max()/2 + 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max()/2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, VeryBigValIsError4)
{
	Calc calc;
	int expected = -1;
	std::string expr1 = std::to_string(std::numeric_limits<int>::max() / 2);
	std::string expr2 = std::to_string(std::numeric_limits<int>::max() / 2 + 2);
	int actual = calc.sum((expr1 + "," + expr2).c_str());
	ASSERT_EQ(expected, actual);
}
/**/
// Чисел более 2-х

TEST_F(CalcTest, ThreeVal_Success)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, ThreeValThirdNegValIsError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,-1");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, ThreeValThirdNegValIsError2)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,-1000000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, ThreeValThirdStringValError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,val3");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, ThreeValThirdFloatingPointValIsError)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,val3");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, ThreeValThirdVeryBigValIsError)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum(("10,100," + expr).c_str());
	ASSERT_EQ(expected, actual);
}


TEST_F(CalcTest, FourVal_Success)
{
	Calc calc;
	int expected = 11110;
	int actual = calc.sum("10,100,1000,10000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FourValFouthNegValIsError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,-1");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FourValFouthNegValIsError2)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,-1000000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FourValFouthStringValError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,val3");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FourValFouthFloatingPointValIsError)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,10.0");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FourValFouthVeryBigValIsError)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum(("10,100,1000," + expr).c_str());
	ASSERT_EQ(expected, actual);
}


TEST_F(CalcTest, FiveVal_Success)
{
	Calc calc;
	int expected = 111110;
	int actual = calc.sum("10,100,1000,10000,100000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FiveValFifthNegValIsError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,10000,-1");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FiveValFifthNegValIsError2)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,10000,-1000000");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FiveValFifthStringValError1)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,10000,val3");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FiveValFifthFloatingPointValIsError)
{
	Calc calc;
	int expected = 1110;
	int actual = calc.sum("10,100,1000,10000,10.0");
	ASSERT_EQ(expected, actual);
}

TEST_F(CalcTest, FiveValFifthVeryBigValIsError)
{
	Calc calc;
	int expected = -1;
	std::string expr = std::to_string((std::int64_t)(std::numeric_limits<int>::max()) + 1);
	int actual = calc.sum(("10,100,1000,10000," + expr).c_str());
	ASSERT_EQ(expected, actual);
}
/**/