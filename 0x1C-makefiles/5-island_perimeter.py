#\!/usr/bin/python3
def island_perimeter(grid):
    perimiter = 0
    for r_idx, row in enumerate(grid):
        for c_idx, column in enumerate(row):
            if column == 1:
                perimiter += count_waters(grid, column, r_idx, c_idx)
    return perimiter


def count_waters(grid, column, r_idx, c_idx):
    water_count = 0

    """up is r_idx - 1, same c_idx"""
    if grid[r_idx - 1][c_idx] == 0:
        water_count += 1

    """down r_idx + 1, same c_idx"""
    if grid[r_idx + 1][c_idx] == 0:
        water_count += 1

    """right same r_idx, c_idx + 1"""
    if grid[r_idx][c_idx + 1] == 0:
        water_count += 1

    """left same r_idx, c_idx - 1"""
    if grid[r_idx][c_idx - 1] == 0:
        water_count += 1

    return water_count
