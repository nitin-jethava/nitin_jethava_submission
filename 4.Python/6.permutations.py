from itertools import permutations

# Given input list
nums = [1, 2, 3]

# Generate all possible permutations
perm = list(permutations(nums))

# Print each permutation as a list
for p in perm:
    print(list(p))
