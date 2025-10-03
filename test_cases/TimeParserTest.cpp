#include <gtest/gtest.h>
#include "../TimeParser.h"

// Test suite: TimeParserTest
TEST(TimeParserTest, TestCaseCorrectTime) {

    // Note that this test fails on purpose!!

    // Test with correct time string
    char time_test[] = "141205";
    ASSERT_EQ(time_parse(time_test),0);

}
TEST(timeParserTest, TestCaseIncorrectTime) {
    char time_test[] = "256161";
    ASSERT_EQ(time_parse(time_test),TIME_VALUE_ERROR);
}
TEST(timeParserTest, TestCaseArrayError) {
    char a = 'Y';
    ASSERT_EQ(time_parse(&a), TIME_ARRAY_ERROR);
}

// https://google.github.io/googletest/reference/testing.html
// https://google.github.io/googletest/reference/assertions.html
