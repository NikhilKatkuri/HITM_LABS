# Read the year and check whether that year is a leap year.

year = int(input("Enter a year: "))

if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
    print(f"{year} is a leap year.")
else:
    print(f"{year} is Ordinary year.")

# output 

# Enter a year: 2000
# 2000 is a leap year.

# Enter a year: 2025 
# 2025 is Ordinary year.