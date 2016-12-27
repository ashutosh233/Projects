def calcfromexp(dic,line):
	#print dic['c']	
	exp=line.split()
	ret=[]
	for word in exp:
		if word[1]=='+':
			x=word.split('+')
	#		print x
			ret.append((dic[x[0]]+dic[x[1]])%10)
		elif word[1]=='*':
			x=word.split('*')
	#		print x
			ret.append((dic[x[0]]*dic[x[1]])%10)
	return ret


fil1=open("8SelectedOTPOutput.txt","r")
fil2=open("6filterAllOutput.txt","r")
filw=open("Table70000.txt","w+")
c=0
for otp in fil1:
	
	filw.write(otp[:4])
	filw.write("\t")
	
filw.write("\n\n\n")
fil1.close()
fil1=open("8SelectedOTPOutput.txt","r")
count=0
for lin in fil2:
	count+=1
	print (count)
	fil1=open("8SelectedOTPOutput.txt","r")
	if count==100:
		break
	for otp in fil1:			
		otp=otp[:4]
		dic=dict()
		ch="abcdef"
		print('\t', otp)
		for i in range(len(otp)):
			dic[ch[i]]=int(otp[i])
		CurrOTP=map(str, calcfromexp(dic,lin))
		Cotpstr=''.join(CurrOTP)
		num=0
		filtemp=open("temp.txt","w+")		
		fil2temp=open("6filterAllOutput.txt","r+")		
		for line in fil2temp:
		
			lst=list()
			lst=map(str, calcfromexp(dic,line))
			
			s=''.join(lst)
			filtemp.write(s)
			filtemp.write('\n')
		fil2temp.close()
		filtempread=open("temp.txt","r+")
		for line in filtempread:
			line=line[:4]
			if line==Cotpstr:
				num+=1
		filw.write(str(num))
		filw.write("\t")
	filw.write("\n")
	print (count)
