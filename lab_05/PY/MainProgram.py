
from Matrix2 import Matrix2
from Matrix3 import Matrix3

A = Matrix3()
B = Matrix2()

A.EnterMatrix()
B.EnterMatrix()

print(f"sum(A) = {A.Sum()}")
print(f"det(A) = {A.Det()}")
print(f"det(B) = {B.Det()}")

print(f"sum(A) + det(A) + det(B) = {A.Sum() + A.Det() + B.Det()}")
