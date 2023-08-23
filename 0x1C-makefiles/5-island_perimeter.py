#!/usr/bin/python3
"""
module
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid
    """
    perimiter = 0
    for r_idx, row in enumerate(grid):
        for c_idx, column in enumerate(row):
            if column == 1:
                perimiter += count_waters(grid, column, r_idx, c_idx)
    return perimiter


def count_waters(grid, column, r_idx, c_idx):
    """
    counts the water around a land
    """
    ru = 0
    rd = 0
    lu = 0
    ld = 0
    water_count = 0
    if r_idx <= 0 and c_idx <= 0:
        water_count += 2
        lu = 1
    if r_idx >= len(grid) - 1 and c_idx >= len(grid[r_idx]) - 1:
        water_count += 2
        rd = 1
    if c_idx <= 0 and r_idx >= len(grid) - 1:
        water_count += 2
        ld = 1
    if r_idx <= 0 and c_idx >= len(grid[r_idx]) - 1:
        water_count += 2
        ru = 1

    """up is r_idx - 1, same c_idx"""
    if (lu == 0 and ru == 0) and (r_idx <= 0 or grid[r_idx - 1][c_idx] == 0):
        water_count += 1

    """down r_idx + 1, same c_idx"""
    if (ld == 0 and rd == 0) and (
        r_idx >= len(grid) - 1 or grid[r_idx + 1][c_idx] == 0
    ):
        water_count += 1

    """right same r_idx, c_idx + 1"""
    if (rd == 0 and ru == 0) and (
        c_idx >= len(grid[r_idx]) - 1 or grid[r_idx][c_idx + 1] == 0
    ):
        water_count += 1

    """left same r_idx, c_idx - 1"""
    if (ld == 0 and lu == 0) and (c_idx <= 0 or grid[r_idx][c_idx - 1] == 0):
        water_count += 1

    return water_count
