#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <vector>

struct MarketData {
    std::string symbol;
    double bidPrice;
    double askPrice;
};

class MarketDataAPI {
public:
    MarketDataAPI(const std::string& apiKey);
    std::vector<MarketData> fetchMarketData(const std::vector<std::string>& symbols);

private:
    std::string apiKey;
    std::string fetchDataFromAPI(const std::string& symbol);
};

#endif // MARKET_DATA_H
