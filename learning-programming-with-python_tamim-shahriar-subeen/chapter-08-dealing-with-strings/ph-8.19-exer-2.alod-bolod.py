# I do it

input_str = input("Please input a string: ")
length = len(input_str)

new_str = ""

i = 0
if length % 2 == 0:
    while i < length:
        first_value = input_str[i]
        new_str = new_str + input_str[i+1]
        new_str = new_str + first_value
        i += 2
else:
    while i < length-1:
        first_value = input_str[i]
        new_str = new_str + input_str[i+1]
        new_str = new_str + first_value
        i += 2
    new_str = new_str + input_str[i]

print(new_str)
