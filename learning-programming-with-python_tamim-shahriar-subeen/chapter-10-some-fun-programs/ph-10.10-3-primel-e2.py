def is_primel_3(n):
    if n == 2:
        return True  # 2 is prime
    if n % 2 == 0:
        print(n, "is divisible by 2")
        return False  # all even numbers except 2 are not prime
    if n < 2:
        return False  # numbers less then 2 are not prime
    prime = True
    for x in range(3, n, 2):
        if n % x == 0:
            print(n, "is divisible by", x)
            prime = False
            break
    return prime


while True:
    number = int(input("Please enter a number (enter 0 to exit): "))
    prime = is_primel_3(number)
    if number is 0:
        break
    elif prime is True:
        print(number, "is a prime number.")
    else:
        print(number, "is not a prime number")
