#Script Written By - Ashutosh
#This program reads the file "7OTPDigitsOutput.txt" line by line and selects the OTPs according to the users preference either distinct or 2 repeated or both 
fil=open("7OTPDigitsOutput.txt","r")
file1=open("8SelectedOTPOutput.txt","w")
count=0
lst=list()
n=int(input("Enter 1 for All distinct digits\n2 for two digits repeated and \n3 for both\n4 for All\n"))
if n not in [1,2,3,4]:
	print("Wrong Input!!")
	exit()
for line in fil:
    count+=1
    if count==1 or count==2:
        continue
    if count==1000003:
        break
    lst=(line.split())
    try:
        if (lst[1]==str(len(lst[0]))or lst[2]=='2')and n==3:
        	file1.write(lst[0])
        	file1.write('\n')
	elif lst[1]==str(len(lst[0])) and n==1:
		file1.write(lst[0])
		file1.write('\n')
	elif lst[2]=='2' and n==2:
		file1.write(lst[0])
		file1.write('\n')
	elif n==4:
		file1.write(lst[0])
		file1.write('\n')
	
    except:
        print (count)
    
print("Done!!")
        
    
    
