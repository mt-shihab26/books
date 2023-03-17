input_str = input("Enter a String: ")

length = len(input_str)

end = length - 1
start = 0

while start < int(length/2):
    if input_str[start] == input_str[end]:
        ok = 1
    else:
        ok = 0
    end = end - 1
    start = start + 1

if ok == 1:
    print(input_str, "is palindrome")
else:
    print(input_str, "is not palindrome")
