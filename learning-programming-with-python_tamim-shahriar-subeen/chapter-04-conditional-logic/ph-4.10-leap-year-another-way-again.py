year = input("plase enter a Year: ")
year = int(year)

if year % 100 != 0 and year % 4 == 0:
    print(year, "is Leap year")
elif year % 100 == 0 and year % 4 == 0:
    print(year, "is Leap Year")
else:
    print(year, "is not Leap year")
