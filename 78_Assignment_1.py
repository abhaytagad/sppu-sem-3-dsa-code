
cr = ["pranav", "abhay","akshay","aditi"]
ft = ["aditi","abhay"]
bd = ["pranav", "akshay", "abhay"]

def add_info():

    name = input("enter the name of student and choice:\n")
    game = int(input())

    if game == 1:

        cr.append(name)

    elif game == 2:

        ft.append(name)

    elif game == 3:

        bd.append(name)
    
    else:

        print ("invalid input")
    

def union(s1 , s2):

    temp = []

    for i in s1:

        temp.append(i)
    
    for i in s2:
        flag = True 
        for j in s1:

            if i == j:

                flag = False
                break
            else:
                pass
        if flag:
            temp.append(i)
        else:
            pass
    print (temp)

def intersection(s1 , s2):

    temp = []

    for i in s1:
        for j in s2:
            if i == j:
                temp.append(i)
                break
            else: 
                pass
    
    print (temp)

def diff(s1 , s2):

    temp = []
    for i in s1 :
        temp.append(i)
    
    for i in  s2:
        for j in s1:

            if i == j:

                temp.remove(j)
            else:
                pass
    
    print (temp)

union(cr,ft)
intersection(cr,ft)
diff(bd,cr)