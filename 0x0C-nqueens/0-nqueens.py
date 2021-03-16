#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking
queens on an N×N chessboard.
"""

import sys


def print_queens_pos(queens_pos):
    # TO DO: print like lists
    print(queens_pos)


def filter(new_queen, queens_pos):
    for queen in queens_pos:
        if (new_queen[0] + new_queen[1]) is (queen[0] + queen[1]):
            return False
        if (new_queen[0] - new_queen[1]) is (queen[0] - queen[1]):
            return False
        if new_queen[1] is queen[1]:
            return False
    return True


def place_queens(n, queens_pos):
    new_queens_y = len(queens_pos)

    for x in range(n):
        new_queen = (new_queens_y, x)

        if filter(new_queen, queens_pos):
            new_queens_pos = queens_pos + (new_queen,)

            if len(new_queens_pos) is n:
                print_queens_pos(new_queens_pos)
            else:
                place_queens(n, new_queens_pos)


def n_queens(n):
    for i in range(n):
        queens_pos = ((0, i),)
        place_queens(n, queens_pos)


if __name__ == "__main__":
    # TO DO: check parameters
    n_queens(int(sys.argv[1]))
