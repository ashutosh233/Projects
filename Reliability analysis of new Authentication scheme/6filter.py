 #This file filters the set of functions containing the duplicate functions
#from pip._vendor.distlib.compat import raw_input
n=int(input("Enter 0 for 5functionsplusOutput.txt as input file \n Enter 1 for 5functionsAllOutput.txt as input file\n"))
if n==0:
	name="5functionsplusOutput.txt"
elif n==1:
	name="5functionsAllOutput.txt"
else:
	print("Wrong Input!!!")
	exit()	

if n==0:
	Oname="6filterplusOutput.txt"
elif n==1:
	Oname="6filterAllOutput.txt"

handler=open(name,"r")
handlew=open(Oname,"w")
for line in handler:
    lst=line.split()
    flag=0
    for j in range(0,len(lst)):
        for k in range(0,len(lst)):
            if j!=k:
                if lst[k]==lst[j]:
                    flag=1
    if flag==0:
        handlew.write(line) 
handler.close()
handlew.close()                
        
    
