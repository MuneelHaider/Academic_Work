import csv
import random

# Generate random numbers
numbers = [random.randint(1, 1000000) for _ in range(100000)]

# Write numbers to a CSV file
with open('numbers.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(numbers)
