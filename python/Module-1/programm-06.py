# Read 4 numbers and find maximum and minimum among those numbers

numbers = []
for i in range(4):
    num = float(input(f"Enter number {i+1}: "))
    numbers.append(num)

max_num = max(numbers)
min_num = min(numbers)

print("Maximum number is:", max_num)
print("Minimum number is:", min_num)
