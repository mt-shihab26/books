class my_range:
    def __init__(self, *argv):
        self.start = 0
        self.stop = 0
        self.step = 1
        if len(argv) > 3:
            raise Exception
        elif len(argv) == 1:
            self.stop = argv[0]
        elif len(argv) == 2:
            self.start = argv[0]
            self.stop = argv[1]
        elif len(argv) == 3:
            self.start = argv[0]
            self.stop = argv[1]
            self.step = argv[2]
        self.index = self.start
        self.max_index = self.stop-1

    def __iter__(self):
        return self

    def __next__(self):
        if self.index <= self.max_index:
            self.index += self.step
            return self.index - self.step
        else:
            raise StopIteration


if __name__ == "__main__":
    for i in my_range(2, 9, 2):
        print(i, end=" ")
    print()
    for i in my_range(10):
        print(i, end=" ")
    print()
    for i in my_range(2, 10):
        print(i, end=" ")
    print()
