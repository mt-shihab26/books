dt = {"a": "A", "b": "B", "c": "C"}
dt[(1, 2, 3)] = "tuple"
print(dt)

li = [1, 2, 3]
dt[li] = "list"

s = {1, 2, 3, 4}

dt[s] = "set"
