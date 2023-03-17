import math


def is_primel_5(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    m = math.sqrt(n)
    m = int(m) + 1
    for x in range(3, m, 2):
        if n % x == 0:
            return False
    return True


while True:
    number = int(input("Please enter a number (enter 0 to exit): "))
    prime = is_primel_5(number)
    if number is 0:
        break
    elif prime is True:
        print(number, "is a prime number.")
    else:
        print(number, "is not a prime number")
