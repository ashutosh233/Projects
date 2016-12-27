// Creator- Ashutosh Prasad
// This program reads the file "3AllArrangementsOutput.txt" line by line and sorts the pair of elements at ith and (n+i)th position
// And stores the Output to "4AlterSortOutput.txt" 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif
int main(){
	int i;
	FILE* fh;
	FILE *fp;
	fp=fopen("4AlterSortOutput.txt","w+");
	char *filename="3AllArrangementsOutput.txt";
fopen_s(&fh, filename, "r");

//check if file exists
if (fh == NULL){
    printf("file does not exists %s", filename);
    return 0;
}


//read line by line
const size_t line_size = 15;
char* line = malloc(line_size);
while (fgets(line, line_size, fh) != NULL)  {
	int n=(strlen(line)-1)/2;
	//printf("%d",strlen(line);
	for(i=0;i<n;++i){
		if(line[i]>line[n+i]){
			char t=line[i];
			line[i]=line[n+i];
			line[n+i]=t;
		}
	}
	fprintf(fp,"%s",line);
}
printf("DONE!!");
return 0;
}
