#include <gmock/gmock.h>
#include "../src/LogicSimulator.h"

class MockLogicSimulator : public LogicSimulator {
public:
    MOCK_METHOD(bool, loadCircuit, (const std::string& filePath), (override));
    MOCK_METHOD(std::string, getTruthTable, (), (override));
    MOCK_METHOD(std::string, simulate, (const std::vector<int>& inputs), (override));
    MOCK_METHOD(int, getNumInputs, (), (override));
    MOCK_METHOD(int, getNumOutputs, (), (override));
    MOCK_METHOD(void, clearCircuit, (), (override));
};
