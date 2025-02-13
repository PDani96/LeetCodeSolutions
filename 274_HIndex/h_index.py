from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # initialize h-index to 0
        h = 0

        # sort list of citations from high to low
        citations.sort(reverse = True)

        # loop through the numbers of citations for each paper
        for i, num in enumerate(citations):
            # check if the number of citations is greater than the possible h-index (i + 1)
            if num >= i + 1:
                h = i + 1
            else:
                break  # No need to check further

        return h
    
# Test cases
sol = Solution()
print(sol.hIndex([3, 0, 6, 1, 5]))  # Output: 3
print(sol.hIndex([1, 3, 1]))        # Output: 1
print(sol.hIndex([10, 8, 5, 4, 3])) # Output: 4