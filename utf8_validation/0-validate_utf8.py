#!/usr/bin/python3
def validUTF8(data):
    # Number of bytes left in the current UTF-8 character
    num_bytes = 0

    # Masks for checking the most significant bits
    mask1 = 1 << 7    # 10000000
    mask2 = 1 << 6    # 01000000

    for byte in data:
        # Extract only the 8 least significant bits of the byte
        byte = byte & 0xFF

        if num_bytes == 0:
            # Determine the number of bytes for the current UTF-8 character
            if (byte >> 5) == 0b110:  # 2-byte character
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3-byte character
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4-byte character
                num_bytes = 3
            elif (byte >> 7):  # Invalid 1-byte character (must start with 0)
                return False
        else:
            # Check that the byte starts with 10xxxxxx
            if not (byte >> 6) == 0b10:
                return False
            num_bytes -= 1

    return num_bytes == 0  # All bytes must be accounted for