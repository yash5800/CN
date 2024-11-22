#include<stdio.h>
#include<string.h>

int main()
{
	char msg[20],temp_f[30],temp[30]={'~','\0'};
	int i,index=1;
	
	printf("Enter msg : ");
	scanf("%s",msg);
	
	for(i=0;i<strlen(msg);i++){
		if(msg[i]=='~'){
			temp[index++]='~';
		}
		temp[index++]=msg[i];
	}
	
	temp[index++]='~';
	temp[index]='\0';
	
	printf("Sender : %s\n",temp);
	
	index=0;
	
	for(i=1;i<strlen(temp)-1;i++){
		if(temp[i]=='~'){
			i++;
		}
		temp_f[index++]=temp[i];
	}
	
	temp_f[index]='\0';
	
	printf("Recived : %s ",temp_f);
}