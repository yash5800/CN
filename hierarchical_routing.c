#include<stdio.h>
#include<conio.h>
struct full
{
	char line[10],dest[10];
	int hops;
}f[20];
void main()
{
	int nv,i,min,minver;
	char sv[20],temp;
	printf("Enter number of vertices : ");
	scanf("%d",&nv);
	printf("Enter source vertex : ");
	scanf("%s",sv);
	printf("Enter full table for soutce vertex %s\n",sv);
	for(i=0;i<nv;i++)
		scanf("%s%s%d",f[i].dest,f[i].line,&f[i].hops);
	printf("HIERARCHICAL TABLE");
	for(i=0;i<nv;)
	{
		if(sv[0]==f[i].dest[0])
		{
			printf("\n%s %s %d",f[i].dest,f[i].line,f[i].hops);
			i++;
		} 
		else
		{
			min=1000;
			minver=0;
			temp=f[i].dest[0];
			while(temp==f[i].dest[0])
			{
				if(f[i].hops<min)
				{
					minver=i;
				}
				i++;
			}
			printf("\n%c %s %d",temp,f[minver].line,f[minver].hops);
		}
	}
	printf("\n");
}
