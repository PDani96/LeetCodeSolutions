import random

class RandomizedSet:

    def __init__(self):
        self.values = []

    def insert(self, val: int) -> bool:
        if self.values.count(val) > 0:
            return False
        else:
            self.values.append(val)
            return True

    def remove(self, val: int) -> bool:
        if self.values.count(val) > 0:
            self.values.remove(val)
            return True
        else:
            return False

    def getRandom(self) -> int:
        if not self.values:
            raise ValueError("Cannot get random element from an empty set")
        return self.values[random.randint(0, len(self.values) - 1)]


# Test script
if __name__ == "__main__":
    obj = RandomizedSet()
    
    print(obj.insert(1))  # Expected: True
    print(obj.insert(2))  # Expected: True
    print(obj.insert(1))  # Expected: False (1 is already in the set)
    
    print(obj.remove(1))  # Expected: True
    print(obj.remove(3))  # Expected: False (3 is not in the set)
    
    print(obj.insert(3))  # Expected: True
    
    print(obj.getRandom())  # Expected: Random value from {2, 3}
