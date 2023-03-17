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


n1 = int(input("Enter the lower value of range(n1): "))
n2 = int(input("Enter the higher value of range(n2): "))
for x in range(n1, n2+1, 1):
    value = is_primel_5(x)
    if value is True:
        print(x)
