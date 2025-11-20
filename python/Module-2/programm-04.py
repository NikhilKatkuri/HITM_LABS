# Write a program to perform union, intersection and difference using Set A and Set B.
 
A= set(map(int, input("Enter Set A elements separated by space : ").split()))
B= set(map(int, input("Enter Set B elements separated by space : ").split()))

Union_AB = A.union(B)
Intersection_AB = A.intersection(B)
Intersection_BA = B.intersection(A)
Difference_AB = A.difference(B)
Difference_BA = B.difference(A)

print("Set A :", A)
print("Set B :", B)
print("Union of Set A and Set B :", Union_AB)
print("Intersection of Set A and Set B :", Intersection_AB)
print("Intersection of Set B and Set A :", Intersection_BA)
print("Difference of Set A and Set B (A - B) :", Difference_AB)
print("Difference of Set B and Set A (B - A) :", Difference_BA)
