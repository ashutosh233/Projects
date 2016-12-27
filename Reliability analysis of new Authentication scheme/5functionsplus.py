#This program first filters out the same strings from file "4AlterSortOutput.txt" and makes functions out of them with '+' sign only. Saves the Output to "5functionsplusOutput.txt"
handle=open("4AlterSortOutput.txt","r")
handlew=open("5functionsplusOutput.txt","w")

s=set()
l=0
for line in handle:
    s.add(line)
l=len(line)
m=(l-1)//2 

for i in s:
	for j in range(0,m):
		handlew.write(i[j]+'+'+i[m+j]+'\t')
	handlew.write('\n')
