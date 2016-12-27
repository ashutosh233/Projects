// Creator- Ashutosh
// This program reads the file "2AssignAlphabetOutput.txt" line by line and stores all theeir Permutations to the file "AllPerm3.txt"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif
int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}
 
// A utility function two swap two characters a and b
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
 
// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l;
 	int i;
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for ( i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}

// Print all permutations of str in sorted order
void sortedPermutations(char str[], FILE *fp)
{
    // Get size of string
    int size = strlen(str);
 
    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);
 
    // Print permutations one by one
    int isFinished = 0;
    while (!isFinished)
    {
        // print this permutation
 		
      fprintf(fp,"%s\n",str);
    
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for (i = size - 2; i >= 0; --i)
            if (str[i] < str[i+1])
                break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if (i == -1)
            isFinished = 1;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil(str, str[i], i + 1, size - 1);
 
            // Swap first and second characters
            swap(&str[i], &str[ceilIndex]);
 
            // Sort the string on right of 'first char'
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}


void main(){
	FILE* fh;
	FILE *fp;
	fp=fopen("3AllArrangementsOutput.txt","w+");
	char *filename="2AssignAlphabetOutput.txt";
fopen_s(&fh, filename, "r");

//check if file exists
if (fh == NULL){
    printf("file does not exists %s", filename);
    return ;
}


//read line by line
const size_t line_size = 15;
char* line = malloc(line_size);
while (fgets(line, line_size, fh) != NULL)  {
	printf(line);
	int n=strlen(line);
	line[n-1]='\0';
    sortedPermutations(line,fp);
}
free(line);
return; 
}
