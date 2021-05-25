#!/usr/bin/python3
"""
Given an n x n 2D matrix, rotate it 90 degrees clockwise.
Do not return anything. The matrix must be edited in-place.
You can assume the matrix will have 2 dimensions and will not be empty.
"""


def rotate_2d_matrix(matrix):

    le = len(matrix)
    matrix_copy = [row[:] for row in matrix]

    for y in range(le):
        for x in range(le):
            matrix[x][(le - 1) - y] = matrix_copy[y][x]
