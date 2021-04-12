#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    water = 0
    previous_wall_height = 0
    spaces_between = 0

    for wall in walls:
        if wall == 0 and previous_wall_height > 0:
            spaces_between += 1
        if wall > 0:
            height = min(previous_wall_height, wall)
            water += height * spaces_between
            previous_wall_height = wall
            spaces_between = 0

    return water
