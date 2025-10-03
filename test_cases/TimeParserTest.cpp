#include <gtest/gtest.h>
#include "../TimeParser.h"


TEST(ComplexChars, TestCaseCharsCorrectInput) {
    char char_test[] = "R,700,Y,200,G,200";
    ASSERT_EQ(checkChars(char_test), -1);
}
TEST(ComplexChars, TestCaseCharsNullValue) {
    ASSERT_EQ(checkChars(NULL), CHARACTERS_NULL_ERROR);
}
TEST(ComplexChars, TestCaseCharsWrongInput) {
    char char_test[] = "A, 700, B, 800, C, 9000";
    ASSERT_EQ(checkChars(char_test), WRONG_CHARS_ERROR);
}

// Test suite: TimeParserTest
TEST(TimeParserTest, TestCaseCorrectTime) {

    // Note that this test fails on purpose!!

    // Test with correct time string
    char time_test[] = "141205";
    ASSERT_EQ(time_parse(time_test),51125);

}
TEST(TimeParserTest, TestCaseIncorrectTime) {
    char time_test[] = "256161";
    ASSERT_EQ(time_parse(time_test),TIME_VALUE_ERROR);
}
TEST(TimeParserTest, TestCaseArrayError) {
    char a = 'Y';
    ASSERT_EQ(time_parse(&a), TIME_ARRAY_ERROR);
}
TEST(TimeParserTest, TestCaseNullValue) {
    ASSERT_EQ(time_parse(NULL), TIME_VALUE_ERROR);
}


// https://google.github.io/googletest/reference/testing.html
// https://google.github.io/googletest/reference/assertions.html
