# Write a python program to perform 
# multiplication of two square matrices

import numpy as np

list_a = [[int(input(f"Enter element at position [{i}][{j}] for first matrix: ")) for j in range(3)] for i in range(3)]
list_b = [[int(input(f"Enter element at position [{i}][{j}] for second matrix: ")) for j in range(3)] for i in range(3)]

a = np.array(list_a)
b = np.array(list_b)

print(f"multiplication of two matrices:\n{np.dot(a, b)}")