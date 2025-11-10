# Read a list of numbers and write a program to check whether a particular element is
# present or not using membership operators.

numbers = input("Enter Numbers seprated by space : ")
element = input("Enter Element : ")
number_list = numbers.split()

if element in number_list:
      print(f"{element} present in List")
else :
      print(f"{element} is not present in List")

# output 

# Enter Numbers seprated by space : 12 14 15 16
# Enter Element : 13
# 13 is not present in List

# Enter Numbers seprated by space : 1 2 3 4
# Enter Element : 3
# 3 present in List