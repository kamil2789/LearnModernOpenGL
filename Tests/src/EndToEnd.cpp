#include "EndToEndTests.h"

#include "gtest/gtest.h"

TEST(EndToEnd, GradientTriangleWithUniform)
{
    EXPECT_TRUE(EndToEndTest::GradientTriangleWithUniformTest());
}

TEST(EndToEnd, ColoredTriangle)
{
    EXPECT_TRUE(EndToEndTest::ColoredTriangleTest());
}

TEST(EndToEnd, TexturedReactangle)
{
    EXPECT_TRUE(EndToEndTest::TexturedReactangleTest());
}