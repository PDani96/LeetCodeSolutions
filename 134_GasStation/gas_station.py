from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Check if a complete trip is possible
        if sum(gas) < sum(cost):
            return -1

        # Initialize tank as empty and start at 0
        tank = 0
        start = 0

        for i in range(len(gas)):
            tank += gas[i] - cost[i]  # Refuel and deduct travel cost

            if tank < 0:
                # Reset starting position and empty tank
                start = i + 1
                tank = 0

        return start

if __name__ == "__main__":
    # Example test case
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]

    solution = Solution()
    result = solution.canCompleteCircuit(gas, cost)
    print(f"Starting gas station index: {result}")