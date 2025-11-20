# Given a list of tuples. Write a program to find tuples which have all elements divisible by
# K from a list of tuples. test_list = [(6, 24, 12), (60, 12, 6), (12, 18, 21)], K = 6, Output : [(6,
# 24, 12), (60, 12, 6)]


test_list = [(6, 24, 12), (60, 12, 6), (12, 18, 21)]
tups_divisible = []
K = 6

for tup in test_list: 
      l=len(tup)
      count=0
      for i in tup:
             if i%K !=0:
                  break
             else:
                   count+=1
      if(count == l):
            tups_divisible.append(tup)

print(tups_divisible)
                