# https://leetcode.com/problems/roman-to-integer/description/

class Solution:
    def romanToInt(self, s: str) -> int:
        # initialize empty number to keep track
        number = 0

        # initialize a flag to know when to skip the next character if it was already accounted for
        skip = False

        # iterate through each character in the string of roman numerals
        for i, c in enumerate(s):
            # check that we aren't on the last character of the string
            if(i < len(s) - 1 and skip == False):
                # identify current character
                match c:
                    case 'I':
                        match s[i + 1]:
                            # 'I' can be subtracted from 'X' to make 9
                            case 'X':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'IX'
                                number += 9
                            # 'I' can be subtracted from 'V' to make 4
                            case 'V':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'IV'
                                number += 4
                            # 'I' cannot be subtracted from the next character
                            case _:
                                # increment number by 'I'
                                number += 1
                    case 'V':
                        # 'V' can not be subtracted from anything, increment number by 'V'
                        number += 5
                    case 'X':
                        match s[i + 1]:
                            # 'X' can be subtracted from 'C' to make 90
                            case 'C':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'XC'
                                number += 90
                            # 'X' can be subtracted from 'L' to make 40
                            case 'L':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'XL'
                                number += 40
                            # 'X' cannot be subtracted from the next character
                            case _:
                                # increment number by 'X'
                                number += 10
                    case 'L':
                        # 'L' can not be subtracted from anything, increment number by 'L'
                        number += 50
                    case 'C':
                        # check next letter to see if we are subtracting from it
                        match s[i + 1]:
                            # 'C' can be subtracted from 'M' to make 900
                            case 'M':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'CM'
                                number += 900
                            # 'C' can be subtracted from 'D' to make 400
                            case 'D':
                                # set skip flag to true so we know to skip the next character
                                skip = True
                                # increment number by 'CD'
                                number += 400
                            # 'C' cannot be subtracted from the next character
                            case _:
                                # increment number by 'C'
                                number += 100
                    case 'D':
                        # 'D' can not be subtracted from anything, increment number by 'D'
                        number += 500
                    case 'M':
                        # 'M' can not be subtracted from anything, increment number by 'M'
                        number += 1000
            # next character was already accounted for in last calculation, skip it
            elif skip:
                # reset skip flag
                skip = False
                continue
            # we are on the last character
            else:
                # identify current character
                match c:
                    # add the last character on (last character was already skipped if needed)
                    case 'I':
                        number += 1
                    case 'V':
                        number += 5
                    case 'X':
                        number += 10
                    case 'L':
                        number += 50
                    case 'C':
                        number += 100
                    case 'D':
                        number += 500
                    case 'M':
                        number += 1000

        return number

# Extra scripting for running manually without LeetCode's test cases
solution = Solution()

s = input("Enter a roman numeral to convert: ")
number = solution.romanToInt(s)
print(f"{s} is equal to {number}.")