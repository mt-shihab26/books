fib_x = 1
fib_next = 1
n = int(input())

if n <= 2:
    fib_n = 1
else:
    i = 3
    while i <= n:
        i += 1
        fib_next, fib_x = fib_next + fib_x, fib_next
        """
        fib_temp = fib_x + fib_next
        fib_x = fib_next
        fib_next = fib_temp
        """
    fib_n = fib_next

print(fib_n)
