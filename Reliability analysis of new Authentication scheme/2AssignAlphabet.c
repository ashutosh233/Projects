//	Creator - Ashutosh
// this file reads every arrangements of the partitions from the file "1partitionOutput.txt" and stores the expected alpphabetical equivalent
// according to a linear countable map.
//	example-  111117 corresponds to abcdefffffff	and	123213 corresponds to	abbcccddefff
// and writes the files to "Digits2.txt"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif


void main(){
	
	FILE* fh;
	FILE *fp;
fopen_s(&fh, "1partitionOutput.txt", "r");
fp=fopen("2AssignAlphabetOutput.txt","w+");
//check if file exists
if (fh == NULL){
    printf("file does not exists");
    return ;
}


//read line by line
const size_t line_size = 10;
char* str = malloc(line_size);
while (fgets(str, line_size, fh) != NULL)  {
    //printf(line);
	char *seq="abcdef";
	int a[6];
	int i;
	int n=strlen(str);
	//printf("%d",n);
	
	for(i=0;i<n-1;++i){
		a[i]=(int)str[i]-48;
	}
	
	char arr[2*n-1];
	int j=0;i=0;
	// This loop assigns the alphabetical equivalent to  the character array "arr"
	while(j<=n-2){
		arr[i]=seq[j];
		i++;
		a[j]--;
		if(a[j]==0)
			j++;
	}
	arr[2*(n-1)]='\0';
	fprintf(fp,"%s\n",arr);
}
free(str);
	
}
