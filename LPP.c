#include<stdio.h>
#include<stdlib.h>
void sequence(int *output,int *used,int *symbols,int *canuse,int count,int n);
int * findAllPositions(int *used,int n);
void printarray(int * arr,int n)
{
	int i;
	printf("printing array\n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	printf("\n-----\n");
	return ;
}
int main()
{
int n,i,j,*symbols,*canuse,*output,*used;
//scanf("%d",&n);

n=4;
symbols = (int *) malloc(sizeof(int)*n);
canuse = (int *) malloc(sizeof(int)*n);
output = (int *)malloc(sizeof(int)*(n+n));
used = (int *)malloc(sizeof(int)*(n+n));
for(i=0;i<(n+n);i++)
{
used[i]=0;
}

for(i=0;i<n;i++)
{
symbols[i]=i+1;
canuse[i]=1;
}
sequence(output,used,symbols,canuse,0,n);
return 0;
}


int * findAllPositions(int *used,int n)
{
int * positions,i,j=0;
positions = (int *)malloc(sizeof(int)*(n+n));
for(i=0;i<(n+n);i++)
{
positions[i]=-1;
}
for(i=0;i<(n+n);i++)
{
if(used[i]==0)
positions[j++]=i;
}
return positions;

}


void sequence(int *output,int *used,int *symbols,int *canuse,int count,int n)
{

if(count == (n+n))
{

printf("output\n");
printarray(output,count);

return;

}

int *positions,i,j,k,l;
positions = (int *)malloc(sizeof(int)*(n+n));
positions = findAllPositions(used,n);
for(i=0;i<n;i++)
{
if(canuse[i]==1)
{
canuse[i]=0;
for(j=0;j<(n+n);j++)
{
if(positions[j]==-1)
break;
if(used[positions[j]]==0)
{
output[positions[j]]=symbols[i];
used[positions[j]]=1;
l = positions[j]+symbols[i]+1;
if(l<(n+n) && used[l] == 0 )
{
output[l]=symbols[i];
used[l]=1;
sequence(output,used,symbols,canuse,count+2,n);
used[l]=0;
}
used[positions[j]]=0;
/*
k = positions[j]-symbols[i]-1;
if(k<0)
k=n+k;

if(used[k]==0)
{
output[k]=symbols[i];
used[k] = 1;
sequence(output,used,symbols,canuse,count+2,n);
used[k]=0;
}*/
}
}
canuse[i]=1;
}
}
}
