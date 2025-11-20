# Write a function to 
# compute factorial



def factorial(n):
    if n==0 or n==1:
        return 1
    else:
        fact =1
        for i in range(2, n+1):
             fact *= i
        return fact
    
num = 5
result = factorial(num)
print(f"Factorial of {num} is {result}")