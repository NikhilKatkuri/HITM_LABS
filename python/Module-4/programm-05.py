# Write a python program to 
# check a given phone number is valid or not.

import re

def isValid(pnum):
      pattern = r'[6-9]\d{9}'
      if re.match(pattern,pnum):
            return True
      return False

pnum=input("Enter your mobile number : ")
print(isValid(pnum))
