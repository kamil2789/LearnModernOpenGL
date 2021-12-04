#include <fstream>
#include <string>
#include <filesystem>
#include "ShaderFileReader.h"

#include "gtest\gtest.h"

TEST(ShaderFileReader, readSrc_VertexShaderExists_ReturnValidData)
{
    const std::string sourceCode{"#ExampleSourceCode 100\n output\n\n"};
    const std::string path{"shaders/vertex/"};
    const std::string file{"test.vert"};

    std::ofstream testFile{path + file};
    testFile << sourceCode;
    testFile.close();

    auto result = ShaderFileReader::readSrcFromFile(file);

    EXPECT_EQ(sourceCode, result);
    ASSERT_TRUE(std::filesystem::remove(path + file));
}

TEST(ShaderFileReader, readSrc_FragmentShaderExists_ReturnValidData)
{
    const std::string sourceCode{"#ExampleSourceCode 100\n output\n\n"};
    const std::string path{"shaders/fragment/"};
    const std::string file{"test.frag"};

    std::ofstream testFile{path + file};
    testFile << sourceCode;
    testFile.close();

    auto result = ShaderFileReader::readSrcFromFile(file);

    EXPECT_EQ(sourceCode, result);
    ASSERT_TRUE(std::filesystem::remove(path + file));
}

TEST(ShaderFileReader, readSrc_FileNotExist_ThrowException)
{
    const std::string sourceCode{"#ExampleSourceCode 100\n output\n\n"};
    const std::string file{"test.vert"};

    EXPECT_THROW(ShaderFileReader::readSrcFromFile(file), std::invalid_argument);
}

TEST(ShaderFileReader, readSrc_FileWithInvalidExtension_ThrowException)
{
    const std::string sourceCode{"#ExampleSourceCode 100\n output\n\n"};
    const std::string path{"shaders/vertex/"};
    const std::string file{"test.verte"};

    try
    {
        auto result = ShaderFileReader::readSrcFromFile(file);
    }
    catch(const std::invalid_argument& error)
    {
        EXPECT_EQ(std::string{"Invalid file extension"}, error.what());
    }
}