def add_numbers(numbers):
    result = 0
    for i in numbers:
        result += i
        #print("number =", i)
    return result


result = add_numbers([1, 2, 30, 4, 5, 9])
print(result)
