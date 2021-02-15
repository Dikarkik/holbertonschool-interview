#!/usr/bin/python3
"""
Method that determines if a given data set represents a valid UTF-8 encoding.
The data will be represented by a list of integers.
Each integer represents 1 byte of data.
"""

def validUTF8(data):
	pending_segments = 0

	for n in data:
		byte = format(n, '#010b')

		# check for pending segments of a sequences
		if pending_segments > 0:
			if byte[0:4] == '0b10':
				pending_segments -= 1
				continue
			else:
				return False

		# check for initial sequences
		if byte[0:7] == '0b11110':
			pending_segments = 3
			continue
		elif byte[0:6] == '0b1110':
			pending_segments = 2
			continue
		elif byte[0:5] == '0b110':
			pending_segments = 1
			continue

		# check error: segment without predecessor
		if byte[0:4] == '0b10':
			return False

		# check error: not a valid individual segment
		if byte[0:3] != '0b0':
			return False

	return True
