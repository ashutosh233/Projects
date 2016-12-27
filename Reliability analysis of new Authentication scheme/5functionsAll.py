#This program first filters out the same strings from file "4AlterSortOutput.txt" and makes functions out of them with '+' and '*' signs. Saves the Output to "5functionsAllOutput.txt"
handle=open("4AlterSortOutput.txt","r")
handlew=open("5functionsAllOutput.txt","w")

def toString(List):
    return ''.join(List)
ls=list()
def allLexicographicRecur (string, data, last, index):
    length = len(string)
 
    for i in range(0,length):
        data[index] = string[i]
 
        if index==last:
            ls.append(toString(data))
        else:
            allLexicographicRecur(string, data, last, index+1)
 
def allLexicographic(string):
    length = len(string)
 
    data = [""] * (length+1)
 
    string = sorted(string)
 
    # Now print all permutaions
    allLexicographicRecur(string, data, length-1, 0)
 
# Driver program to test the above functions
# string = "++*"
# print ("All permutations with repetition of " + string + " are:")
# allLexicographic(string)
# print(ls)

s=set()
l=0
for line in handle:
    s.add(line)
l=len(line)
m=(l-1)//2 
sign=list()   
for i in range(0,m-1):
    sign.append('+')
sign.append('*')
allLexicographic(toString(sign))
ls=set(ls)
print(len(ls),len(s))
for k in ls:
    for i in s:
        for j in range(0,m):
            handlew.write(i[j]+k[j]+i[m+j]+'\t')
        handlew.write('\n')
    handlew.write('\n')
