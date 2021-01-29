#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning: Total file size
and number of lines by status code.
excecute: ./0-generator.py | ./0-stats.py
"""
import sys

count = 0
total_size = 0
status_code = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}


def print_metrics():
    """Method to print the statistics from the beginning"""

    print("File size: {}".format(total_size))

    for key, value in sorted(status_code.items()):
        if value > 0:
            print("{}: {}".format(key, value))

try:
    for line in sys.stdin:

        try:
            code = line.split()[-2]
            if code in status_code.keys():
                status_code[code] += 1
        except BaseException:
            pass

        try:
            size = line.split()[-1]
            total_size += int(size)
        except BaseException:
            pass

        # print metrics every 10 lines
        count += 1
        if (count % 10 == 0):
            print_metrics()

    print_metrics()

except KeyboardInterrupt:
    print_metrics()
    raise
