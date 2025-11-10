# Consider two numbers as input and swap those two values without using 3rd variable. 

a,b=input("Enter a : "),input("Enter b : ")
print(f"Before swap a = {a} , b = {b} ")
a,b=b,a
print(f"After swap a = {a} , b = {b} ")

# output 

# Enter a : 12
# Enter b : 13
# Before swap a = 12 , b = 13 
# After swap a = 13 , b = 12

# Enter a : 19
# Enter b : 1 
# Before swap a = 19 , b = 1 
# After swap a = 1 , b = 19 