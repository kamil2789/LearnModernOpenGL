#include "EndToEndTests.h"

#include "gtest\gtest.h"

TEST(EndToEnd, GradientTriangleWithUniform)
{
    EXPECT_TRUE(EndToEndTest::GradientTriangleWithUniformTest());
}