//Creator- Ashutosh
//This program takes n as an input and stores all the arrangements of the partition of the number 2*n in the file "1partsArrange.txt"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sortedPermutations(char str[]);
// A utility function to print an array p[] of size 'n'
void printArray(int p[], int n)
{	int i;
	for ( i = 0; i < n; i++)
	printf("%d", p[i]);
	printf("\n");
}

void printAllUniqueParts(int n)
{
	int p[n]; // An array to store a partition
	int k = 0; // Index of last element in a partition
	p[k] = n; // Initialize first partition as number itself

	// This loop first prints current partition, then generates next
	// partition. The loop stops when the current partition has all 1s
	while (1)
	{
		// print current partition
		if(k==n/2-1)
		{int i;
			char *cp;
			cp=(char*)malloc(7*sizeof(char));
			for(i=0;i<k+1;++i)
				cp[i]=(char)(48+p[i]);
			cp[6]='\0';
			sortedPermutations(cp);
		}

		// Generate next partition

		// Find the rightmost non-one value in p[]. Also, update the
		// rem_val so that we know how much value can be accommodated
		int rem_val = 0;
		while (k >= 0 && p[k] == 1)
		{
			rem_val += p[k];
			k--;
		}

		// if k < 0, all the values are 1 so there are no more partitions
		if (k < 0) return;

		// Decrease the p[k] found above and adjust the rem_val
		p[k]--;
		rem_val++;

		while (rem_val > p[k])
		{
			p[k+1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}

		// Copy rem_val to next position and increment position
		p[k+1] = rem_val;
		k++;
	}
}
	
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
 int x=0;
 char partseq[500][7];
// Print all permutations of str in sorted order
void sortedPermutations(char str[])
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
 		
       strcpy(partseq[x],str);
    
 		x++;
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
	
int main()
{	FILE *fp;
	fp=fopen("1partitionOutput.txt","w+");
	printf("Enter the number n\n");
	int n;
	scanf("%d",&n);
	printf("All Unique Partitions of 2*%d = %d are and there arrangements are written in the file \n",n,2*n);
	printAllUniqueParts(2*n);
	int i=0;
	for(i=0;i<x;++i){
		//writing the arrangements to the file
		fprintf(fp,"%s\n",partseq[i]);
	}
	fclose(fp);
	return 0;
}

