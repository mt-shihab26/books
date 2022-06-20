while True:
    n = input ("Please enter a positive integer. Enter 0 to quit: ")
    n = int(n)
    if n == 0:
        break

    if n < 0:
        print("You must enter a positive integer. Please try again.")
        continue
    
    factors = [1, n]

    for i in range(2, (n//2) + 1): # (n / 2) + 1
        if n % i == 0:
            factors.append(i)
    
    factors = sorted(factors)
    print("Factors of", n, ":", factors)
    print("\n")
