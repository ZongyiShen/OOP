#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "../src/TextUI.h"
#include "MockLogicSimulator.h"

using ::testing::Return;
using ::testing::NiceMock;

class TextUITest : public ::testing::Test {
protected:
    MockLogicSimulator mockSimulator;
    TextUI textUI{&mockSimulator};
    void SetUp() override {
    }

    void TearDown() override {
        // Cleanup after each test
    }
};

TEST_F(TextUITest, TestLoadFileSuccess) {
    EXPECT_CALL(mockSimulator, loadCircuit("testfile.lcf")).WillOnce(Return(true));

    // Use std::cin to simulate user input
    std::istringstream input("testfile.lcf");
    std::streambuf* orig_cin_streambuf = std::cin.rdbuf(input.rdbuf());

    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(1); // Simulate user choosing to load the file

    std::cin.rdbuf(orig_cin_streambuf); // Restore the original buffer
    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Please key in a file path: "), std::string::npos);
}

TEST_F(TextUITest, TestLoadFileFailure) {
    EXPECT_CALL(mockSimulator, loadCircuit("testfile1.lcf")).WillOnce(Return(false));

    // Use std::cin to simulate user input
    std::istringstream input("testfile1.lcf");
    std::streambuf* orig_cin_streambuf = std::cin.rdbuf(input.rdbuf());

    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(1); // Simulate user choosing to load the file

    std::cin.rdbuf(orig_cin_streambuf); // Restore the original buffer
    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Please key in a file path: "), std::string::npos);
    EXPECT_NE(output_str.find("File not found or file format error!!\n\n"), std::string::npos);
}

TEST_F(TextUITest, TestSimulation) {
    EXPECT_CALL(mockSimulator, getNumInputs()).Times(3).WillRepeatedly(Return(2));
    EXPECT_CALL(mockSimulator, getNumOutputs()).WillOnce(Return(1));
    EXPECT_CALL(mockSimulator, simulate(::testing::ElementsAre(0, 1))).WillOnce(Return("1"));

    // Use std::cin to simulate user input
    std::istringstream input("-1\n0\n1\n");
    std::streambuf* orig_cin_streambuf = std::cin.rdbuf(input.rdbuf());

    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(2); // Simulate user choosing to perform simulation

    std::cin.rdbuf(orig_cin_streambuf); // Restore the original buffer
    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("The value of input pin must be 0/1\n"),std::string::npos);
    EXPECT_NE(output_str.find("Simulation Result:"), std::string::npos);
    EXPECT_NE(output_str.find("1"), std::string::npos);
}

TEST_F(TextUITest, TestSimulationFailure) {
    EXPECT_CALL(mockSimulator, getNumInputs()).WillOnce(Return(0));

    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(2); // Simulate user choosing to perform simulation

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Please load an lcf file, before using this operation.\n\n"), std::string::npos);
}

TEST_F(TextUITest, TestTruthTable){
    EXPECT_CALL(mockSimulator, getTruthTable).WillOnce(Return("1 | 0\n0 | 1\n"));
    EXPECT_CALL(mockSimulator, getNumInputs()).WillOnce(Return(1));
    EXPECT_CALL(mockSimulator, getNumOutputs()).WillOnce(Return(1));

    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(3); // Simulate user choosing to perform simulation

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Truth table: "), std::string::npos);
    EXPECT_NE(output_str.find("1 | 0\n0 | 1\n"), std::string::npos);
}

TEST_F(TextUITest, TestDisplayMenu) {
    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.displayMenu(); // Display the menu

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("1. Load logic circuit file"), std::string::npos);
    EXPECT_NE(output_str.find("2. Simulation"), std::string::npos);
    EXPECT_NE(output_str.find("3. Display truth table"), std::string::npos);
    EXPECT_NE(output_str.find("4. Exit"), std::string::npos);
}

TEST_F(TextUITest, TestProcessCommandInvalid) {
    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(99); // Simulate user choosing an invalid command

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Invalid command!"), std::string::npos);
}

TEST_F(TextUITest, TestProcessCommandExit) {
    // Capture std::cout output
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    textUI.processCommand(4); // Simulate user choosing to exit

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Goodbye, thanks for using LS."), std::string::npos);
}
