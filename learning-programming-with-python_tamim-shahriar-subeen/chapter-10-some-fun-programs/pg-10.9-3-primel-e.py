def is_primel_2(n):
    if n < 2:
        return False
    prime = True
    for x in range(2, n):
        if n % x == 0:
            print(n, "is divisible by", x)
            prime = False
            break
    return prime


while True:
    number = int(input("Please enter a number (enter 0 to exit): "))
    prime = is_primel_2(number)
    if number is 0:
        break
    elif prime is True:
        print(number, "is a prime number.")
    else:
        print(number, "is not a prime number")
