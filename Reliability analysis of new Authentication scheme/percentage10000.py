
def calcfromexp(dic,line):
	#print (dic['a'])	
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

handle=open("ALLOutput.txt","r+")
handlef=open("med1OutputMOD.txt","r+")
han=open("percentage10000file.txt","w+")

count=0
l=""
for lin in handle:
	#print(line)
	dic=dict()
	ch="abcdef"
	l=lin[:4]
	han.write(l+"\t-")
	l.strip('\n')
	print (l)
	for i in range(len(l)):
		dic[ch[i]]=int(l[i])
	#print (dic)
	count+=1
	handlef=open("med1OutputMOD.txt","r+")
	setofOutput=set()
	for line in handlef:
		lst=list()
		lst=map(str, calcfromexp(dic,line))
	
		s=''.join(lst)
		setofOutput.add(s)
	percentage=100*(len(setofOutput)/10000)
	han.write("\t"+str(percentage)+"%")
	han.write("\n")
print(count)