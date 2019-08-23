#include "gtest/gtest.h"
#include "filterSignLimit.h"

TEST(FilterSignLimitTests, ZeroInputTest)
{
    EXPECT_ANY_THROW(FilterSignLimit filter(0));
}

TEST(FilterSignLimitTests, ValidInputTest)
{
    FilterSignLimit filter(2);
    int subResult = filter.addRecord(20);
    int result = filter.addRecord(20);

    EXPECT_EQ(result, 20);
}

TEST(FilterSignLimitTests, InValidInputTest)
{
    FilterSignLimit filter(2);
    int subResult = filter.addRecord(20);
    int result = filter.addRecord(8);

    EXPECT_EQ(result, 0);
}

TEST(FilterSignLimitTests, NegativeInputTest)
{
    FilterSignLimit filter(2);
    int subResult = filter.addRecord(20);
    int result = filter.addRecord(-20);

    EXPECT_EQ(result, 0);
}

TEST(FilterSignLimitTests, LargeInputTest)
{
    FilterSignLimit filter(2);
    int subResult = filter.addRecord(20);
    int result = filter.addRecord(150);

    EXPECT_EQ(result, 0);
}

TEST(FilterSignLimitTests, FaultToleranceTest)
{
    FilterSignLimit filter(2);
    int subResult1 = filter.addRecord(20);
    int subResult2 = filter.addRecord(20);
    int result = filter.addRecord(23);

    EXPECT_EQ(result, 20);
}

TEST(FilterSignLimitTests, ChangingInputTest)
{
    FilterSignLimit filter(2);
    int subResult1 = filter.addRecord(20);
    int result1 = filter.addRecord(20);

    EXPECT_EQ(result1, 20);

    int subResult2 = filter.addRecord(50);
    int result2 = filter.addRecord(50);

    EXPECT_EQ(result2, 50);
}
