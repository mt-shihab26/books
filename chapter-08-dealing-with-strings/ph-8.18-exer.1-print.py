full_string = input("Enter a string with capitall latter, number, more: ")

length = len(full_string)

string = [" "] * length

for i in full_string:
    if i >= "A" and i <= "Z":
        #string1 += i
        string[0] += i
    elif i >= "a" and i <= "z":
       # string2 += i
        string[1] += i
    elif i >= "1" and i <= "9":
       # string3 += i
        string[2] += i
    else:
        #string4 += i
        string[3] += i


for i in string:
    print(i)
#string1 = string1.strip()
#string2 = string2.strip()
#string3 = string3.strip()
#string4 = string4.strip()
# for i in string:
 #   i = i.strip()

# print(string1)
# print(string2)
# print(string3)
# print(string4)
# for i in string:
 #   print(i)
