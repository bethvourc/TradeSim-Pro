#include <iostream>
#include <vector>
#include "trading_algorithms.h"
#include "market_data.h"

int main() {
    std::cout << "Trading Simulation Platform" << std::endl;

    std::string apiKey = "YOUR_ALPHA_VANTAGE_API_KEY";  // Replace with your Alpha Vantage API key
    MarketDataAPI marketDataAPI(apiKey);

    std::vector<std::string> symbols = { "AAPL", "GOOGL" };
    std::vector<MarketData> marketData = marketDataAPI.fetchMarketData(symbols);

    std::cout << "Market Data:" << std::endl;
    for (const auto& data : marketData) {
        std::cout << "Symbol: " << data.symbol << ", Bid: " << data.bidPrice << ", Ask: " << data.askPrice << std::endl;
    }

    std::cout << "Running example trading algorithm..." << std::endl;
    exampleAlgorithm(marketData);

    return 0;
}
