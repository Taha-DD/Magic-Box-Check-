def sum_line(matrix, index):
    return sum(matrix[index])

def sum_column(matrix, index):
    return sum(col[index] for col in matrix)

def sum_diagonal(matrix):
    return sum(matrix[index][index] for index in range(len(matrix)))

def sum_anti_diagonal(matrix):
    return sum(matrix[index][len(matrix) - index - 1] for index in range(len(matrix)))

def is_magic(matrix):
    magic = sum(matrix[0])
    return all(sum(row) == magic for row in matrix) and\
           all(sum_column(matrix, i) == magic for i in range(len(matrix))) and \
           sum_diagonal(matrix) == magic and \
           sum_anti_diagonal(matrix) == magic

def is_normal(matrix):
    if is_magic(matrix):
        return False
    return True
    
import numpy as np


rows = int(input("Enter the number of rows: "))
matrix = []

print("Enter the matrix row by row (space-separated values):")
for _ in range(rows):
    row = list(map(float, input().split()))
    matrix.append(row)

np_matrix = np.array(matrix)

print("The matrix is:")
print(np_matrix)
print(f" is magic: {is_magic(matrix)}")
