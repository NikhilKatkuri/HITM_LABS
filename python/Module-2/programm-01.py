# Write a program to check whether the given input is digit or lowercase character or
# uppercase character or a special character (use 'if-else-if' ladder)

char = input("Enter a character: ")

if char.isdigit():
    print(f"{char} is a digit.")
elif char.isupper():
    print(f"{char} is an uppercase character.")
elif char.islower():
      print(f"{char} is a lowercase character.")      
else:
    print(f"{char} is a special character.")
