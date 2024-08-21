#include <iostream>
#include <vector>
#include "trading_algorithms.h"
#include "market_data.h"

void exampleAlgorithm(const std::vector<MarketData>& marketData) {
    // Example trading algorithm
    for (const auto& data : marketData) {
        if (data.bidPrice > 100.00) {
            std::cout << "Buying " << data.symbol << " at " << data.bidPrice << std::endl;
        } else {
            std::cout << "Not buying " << data.symbol << " as bid price is too low." << std::endl;
        }
    }
}
