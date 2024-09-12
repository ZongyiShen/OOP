#include <gtest/gtest.h>
#include "../src/LogicSimulator.h"

// 使用 Google Test 进行单元测试
class LogicSimulatorTest : public ::testing::Test {
protected:
    LogicSimulator simulator;

    void SetUp() override {
        // 在每个测试之前进行设置
        // 可以添加初始化代码
    }

    void TearDown() override {
        // 在每个测试之后进行清理
        simulator.clearCircuit();
    }
};

// 测试加载电路文件
TEST_F(LogicSimulatorTest, LoadCircuit) {
    // 使用一个示例电路文件路径
    std::string filePath = "testfile.lcf";
    bool result = simulator.loadCircuit(filePath);

    // 验证电路是否成功加载
    ASSERT_TRUE(result);
}

// 测试电路的模拟
TEST_F(LogicSimulatorTest, Simulation) {
    std::string filePath = "testfile.lcf";
    simulator.loadCircuit(filePath);

    std::vector<int> inputs = {1, 0, 1, 0}; // 根据你的电路文件设置输入值
    std::string result = simulator.simulate(inputs);

    // 根据预期输出验证结果
    std::string expectedOutput = "1 0 1 0 | 1 0 1 "; // 根据电路逻辑填充正确的预期输出
    EXPECT_EQ(result, expectedOutput);
}

// 测试生成真值表
TEST_F(LogicSimulatorTest, TruthTable) {
    std::string filePath = "testfile.lcf";
    simulator.loadCircuit(filePath);

    std::string truthTable = simulator.getTruthTable();

    // 根据电路的预期真值表进行验证
    std::string expectedTruthTable = "i 1 | o 1 \n0 | 0 \n1 | 1 \n";
    EXPECT_EQ(truthTable, expectedTruthTable);
}
