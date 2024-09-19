#include "../src/LogicSimulator.h"
#include <fstream>
#include <string>

// Unit tests using Google Test
class LogicSimulatorTest : public ::testing::Test {
protected:
    LogicSimulator simulator;
    void SetUp() override {
        std::ofstream file("validFile1.lcf");
        file << "4" << std::endl;
        file << "5" << std::endl;
        file << "1 -1 -2 0" << std::endl;
        file << "1 -2 -3 0" << std::endl;
        file << "3 1.1 0" << std::endl;
        file << "1 1.1 2.1 0" << std::endl;
        file << "3 -4 0";
        std::ofstream file2("validFile2.lcf");
        file2 << "3" << std::endl;
        file2 << "3" << std::endl;
        file2 << "1 -1 2.1 3.1 0" << std::endl;
        file2 << "3 -2 0" << std::endl;
        file2 << "2 2.1 -3 0" << std::endl;
        std::ofstream file3("invalidFile1.lcf");
        file3 << "2" << std::endl;
        file3 << "1" << std::endl;
        file3 << "1 -2 -3 0" << std::endl;
        std::ofstream file4("invalidFile2.lcf");
        file4 << "2" << std::endl;
        file4 << "1" << std::endl;
        file4 << "1 -1 2.2 0" << std::endl;
        std::ofstream file5("invalidFile3.lcf");
        file5 << "2" << std::endl;
        file5 << "1" << std::endl;
        file5 << "4 -1 2.2 0" << std::endl;
        
    }

    void TearDown() override {
        // Cleanup after each test
        remove("validFile1.lcf");
        remove("validFile2.lcf");
        remove("invalidFile1.lcf");
        remove("invalidFile2.lcf");
        remove("invalidFile3.lcf");
        simulator.clearCircuit();
    }
};

// Test loading the circuit file
TEST_F(LogicSimulatorTest, LoadCircuitSuccess) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    // Use a sample circuit file path
    std::string filePath = "validFile1.lcf";
    bool result = simulator.loadCircuit(filePath);
    int numInput = simulator.getNumInputs();
    int numOutput = simulator.getNumOutputs();
    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify that the circuit was loaded successfully
    ASSERT_TRUE(result);
    EXPECT_EQ(numInput,4);
    EXPECT_EQ(numOutput,3);

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 4 input pins, 3 output pins and 5 gates\n\n"),std::string::npos);
}

TEST_F(LogicSimulatorTest, LoadCircuitSuccess2) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    // Use a sample circuit file path
    std::string filePath = "validFile2.lcf";
    bool result = simulator.loadCircuit(filePath);
    int numInput = simulator.getNumInputs();
    int numOutput = simulator.getNumOutputs();
    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify that the circuit was loaded successfully
    ASSERT_TRUE(result);
    EXPECT_EQ(numInput,3);
    EXPECT_EQ(numOutput,1);

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 3 input pins, 1 output pins and 3 gates\n\n"),std::string::npos);
}

TEST_F(LogicSimulatorTest, LoadCircuitFailure) {
    // Use a sample circuit file path
    std::string filePath = "testfile1.lcf";
    bool result = simulator.loadCircuit(filePath);
    // Verify that the path is invalid
    ASSERT_FALSE(result);
}

TEST_F(LogicSimulatorTest, LoadCircuitFailure2) {
    // Use a sample circuit file path
    std::string filePath = "invalidFile1.lcf";
    bool result = simulator.loadCircuit(filePath);
    // Verify that the inputIndex is invalid
    ASSERT_FALSE(result);
}

TEST_F(LogicSimulatorTest, LoadCircuitFailure3) {
    // Use a sample circuit file path
    std::string filePath = "invalidFile2.lcf";
    bool result = simulator.loadCircuit(filePath);
    // Verify that the gateIndex is invalid
    ASSERT_FALSE(result);
}

TEST_F(LogicSimulatorTest, LoadCircuitFailure4) {
    // Use a sample circuit file path
    std::string filePath = "invalidFile3.lcf";
    bool result = simulator.loadCircuit(filePath);
    // Verify that the gateTyoe is invalid
    ASSERT_FALSE(result);
}

// Test the circuit simulation
TEST_F(LogicSimulatorTest, Simulation) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    std::string filePath = "validFile1.lcf";
    simulator.loadCircuit(filePath);

    std::vector<int> inputs = {1, 0, 1, 0}; // Set input values based on your circuit file
    std::string result = simulator.simulate(inputs);

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify the result based on the expected output
    std::string expectedOutput = "1 0 1 0 | 1 0 1 "; // Fill with the correct expected output based on the circuit logic
    EXPECT_EQ(result, expectedOutput);

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 4 input pins, 3 output pins and 5 gates\n\n"),std::string::npos);
}

// Test the circuit simulation
TEST_F(LogicSimulatorTest, Simulation2) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    std::string filePath = "validFile2.lcf";
    simulator.loadCircuit(filePath);

    std::vector<int> inputs = {1, 0, 1}; // Set input values based on your circuit file
    std::string result = simulator.simulate(inputs);

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify the result based on the expected output
    std::string expectedOutput = "1 0 1 | 1 "; // Fill with the correct expected output based on the circuit logic
    EXPECT_EQ(result, expectedOutput);

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 3 input pins, 1 output pins and 3 gates\n\n"),std::string::npos);
}

// Test generating the truth table
TEST_F(LogicSimulatorTest, TruthTable) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    std::string filePath = "validFile1.lcf";
    simulator.loadCircuit(filePath);

    std::string truthTable = simulator.getTruthTable();

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify the truth table based on the expected table
    std::string expectedTruthTable = R"(0 0 0 0 | 1 0 1 
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

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 4 input pins, 3 output pins and 5 gates\n\n"),std::string::npos);
}

// Test generating the truth table
TEST_F(LogicSimulatorTest, TruthTable2) {
    std::ostringstream output;
    std::streambuf* orig_cout_streambuf = std::cout.rdbuf(output.rdbuf());

    std::string filePath = "validFile2.lcf";
    simulator.loadCircuit(filePath);

    std::string truthTable = simulator.getTruthTable();

    std::cout.rdbuf(orig_cout_streambuf); // Restore the original buffer

    // Verify the truth table based on the expected table
    std::string expectedTruthTable = R"(0 0 0 | 0 
0 0 1 | 0 
0 1 0 | 0 
0 1 1 | 0 
1 0 0 | 1 
1 0 1 | 1 
1 1 0 | 0 
1 1 1 | 0 
)";
    EXPECT_EQ(truthTable, expectedTruthTable);

    std::string output_str = output.str();
    EXPECT_NE(output_str.find("Circuit: 3 input pins, 1 output pins and 3 gates\n\n"),std::string::npos);
}

