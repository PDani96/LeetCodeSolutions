from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Initialize profit to 0
        profit = 0

        # Iterate through all prices
        for i, price in enumerate(prices):
            # Check that we are past day one
            if i > 0:
                # Check if a profit could have been made between today and yesterday
                if price > prices[i - 1]:
                    # Add profit
                    profit += price - prices[i - 1]

        return profit

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example test cases
    test_cases = [
        ([7,1,5,3,6,4], 7),
        ([1,2,3,4,5], 4),
        ([7,6,4,3,1], 0),
    ]

    for prices, expected in test_cases:
        result = solution.maxProfit(prices)
        print(f"Prices: {prices} => Max Profit: {result} (Expected: {expected})")
