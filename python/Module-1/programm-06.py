# Read 4 numbers and find maximum and minimum among those numbers

numbers = []
for i in range(4):
    num = float(input(f"Enter number {i+1}: "))
    numbers.append(num)

max_num = max(numbers)
min_num = min(numbers)

print("Maximum number is:", max_num)
print("Minimum number is:", min_num)

# output

# Enter number 1: 1
# Enter number 2: 3
# Enter number 3: 0
# Enter number 4: 16
# Maximum number is: 16.0
# Minimum number is: 0.0

# Enter number 1: 9
# Enter number 2: 1
# Enter number 3: 17
# Enter number 4: -1
# Maximum number is: 17.0
# Minimum number is: -1.0