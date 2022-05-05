# Sliding-Window


Basic template of such problems is basically 3 steps.

Step1: Have a counter or hash-map to count specific array input and keep on increasing the window toward right using outer loop.

Step2: Have a while loop inside to reduce the window side by sliding toward right. Movement will be based on constraints of problem.

Step3: Store the current maximum window size or minimum window size or number of windows based on problem requirement.

Identification includes the problem contains about frequency of letters or numbers. the constraint is like < k or >= k.so we the window according to the condition
->related to substring or subarray
->the number of ways is calculated by using hashmap or by considering number of ways that ends at or starts at.
->subarray must start at index and end at some index take that as refercence to get some results in the question.
->hashmap is used sometimes to count the chars or numbers present in window.
