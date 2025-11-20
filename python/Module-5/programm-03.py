# Write a Python program to copy the
# content of given file to another a file.

source_file = input("Enter source file name: ")
destination_file = input("Enter destination file name: ")

try:
    with open(source_file, 'r') as sf:
        content = sf.read()

    with open(destination_file, 'w') as df:
        df.write(content)

    print("File copied successfully!")

except FileNotFoundError:
    print("Source file not found!")