
class program_info:

    info = []

    def __init__(self):

        n = int (input("number of student you want to enter:\n"))
        print ("enter the roll numbers:")
        while n > 0:

            roll_no = int (input())
            program_info.info.append(roll_no)
            n -= 1


    @classmethod

    def linear_search(cls , Roll_no):

        for i in cls.info:
            
            if i == Roll_no:
                print (f"the Roll number {i} has attended the program")
                return
            else:
                pass
        
        print (f"the Roll number {Roll_no} has not attented the program")
        return 

    @classmethod

    def sentinal_search(cls,Roll_no):

        last = cls.info[len(cls.info)-1]

        if last == Roll_no :

            print(f"the Roll number {Roll_no} has attended the program") 
            return ''

        cls.info[len(cls.info)-1] = Roll_no

        i = 0

        while cls.info[i] != Roll_no:

            i += 1

        if i != len(cls.info) - 1:

            print(f"the Roll number {Roll_no} has attended the program") 

        else:
           print (f"the Roll number {Roll_no} has not attented the program")

    @classmethod

    def sort(cls):

        for i in range(len(cls.info)-1):

            for j in range(i+1,len(cls.info)):


                if cls.info[i] > cls.info[j]:
                    
                    cls.info.insert(i,cls.info[j])
                    del cls.info[j+1]
                else:

                    pass
      
        return cls.info
    
    @classmethod

    def binary_search(cls, Roll_num):

        lis = cls.sort()
        first = 0
        last = len(lis) -1

        while first <= last:

            mid = (last + first)//2

            if lis[mid] == Roll_num:

                print(f"the Roll number {Roll_num} has attended the program")
                return ''
            elif lis[mid] > Roll_num:

                last = mid - 1
                
            else:
                first = mid + 1
        print(f"the Roll number {Roll_num} has not attended the program")  
    


    @classmethod

    def fibonacci_search(cls,roll_num):
        cls.sort()
        f0 = 0
        f1 = 1
        f2 = 1

        while f2 < len(cls.info):
            
            f0 = f1
            f1 = f2
            f2 = f1 + f0
         
        start = 0

        while f2 > 1:

            idx = min(start + f0, len(cls.info)-1)

            if cls.info[idx] == roll_num:

                print("found")
                return
            elif cls.info[idx] < roll_num:

                f2 = f1
                f1 = f0
                f0 = f2 - f1
                start = idx
            else:

                f2 = f0
                f1 = f1 - f2
                f0 = f2 - f1

        else :

            return -1

    
        

      
        


p1 = program_info()
           

#p1.linear_search(5)
#p1.sentinal_search(7)
#p1.binary_search(7)
print(p1.fibonacci_search(78))
#p1.sort()



        

    