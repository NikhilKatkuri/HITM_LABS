# Write a function called is_sorted that takes a list 
# as a parameter and returns True if the list
# is sorted in ascending order and False otherwise.

def is_sorted(lst):
    for i in range(len(lst) - 1):
        if lst[i] > lst[i + 1]:
            return False
    return True

a=[int(x) for x in input("Enter numbers separated by space: ").split()]
print(is_sorted(a))
