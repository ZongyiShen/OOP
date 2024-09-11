#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TextUI.h"  // Include your header file

using ::testing::Return;
using ::testing::NiceMock;

class MockLogicSimulator : public LogicSimulator {
public:
    MOCK_METHOD(bool, loadCircuit, (const std::string&), (override));
    MOCK_METHOD(std::string, getTruthTable, (), (override));
    MOCK_METHOD(std::string, simulate, (const std::vector<int>&), (override));
    MOCK_METHOD(int, getNumInputs, (), (override));
};

class TextUITest : public ::testing::Test {
protected:
    NiceMock<MockLogicSimulator> mockSimulator;
    TextUI ui{&mockSimulator};

    void SetUp() override {
        // Optional: Set up any shared test data here
    }

    void TearDown() override {
        // Optional: Clean up any resources here
    }
};

TEST_F(TextUITest, ProcessCommandLoadFile) {
    EXPECT_CALL(mockSimulator, loadCircuit("valid_file.lcf"))
        .WillOnce(Return(true));

    // Capture the output and call the method
    testing::internal::CaptureStdout();
    ui.processCommand(1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("File not found or file format error!"), std::string::npos);
}

TEST_F(TextUITest, ProcessCommandSimulation) {
    EXPECT_CALL(mockSimulator, getNumInputs())
        .WillOnce(Return(2));
    EXPECT_CALL(mockSimulator, simulate(testing::_))
        .WillOnce(Return("1 0"));

    // Capture the output and call the method
    testing::internal::CaptureStdout();
    ui.processCommand(2);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Simulation Result:"), std::string::npos);
}

TEST_F(TextUITest, ProcessCommandTruthTable) {
    EXPECT_CALL(mockSimulator, getTruthTable())
        .WillOnce(Return("Truth Table"));

    // Capture the output and call the method
    testing::internal::CaptureStdout();
    ui.processCommand(3);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Truth table:"), std::string::npos);
}
