#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

for i in range(30):
	print("n = {} -> {}".format(i, minOperations(i)))
