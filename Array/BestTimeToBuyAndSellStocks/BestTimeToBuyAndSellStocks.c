int maxProfit(int* prices, int pricesSize) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        min_price = (prices[i] < min_price) ? prices[i] : min_price;
        max_profit = (prices[i] - min_price > max_profit) ? prices[i] - min_price : max_profit;
    }
    return max_profit;
}
