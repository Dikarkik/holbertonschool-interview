#!/usr/bin/python3
"""
Given a number n, write a method that calculates the fewest
number of operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    len = 1
    operations = 0
    copy = 0

    while (len <= n):

        if (len == n):
            return operations

        """ "Copy All" """
        if (n % len == 0):
            copy = len
            operations += 1

        """ "Paste" """
        len = len + copy
        operations += 1

    return 0
