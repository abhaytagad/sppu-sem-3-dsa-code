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

    def partition(cls, fpt,lpt):
        
        pivot = cls.percentage[lpt]

        j = fpt

        for i in range(fpt,lpt):

            if cls.percentage[i] < pivot:

                cls.percentage[i] , cls.percentage[j] = cls.percentage[j], cls.percentage[i]
                j += 1

        cls.percentage[lpt] , cls.percentage[j] = cls.percentage[j], cls.percentage[lpt]
      
        return j
        
    @classmethod

    def quick_sort(cls, fpt, lpt):

        

        if lpt < fpt :
            
            return cls.percentage
        
        else:

            pivot = cls.partition(fpt,lpt)
            
            cls.quick_sort(fpt, pivot - 1)
            cls.quick_sort(pivot + 1, lpt)

    @classmethod

    def top_five(cls):

        cls.quick_sort(0,len(cls.percentage)-1)
        print(cls.percentage[:-6:-1])

             


        

p = Student_Percentage()

#p.quick_sort(0, len(p.percentage)-1)

print(p.percentage)
p.top_five()

