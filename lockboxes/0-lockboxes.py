#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    
    Parameters:
    boxes (list of lists): A list where each element is a list of keys available in that box.
    
    Returns:
    bool: True if all boxes can be opened, else False.
    """
    n = len(boxes)
    opened_boxes = [False] * n
    opened_boxes[0] = True  # The first box is always open
    keys = boxes[0]  # Start with keys from the first box

    while keys:
        new_keys = []
        for key in keys:
            if key < n and not opened_boxes[key]:
                opened_boxes[key] = True
                new_keys.extend(boxes[key])  # Add keys from the newly opened box
        keys = new_keys  # Continue with the new set of keys

    return all(opened_boxes)
