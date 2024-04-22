
from numpy import *

class Student_Percentage:

    percentage = array([])

    def __init__(self):

        n = int(input("number of students ??\n"))
        
        print("enter the percentage")
        while n > 0:

            marks = float(input())
                          
            if (marks > 100) or (marks < 0):

                print("invalid input")

            else:

                Student_Percentage.percentage = append(Student_Percentage.percentage, marks)
            n -= 1

    @classmethod

    def insertion_sort(cls):

        
        for i in range(len(cls.percentage)-1):

          if cls.percentage[i] > cls.percentage[i + 1]:
              
              j = i 

              while j >= 0:
                  
                  if cls.percentage[j] < cls.percentage[i + 1]:
                      
                      cls.percentage = insert(cls.percentage, j+1, cls.percentage[i+1])
                      cls.percentage = delete(cls.percentage, i+2)
                      break
                  
                  elif j == 0:
                      
                      cls.percentage = insert(cls.percentage, j, cls.percentage[i+1])
                      cls.percentage = delete(cls.percentage, i+2)
                      break
                  
                  else:
                       j -= 1
                      

        return cls.percentage
    
    @classmethod

    def shell_sort(cls):

        gap = len(cls.percentage)//2

        while gap >= 0:

            j = 0

            while j+gap < len(cls.percentage):

                if cls.percentage[j] > cls.percentage[j+gap]:

                    cls.percentage[j] , cls.percentage[j+gap] = cls.percentage[j + gap] , cls.percentage[j]
                else :
                    pass

                j += 1

            if gap == 0:

                break
            
            gap -= 1
        return cls.percentage
    
    @classmethod

    def display(cls):

        print("top five scores are :", cls.percentage[:5])

    

obj = Student_Percentage()
print(obj.insertion_sort())
print(obj.shell_sort())
obj.display()




        