# Write a recursive function to 
# compute fibonacci series

def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

num_terms = 10
print(f"Fibonacci series up to {num_terms} terms:")
for i in range(num_terms):
    print(fibonacci(i))