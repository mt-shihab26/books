class my_range:
    def __init__(self, n):
        self.index = 0
        self.max_index = n - 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.index <= self.max_index:
            self.index += 1
            return self.index - 1
        else:
            raise StopIteration


if __name__ == "__main__":
    for i in my_range(5):
        print(i)
    it = my_range(5)
    while True:
        try:
            print(next(it))
        except StopIteration:
            break
