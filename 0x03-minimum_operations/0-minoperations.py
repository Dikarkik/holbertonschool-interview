#!/usr/bin/python3

def minOperations(n):
	len = 1 # "H"
	operations = 0
	copy = 0

	while (len <= n):

		if (len == n):
			return operations

		# "Copy All"
		if (n % len == 0):
			copy = len
			operations += 1

		# "Paste"
		len = len + copy
		operations += 1

	return 0
