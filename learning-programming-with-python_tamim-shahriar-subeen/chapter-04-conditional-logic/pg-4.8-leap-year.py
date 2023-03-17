year = input("Plase Enter a Year: ")
year = int(year)

if year % 4 != 0:
    print("no")
else:
    if year % 100 == 0:
        if year % 400 == 0:
            print("Yes")
        else:
            print("no")
    else:
        print("Yes")
