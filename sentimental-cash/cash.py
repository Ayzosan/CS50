from cs50 import get_float
from math import floor

# user input
while True:
    cowed = get_float("How much change is owed?: ")
    nonintcowed = floor(cowed * 100)
    if cowed > 0:
        break

# changing from float to int

# calculation of coins
quarters = nonintcowed // 25
dimes = (nonintcowed % 25) // 10
nickles = (nonintcowed % 25 % 10) // 5
pennies = (nonintcowed % 25 % 10 % 5) // 1


# printing total
total = quarters + dimes + nickles + pennies
print(total)
