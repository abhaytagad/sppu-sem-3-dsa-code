
from numpy import *
from sys import *


class matrix:

    def __init__(self):

        self.row = int (input("numer of row ??"))
        self.col = int (input("number of col ??"))
        self.Matrix = array([[0 for x in range(self.col)] for x in range(self.row)]) # declared 2d matrix using numpy

    # taking elements of matrix as input from user
        print("enter the elements:")

        for i in range(self.row):
            
            for j in range(self.col):
                ele = int(input())
                self.Matrix[i][j] = ele 

    def sadalPoint(self):
        
        min = maxsize
    
        for i in range(self.row):

            flag = True
            for j in range(self.col):

                if self.Matrix[i][j] < min :

                    min = self.Matrix[i][j]
                    ptr = j
                else:

                    pass
           
            for k in range(self.row):

                if (min < self.Matrix[k][ptr]) and (k != i):

                    flag = False
                    break

                else:

                    pass

            if flag :

                print(min)

            else:

                pass

m = matrix()
print(m.Matrix)
m.sadalPoint()
