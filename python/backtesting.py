import pandas as pd

def backtest(strategy, data):
    initial_balance = 10000
    balance = initial_balance
    position = 0

    for i in range(len(data)):
        action = strategy(data.iloc[i])
        if action == 'buy' and balance >= data.iloc[i]['Close']:
            position = balance // data.iloc[i]['Close']
            balance -= position * data.iloc[i]['Close']
        elif action == 'sell' and position > 0:
            balance += position * data.iloc[i]['Close']
            position = 0

    final_balance = balance + position * data.iloc[-1]['Close']
    return final_balance - initial_balance

def simple_strategy(row):
    if row['Close'] > row['Open']:
        return 'buy'
    else:
        return 'sell'

# Example usage
data = pd.read_csv('../data/historical_data.csv')
profit = backtest(simple_strategy, data)
print(f'Profit from backtest: ${profit}')
