def avear(number_list):
    sum = 0
    for number in number_list:
        sum += number
        length = len(number_list)
        result = sum / length
    return result


ok = [2, 3, 1, 4, 5]
re = avear(ok)
re = int(re)
print(re)
