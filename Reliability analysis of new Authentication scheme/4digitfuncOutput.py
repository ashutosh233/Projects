
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

handle=open("secureOutput.txt","r+")
handlef=open("trial2O.txt","r+")
handlew=open("4digitoutput.txt","w+")
n=int(input("Enter the Index of OTP you want to use"))
count=0
l=""
for line in handle:
	if count==n:
		l=line
		break
	count+=1
dic=dict()
ch="abcdef"

l.strip('\n')
print (l)
for i in range(len(l)-1):
	dic[ch[i]]=int(l[i])
#print dic
exp=list()
for line in handlef:
	#print line
	lst=list()
	lst=map(str, calcfromexp(dic,line))
	
	s=''.join(lst)
	handlew.write(s)
	handlew.write("\n")
#print s

