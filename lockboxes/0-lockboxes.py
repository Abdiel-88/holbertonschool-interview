#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1.
Each box may contain keys to other boxes.

Write a function that determines if all the boxes can be opened.
    Prototype: def canUnlockAll(boxes)
    - boxes is a list of lists
    - A key with the same number as a box opens that box
    - You can assume all keys will be positive integers
    - Some keys may not correspond to any box
    - The first box (boxes[0]) is unlocked initially
    - Return True if all boxes can be opened; otherwise, return False
"""

def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked.

    Args:
        boxes (list of list of int): A list where each sublist contains keys
                                     to other boxes. The box at index i contains
                                     keys to the boxes represented by the integers
                                     in its sublist.

    Returns:
        bool: True if every box can be unlocked, False otherwise.
    """
    n = len(boxes)  # Total number of boxes.
    opened = [False] * n  # List to keep track of which boxes are opened.
    opened[0] = True  # The first box is initially unlocked.
    stack = [0]  # Start with the first box.

    # Use a stack to perform depth-first search.
    while stack:
        current_box = stack.pop()  # Get the most recent box.
        for key in boxes[current_box]:  # Check each key in the current box.
            if 0 <= key < n and not opened[key]:  # Validate key and box.
                opened[key] = True  # Mark the box as unlocked.
                stack.append(key)  # Add the newly unlocked box to the stack.

    # Return True if all boxes are opened, False otherwise.
    return all(opened)
