# Write a recursive function to 
# compute fibonacci series

fibo=[0,1]

def fibonacci(n):
    if n <= 0:
        return fibo[0]
    elif n == 1:
        return fibo[1]
    else:
        for i in range(2, n+1):
            next_fib = fibo[i-1] + fibo[i-2]
            fibo.append(next_fib)
        return fibo
    
num = 7
result = fibonacci(num)
print(f"Fibonacci series up to {num} terms is: {result}")