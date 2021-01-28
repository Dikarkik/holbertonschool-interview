#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning: Total file size
and number of lines by status code.
excecute: ./0-generator.py | ./0-stats.py
"""
import sys


def print_metrics(total_size, status_code):
    """Method to print the statistics from the beginning"""

    print("File size: {}".format(total_size))

    for key, value in status_code.items():
        if value > 0:
            print("{}: {}".format(key, value))

count = 0
total_size = 0
status_code = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for line in sys.stdin:

        total_size += int(line.split()[8])

        status_code[line.split()[7]] += 1

        # print metrics every 10 lines
        count += 1
        if (count % 10 == 0):
            print_metrics(total_size, status_code)

    print_metrics(total_size, status_code)

except KeyboardInterrupt:
    print_metrics(total_size, status_code)
    raise
