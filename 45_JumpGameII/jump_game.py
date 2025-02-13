from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        # Initialize tracker for the furthest possible index we can jump to
        furthest_jump = 0
        # Initialize tracker for current position of the jump
        current_jump = 0
        # Initialize counter for the number of jumps
        jumps = 0

        # Iterate through the numbers in the list (excluding the last element)
        for i in range(len(nums) - 1):
            # Update the furthest we can jump from the current index
            furthest_jump = max(furthest_jump, i + nums[i])

            # Check if we've reached the current jump's boundary
            if i == current_jump:
                jumps += 1
                current_jump = furthest_jump

        return jumps

# Sample test cases
if __name__ == "__main__":
    solution = Solution()

    # Test case 1
    nums1 = [2, 3, 1, 1, 4]
    print(f"Test case 1 - Jumps needed: {solution.jump(nums1)}")  # Expected output: 2

    # Test case 2
    nums2 = [2, 3, 0, 1, 4]
    print(f"Test case 2 - Jumps needed: {solution.jump(nums2)}")  # Expected output: 2

    # Test case 3
    nums3 = [1, 1, 1, 1, 1]
    print(f"Test case 3 - Jumps needed: {solution.jump(nums3)}")  # Expected output: 4

    # Test case 4
    nums4 = [1, 2, 3, 4, 5]
    print(f"Test case 4 - Jumps needed: {solution.jump(nums4)}")  # Expected output: 3
