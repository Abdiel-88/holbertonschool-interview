#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """Calculates the fewest number of operations needed to result in exactly
    n H characters in the file.
    
    Args:
        n (int): The number of H characters desired.

    Returns:
        int: The minimum number of operations required, or 0 if impossible.
    """
    if n < 2:
        return 0
    
    operations = 0
    divisor = 2

    # Loop to divide n by its smallest factors
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1
    
    return operations
