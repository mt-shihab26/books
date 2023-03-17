while True:
    n = input("Please enter a positive integer. Enter 0 to quit: ")
    n = int(n)
    if n == 0:
        break
    if n < 0:
        print("You must enter a positive integer. Please try again.")
        continue
    
    print("Factors of", n, ":", end=' ')
    for i in range(1, n+1):
        if n % i == 0:
            print(i, end=' ')

    print("\n")