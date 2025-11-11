# Write a Python program to print even numbers from 2000 to 2100 in a given interval (use
# break).

start =2000
end =2100
for num in range(start, end + 1):
    if num % 2 == 0:
        print(num) 
    if num == end:
        break

# output

# 2000
# 2002
# 2004
# 2006
# ...
# 2096
# 2098
# 2100