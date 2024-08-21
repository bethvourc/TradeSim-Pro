#include <cassert>
#include "trading_algorithms.h"
#include "market_data.h"

void testExampleAlgorithm() {
    std::vector<MarketData> testData = {
        {"AAPL", 150.00, 151.00},
        {"GOOGL", 2800.00, 2805.00}
    };

    exampleAlgorithm(testData);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}