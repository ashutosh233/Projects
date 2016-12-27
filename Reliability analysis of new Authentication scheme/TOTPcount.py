str=input("Enter the 4 digit transformed otp to see their number of occurence\n")
handle=open("4digitoutput.txt","r")
count=0
flag=0
for line in handle:
	if line[:4]==str:
		count+=1
		flag=1
if flag==0:
	print ("Not Present")
else:
	print ("number of functions corresponding to "+str+" is ",count) 
