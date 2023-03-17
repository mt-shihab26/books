s = "Bangladesh"
print(s)

start = s.startswith("Ban")
print("Ban =", start)
start = s.startswith("ban")
print("ban = ", start)
start = s.startswith("an")
print("an =", start)

ends = s.endswith("Ban")
print("Ban =", ends)
ends = s.endswith("desh")
print("desh =", ends)
ends = s.endswith("h")
print("h =", ends)
