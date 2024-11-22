#include<stdio.h>
struct node
{
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int main()
{
	int cost[10][10],n,i,j,k,count=0;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			cost[i][i]=0;
			rt[i].dist[j]=cost[i][j];
			rt[i].from[j]=j;
		}
	}
	do
	{
		count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j]=k;
						count++;
					}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		Prin	tf("For router %d\n",i+1);
		for(j=0;j<n;j++)
		{
			printf("Node %d via %d distance %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
		}
	}printf("\n");
}
