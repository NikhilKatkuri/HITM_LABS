# Write a function called has_duplicates that takes a 
# list and returns True if there is any
# element that appears more than once. 
# It should not modify the original list.

def has_duplicates(input_list):
    seen = set()
    for item in input_list:
        if item in seen:
            return True
        seen.add(item)
    return False


a=[int(x) for x in input("Enter numbers separated by space: ").split()] 

print(has_duplicates(a))