#include <gtest/gtest.h>
#include "../src/LogicSimulator.h"  // Include your header file

class LogicSimulatorTest : public ::testing::Test {
protected:
    LogicSimulator simulator;

    void SetUp() override {
        // Optional: Set up any shared test data here
    }

    void TearDown() override {
        // Optional: Clean up any resources here
    }
};

TEST_F(LogicSimulatorTest, LoadCircuitValidFile) {
    ASSERT_TRUE(simulator.loadCircuit("valid_circuit.lcf"));
}

TEST_F(LogicSimulatorTest, LoadCircuitInvalidFile) {
    ASSERT_FALSE(simulator.loadCircuit("invalid_circuit.lcf"));
}

TEST_F(LogicSimulatorTest, Simulate) {
    simulator.loadCircuit("valid_circuit.lcf");
    vector<int> inputs = {1, 0}; // Example input
    string result = simulator.simulate(inputs);
    // You may want to verify the expected result
    ASSERT_EQ(result, "expected result");
}

TEST_F(LogicSimulatorTest, GetTruthTable) {
    simulator.loadCircuit("valid_circuit.lcf");
    string truthTable = simulator.getTruthTable();
    // Verify the expected format or content of the truth table
    ASSERT_NE(truthTable.find("expected header"), string::npos);
}
