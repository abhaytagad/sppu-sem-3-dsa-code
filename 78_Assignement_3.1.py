
from numpy import *

class matrix:

    def __init__(self):

        self.row = int (input("numer of row ??"))
        self.col = int (input("number of col ??"))
        self.M = array([[0 for x in range(self.col)] for x in range(self.row)]) # declared 2d matrix using numpy

    # taking elements of matrix as input from user
        print("enter the elements:")

        for i in range(self.row):
            
            for j in range(self.col):
                ele = int(input())
                self.M[i][j] = ele 

    @staticmethod
    def add(m1, m2):

        # if ((m1.row != m2.row) or (m1.col != m2.col)):

        #     return "addition is not possible"
        
        result = array([[0 for x in range(m1.col)] for x in range(m1.row)])

        for i in range(m1.row):

            for j in range((m1.col)):

                result[i][j] = m1.M[i][j] + m2.M[i][j]

        return result
    
    @staticmethod
    def sub(m1 , m2):

        # if ((m1.row != m2.row) or (m1.col != m2.col)):

        #     return "substraction is not possible"
        
        result = array([[0 for x in range(m1.col)] for x in range(m1.row)])

        for i in range(m1.row):

            for j in range((m1.col)):

                result[i][j] = m1.M[i][j] - m2.M[i][j]

        return result

    @staticmethod
    def mul(m1, m2):

        if ((m1.col != m2.row)):

            return "multiplication is not possible"
        
        result = array([[0 for x in range(m2.col)] for x in range(m1.row)])

        for i in range(m2.col):

            for j in range(m1.row):

                for k in range(m1.col):

                    result[j][i] += m1.M[j][k] * m2.M[k][i]

        return result

    
    def transpose(self):

        result = array([[0 for x in range(self.row)] for x in range(self.col)])

        for i in range(self.row):

            for j in range(self.col):

                result[j][i] = self.M[i][j] 

        return result
    
mat = []
while True :

    ch = int(input("enter the choice:\n1.creat matrix\n2.add matrix\n3.sub matrix\n4.multi matrix\n5.tronspose\n6.exit\n"))
    
    if ch == 1:

        num = int (input("number of matrix you want to creat??\n"))

        while num>0:
            obj = matrix()
            mat.append(obj)
            num-=1

    elif ch == 2:
        
        print(matrix.add(mat[0], mat[1]))
    
    elif ch == 3:
        
        print(matrix.sub(mat[0], mat[1]))
    elif ch == 4:
        
        print(matrix.mul(mat[0], mat[1]))
    elif ch == 5:

        print(matrix.transpose(mat[0]))

    elif ch == 6:
        
        break
    
    else:
        print("invalid input")


