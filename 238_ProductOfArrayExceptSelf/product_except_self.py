from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Get length of nums array
        n = len(nums)

        # Initialize prefix and suffix product arrays
        prefix = [1] * n
        suffix = [1] * n
        # Initialize answers array
        answers = [1] * n

        # Compute prefix product
        for i in range(1, n):
            prefix[i] = prefix[i - 1] * nums[i - 1]

        # Compute suffix product
        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1]

        # Compute final answer
        for i in range(n):
            answers[i] = prefix[i] * suffix[i]

        return answers

# Example usage:
solution = Solution()
print(solution.productExceptSelf([1, 2, 3, 4]))  # Output: [24, 12, 8, 6]
print(solution.productExceptSelf([-1, 1, 0, -3, 3]))  # Output: [0, 0, 9, 0, 0]