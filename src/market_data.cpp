#include "market_data.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

MarketDataAPI::MarketDataAPI(const std::string& apiKey) : apiKey(apiKey) {}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string MarketDataAPI::fetchDataFromAPI(const std::string& symbol) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + apiKey;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

std::vector<MarketData> MarketDataAPI::fetchMarketData(const std::vector<std::string>& symbols) {
    std::vector<MarketData> marketData;

    for (const auto& symbol : symbols) {
        std::string response = fetchDataFromAPI(symbol);
        auto json = nlohmann::json::parse(response);

        if (json.contains("Global Quote")) {
            auto quote = json["Global Quote"];
            MarketData data;
            data.symbol = symbol;
            data.bidPrice = std::stod(quote["05. price"].get<std::string>());
            data.askPrice = std::stod(quote["05. price"].get<std::string>()) + 0.05;  // Assuming a small spread for ask price
            marketData.push_back(data);
        } else {
            std::cerr << "Error fetching data for symbol: " << symbol << std::endl;
        }
    }

    return marketData;
}
