#!/usr/bin/python3
''' module: island perimeter '''


def island_perimeter(grid):
    ''' function that returns the perimeter of
    the island described in grid '''
    y = 0
    x = 0
    total = 0
    for y in range(len(grid)):
        for x in range(len(grid[1])):
            if grid[y][x] == 1:

                if x == len(grid[0]) - 1:
                    total += 1
                elif grid[y][x + 1] == 0:
                    total += 1

                if x == 0:
                    total += 1
                elif grid[y][x - 1] == 0:
                    total += 1

                if y == len(grid) - 1:
                    total += 1
                elif grid[y + 1][x] == 0:
                    total += 1

                if y == 0:
                    total += 1
                elif grid[y - 1][x] == 0:
                    total += 1
    return total
