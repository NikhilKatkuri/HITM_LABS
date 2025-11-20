# Write a program to create an employee class and store the employee name, id, age, and
# salary using the constructor. Display the employee details by invoking employee_info ()
# method and also using dictionary(__dict__)

class Employee:
    def __init__(self, name, emp_id, age, salary):
        self.name = name
        self.emp_id = emp_id
        self.age = age
        self.salary = salary

    def employee_info(self):
        print(f"Employee Name: {self.name}")
        print(f"Employee ID: {self.emp_id}")
        print(f"Employee Age: {self.age}")
        print(f"Employee Salary: {self.salary}")

    def employee_info_dict(self):
        print(self.__dict__) 

emp = Employee("Nikhil", 7, 18, 9999999)
emp.employee_info()
emp.employee_info_dict()