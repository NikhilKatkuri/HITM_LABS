# Write a Python Program to find the 
# roots of a quadratic equation and handle the
# appropriate exception.

class QuadraticEquation:
    def __init__(self):
        self.a = float(input("Enter coefficient a: "))
        self.b = float(input("Enter coefficient b: "))
        self.c = float(input("Enter coefficient c: "))

    def find_roots(self):
        try: 
            discriminant = self.b**2 - 4*self.a*self.c
           
            if discriminant < 0 :
                  realPart= -self.b/2*self.a
                  imgPart=(discriminant**0.5)/2*self.a
                  return (f"roots are complex and different\nroot 1 : {realPart}+i{imgPart}\nroot 2 : {realPart}-i{imgPart}")

            elif discriminant==0:
                  return (f"roots are real and equal {-self.b/2*self.a}")
            else:
                  root1 = (-self.b + discriminant**0.5) / (2*self.a)
                  root2 = (-self.b - discriminant**0.5) / (2*self.a)
                  return f"The roots are: {root1} and {root2}"

        except ZeroDivisionError:
            return "Coefficient 'a' cannot be zero."
        except ValueError as ve:
            return str(ve)
        
print(QuadraticEquation().find_roots())
