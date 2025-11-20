# Write a Python program to compute the 
# number of characters, words and lines in a file
file_name = input("Enter file name: ")

try:
    with open(file_name, 'r') as f:
        text = f.read()

        num_chars = len(text)
        words = text.split()
        num_words = len(words)
        num_lines = text.count('\n') + 1   

    print("Number of Characters:", num_chars)
    print("Number of Lines:", num_lines)
    print("Number of Words:", num_words) 

except FileNotFoundError:
    print("File not found!")
