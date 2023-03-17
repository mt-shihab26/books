a = input("Enter the first number: ")
a = int(a)
b = input("Enter the second number: ")
b = int(b)

# main algorithm
# a ও b-এর গসাগু = (a - b) ও b-এর গসাগু 

if b > a:
    #b যদি a-এর চেয়ে বড় হয়, তাহলো তাদেরকে অদলবদল করে দিচ্ছি
    a, b = b, a

while a != b:
    if b == 0: #b-এর মান 0 হলে, গসাগু হবে a, তাই আমরা লুপ থেকে বের হয়ে যাব
        break
    if a > b:
        a = a - b
    else:
        b = b - a

print("GCD is", a)