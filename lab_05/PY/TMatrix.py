class TMatrix():
    def __init__(self, dimension):
        self.dimension = dimension
        self.matrix = []

    def EnterMatrix(self):
        print(f"Enter {self.dimension} matrix row by row:")
        for i in range(self.dimension):
            self.matrix.append(list(map(int, input().split())))

    def PrintMatrix(self):
        for i in range(self.dimension):
            for j in range(self.dimension):
                print(self.matrix[i][j], end = " ")
            print()

    def Sum(self):
        result = 0
        for i in range(self.dimension):
            for j in range(self.dimension):
                result += self.matrix[i][j]
        return result

    def Det():
        pass