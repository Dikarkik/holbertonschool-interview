#!/usr/bin/python3

def minOperations(n):
	count = 0
	len = 1
	to_add = 1

	while (len <= n):

		if (len == n):
			return count

		# "Copy All"
		if (n % len == 0):
			to_add = len
			count += 1

		# "Paste"
		len = len + to_add
		count += 1

	return 0
