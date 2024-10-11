#!/usr/bin/python3
import sys

total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


def print_stats():

    """Prints the accumulated metrics."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


try:

    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        # Ensure the line has the correct format
        # (IP - [date] "GET ..." status_code file_size)
        if len(parts) < 7:
            continue

        # Extract status code and file size
        try:
            status_code = int(parts[-2])
            file_size = int(parts[-1])
            total_size += file_size

            if status_code in status_codes:
                status_codes[status_code] += 1
        except (ValueError, IndexError):
            continue

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise
