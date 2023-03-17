while True:
    n = input("Plase Enter a positive number (0 to exit): ")
    n = int(n)
    if n < 0:
        print("We only allow Positive number: (please try again)")
        continue
    if n == 0:
        break
    print("Square of", n, "is", n*n)
