# Write a Python program to create two threads 
# where thread1 will print the value from 1-20
# and thread2 prints from 21-40.

import threading
import time

def print_1_to_20():
    for i in range(1, 21):
        print("Thread 1:", i)
        time.sleep(0.1)    

def print_21_to_40():
    for i in range(21, 41):
        print("Thread 2:", i)
        time.sleep(0.1)

 
t1 = threading.Thread(target=print_1_to_20)
t2 = threading.Thread(target=print_21_to_40)
 
t1.start()
t2.start()

t1.join()
t2.join()

print("Both threads finished.")
