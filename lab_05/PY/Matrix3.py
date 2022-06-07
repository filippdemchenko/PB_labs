from TMatrix import TMatrix

class Matrix3(TMatrix):
    def __init__(self):
        super().__init__(3)

    def Det(self):
        return self.matrix[0][0] * self.matrix[1][1] * self.matrix[2][2] +  self.matrix[0][1] * self.matrix[1][2] * self.matrix[2][0] + self.matrix[1][0] * self.matrix[2][1] * self.matrix[0][2] - self.matrix[0][2] * self.matrix[1][1] * self.matrix[2][0] - self.matrix[0][1] * self.matrix[1][0] * self.matrix[2][2] - self.matrix[1][2] * self.matrix[2][1] * self.matrix[0][0]