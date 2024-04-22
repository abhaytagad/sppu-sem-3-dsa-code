
class stroperation:

    def  __init__(self):

        str = input("enter the string:\n")
        self.str = str


    def longestWord(self):

        word = ""
        maxlenWord = ""

        for itr in range(len(self.str)):
            

            if self.str[itr] == ' ':
                
                if len(word) > len(maxlenWord):
                    
                    maxlenWord = word
                    
                word = ""

            else:

                if itr == len(self.str)-1:
                    
                    word += self.str[itr]
                    
                    
                    if len(word) > len(maxlenWord):

                        maxlenWord = word
                        
                        return maxlenWord
                    else:

                        return maxlenWord
                else:
                    
                    word += self.str[itr]
        return maxlenWord
            
    def frequqncy(self):

        word = input("enter the word:\n")

        re = ''
        count = 0
        for itr in range(len(self.str)):

            if (self.str[itr] == " "):

                if re == word:

                    count+=1
                re = ''
            else:

                if itr == len(self.str)-1:

                    re += self.str[itr]

                    if re == word:

                        count+=1
                        return count
                    
                    else:

                        return count
                else:
                    re += self.str[itr]
        return count
            
    def isPallimdrome(substr):
        
        substr = input("enter the substring:\n")

        if str.firstOcurr() == -1:

            return "the substr is not present in string"
        
        
        reverse = substr[::-1]
        
        if substr == reverse:
            
            print(f"the  string {substr} is pallimdrome")

        else:

            print(f"the  string {substr} is not pallimdrome")

    def firstOcurr(self):

        substr = input("enter the sub string :\n")

        ptr = 0
        ocurr = -1
        for itr in range(len(self.str)):

            if (self.str[itr] ==  substr[ptr]):

                if ptr == 0 :
                    ocurr = itr

                ptr +=1

                if ptr == len(substr):
                    break

            elif (self.str[itr] != substr[ptr]) and (ptr != 0):

                ptr = 0
                itr = ocurr+1
                ocurr = -1

            else:

                pass 

        if ptr == len(substr):

            return ocurr
        
        else:

            return -1 
          

    def ocurrenceCount(self):

        occurr_dict = {}

        word = ''

        for chr in self.str:

            if chr == ' ':
                
                if (word in occurr_dict.keys()):
                    
                    occurr_dict[word] += 1

                else:

                    occurr_dict[word] = 1

                word = ''

            else:

                word += chr

        if (word in occurr_dict.keys()):
        
            occurr_dict[word] += 1

        else:

            occurr_dict[word] = 1

        return occurr_dict



str = stroperation()


print(str.frequqncy())
print(str.longestWord())

str.isPallimdrome()

print(str.firstOcurr())

print(str.ocurrenceCount())
