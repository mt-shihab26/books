import turtle

name = turtle.textinput("name", "What is your name")
name = name.lower()
if name.startswith("mr"):
    print("Hello Sir, how are you?")
elif name.startswith("mrc") or name.startswith("miss") or name.statswith("ms"):
    print("Hello Madam, how are you?")
else:
    name.capitalize()
    str = "Hi " + name + "! How are you?"
    print(str)

turtle.exitonclick()
