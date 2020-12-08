#!/usr/bin/python3

# Exercise: Lockboxes
# Method that determines if all the boxes can be opened.
# Details in README.md


def canUnlockAll(boxes):
    open_boxes = [0] * len(boxes)  # creates and set the list of integers in 0
    open_boxes[0] = 1
    open_boxes = recursion(boxes, boxes[0], open_boxes)

    if 0 in open_boxes:
        return False
    else:
        return True


def recursion(boxes, keys, open_boxes):

    for key in keys:
        if key < len(boxes) and open_boxes[key] == 0:
            open_boxes[key] = 1
            open_boxes = recursion(boxes, boxes[key], open_boxes)

    return open_boxes
