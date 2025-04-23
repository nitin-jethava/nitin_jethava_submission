def combinationSum(candidates, target):
    result = []

    # Backtracking helper function
    def backtrack(remaining, combo, start):
        if remaining == 0:  # Base case: found a valid combination
            result.append(list(combo))
            return
        for i in range(start, len(candidates)):  # Loop through candidates
            if candidates[i] <= remaining:  # Only consider candidates <= remaining target
                combo.append(candidates[i])  # Add candidate to the current combination
                backtrack(remaining - candidates[i], combo, i)  # Recurse with reduced target
                combo.pop()  # Backtrack by removing the last added candidate

    # Start backtracking with the target and an empty combination
    backtrack(target, [], 0)
    return result

# Test the function
print(combinationSum([2, 3, 6, 7], 7))
