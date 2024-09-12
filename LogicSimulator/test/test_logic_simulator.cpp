#include <gtest/gtest.h>
#include "../src/LogicSimulator.h"

// Unit tests using Google Test
class LogicSimulatorTest : public ::testing::Test {
protected:
    LogicSimulator simulator;

    void SetUp() override {
        // Setup before each test
        // Initialization code can be added here
    }

    void TearDown() override {
        // Cleanup after each test
        simulator.clearCircuit();
    }
};

// Test loading the circuit file
TEST_F(LogicSimulatorTest, LoadCircuit) {
    // Use a sample circuit file path
    std::string filePath = "testfile.lcf";
    bool result = simulator.loadCircuit(filePath);

    // Verify that the circuit was loaded successfully
    ASSERT_TRUE(result);
}

// Test the circuit simulation
TEST_F(LogicSimulatorTest, Simulation) {
    std::string filePath = "testfile.lcf";
    simulator.loadCircuit(filePath);

    std::vector<int> inputs = {1, 0, 1, 0}; // Set input values based on your circuit file
    std::string result = simulator.simulate(inputs);

    // Verify the result based on the expected output
    std::string expectedOutput = "1 0 1 0 | 1 0 1 "; // Fill with the correct expected output based on the circuit logic
    EXPECT_EQ(result, expectedOutput);
}

// Test generating the truth table
TEST_F(LogicSimulatorTest, TruthTable) {
    std::string filePath = "testfile.lcf";
    simulator.loadCircuit(filePath);

    std::string truthTable = simulator.getTruthTable();

    // Verify the truth table based on the expected table
    std::string expectedTruthTable = 
    string s = R"(i i i i | o o o
1 2 3 4 | 1 2 3 
--------+------
0 0 0 0 | 1 0 1 
0 0 0 1 | 1 0 0 
0 0 1 0 | 1 0 1 
0 0 1 1 | 1 0 0 
0 1 0 0 | 1 0 1 
0 1 0 1 | 1 0 0 
0 1 1 0 | 1 0 1 
0 1 1 1 | 1 0 0 
1 0 0 0 | 1 0 1 
1 0 0 1 | 1 0 0 
1 0 1 0 | 1 0 1 
1 0 1 1 | 1 0 0 
1 1 0 0 | 0 0 1 
1 1 0 1 | 0 0 0 
1 1 1 0 | 0 1 1 
1 1 1 1 | 0 1 0 
)";
    EXPECT_EQ(truthTable, expectedTruthTable);
}

