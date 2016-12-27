#include<stdio.h>
#include<math.h>

struct countn {
int digit[10];
int repetition[10]; 	// restricts n to be maximum of size 10
};

int fact(int n){
	if(n==0||n==1)
	 return 1;
	else
	return n*fact(n-1);
}
void main(){
	int n,i,j,k,l,x=0;
	int f;
	struct countn c;
	for(i=0;i<10;++i)
		c.digit[i]=0;
	printf("Enter the number of digits of OTP");
	scanf("%d",&n);
	int count[2*n];
	for(i=0;i<2*n;++i)
		count[i]=0;
	FILE *fp;
        fp=fopen("7OTPDigitsOutput.txt","w+");
        fprintf(fp,"number\t\t");
        for(i=0;i<n;++i)
        fprintf(fp,"%d\t\t",i+1);
	fprintf(fp,"Permutations\n");
	int start=(int)pow(10.0,(double)(n-1)),end=(int)pow(10.0,(double)(n)),arrnum[n];
	for(i=0;i<end;++i){
		//int arrnum[n];
		x=n;
		int t=i,k=0;
		while(t!=0||x>0){
			arrnum[k++]=t%10;
			t/=10;
			x--;
			//printf("%d",arrnum[k-1]);
		}
		fprintf(fp,"\n");
		for(x=n-1;x>=0;--x)
		 fprintf(fp,"%d",arrnum[x]);
		 fprintf(fp,"\t\t");

		for(j=0;j<10;++j){
			c.digit[j]=0;
			for(k=0;k<n;++k){
				if(arrnum[k]==j)
				   c.digit[j]++;
			}
		// fprintf(fp,"%d\t",c.digit[j]);

		}
			f=fact(n);
	//	 fprintf(fp,"\n");
		for(l=1;l<=n;++l){
				c.repetition[l]=0;
			for(j=0;j<10;++j){
					if(c.digit[j]==l){
					c.repetition[l]++;
					}
					}
		int s=c.repetition[l];
		while(s!=0){
		f/=fact(l);
		s--;
		}
			if(c.repetition[1]==1&&c.repetition[2]==1&&c.repetition[3]==1)
			count[4]+=1;
			else if(c.repetition[1]==3&&c.repetition[3]==1)
			count[6]+=1;
			else if(c.repetition[1]==2&&c.repetition[4]==1)
			count[8]+=1;
			else if(c.repetition[1]==1&&c.repetition[5]==1)
			count[9]+=1;
			
		fprintf(fp,"%d\t\t",c.repetition[l]);
		
			}
		fprintf(fp,"%d",f);
		if(n==6){
		if(c.repetition[1]==6)
			count[0]+=1;
		else if(c.repetition[1]==4&&c.repetition[2]==1)
			count[1]+=1;
		else if(c.repetition[1]=2&&c.repetition[2]==2)
			count[2]+=1;
		else if(c.repetition[2]==3)
			count[3]+=1;
		
		else if(c.repetition[3]==2)
			count[5]+=1;
		else if(c.repetition[4]==1&&c.repetition[2]==1)
			count[7]+=1;
		else if(c.repetition[6]==1)
			count[10]+=1;
	}
	}
	printf("%d", sizeof(long long));
	printf("%d",count[4]);
	if(n==6){
	fprintf(fp,"\n\n");
	fprintf(fp,"\n# of All dixtinct digits:\t\t%d",count[0]);
	fprintf(fp,"\n# of one double and other dixtinct digits:\t\t%d",count[1]);
	fprintf(fp,"\n# of two double and 2 dixtinct digits:\t\t%d",count[2]);
	fprintf(fp,"\n# of All double digits:\t\t%d",count[3]);
	fprintf(fp,"\n# of one triple, 1 double and 1 single digits:\t%d",count[4]);
	fprintf(fp,"\n# of 2 triples digits:\t\t%d",count[5]);
	fprintf(fp,"\n# of 1 triple and 3 dixtinct digits:\t\t%d",count[6]);
	fprintf(fp,"\n# of 1 quadruple and 2 dixtinct digits:\t\t%d",count[7]);
	fprintf(fp,"\n# of 1 quadruple and 1 double digits:	\t\t%d",count[8]);
	fprintf(fp,"\n# of 1 quintruple and 1 single digits:\t\t%d",count[9]);
	fprintf(fp,"\n# of all same digits:	\t\t%d",count[10]);
	}
	fclose(fp);
}
