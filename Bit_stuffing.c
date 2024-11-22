#include<string.h>
#include<stdio.h>

int main()
{
	char st[20],st_t[20];
	int i,count=0,index=0;
	
	printf("enter ur bits : ");
	scanf("%s",st);
	for(i=0;i<strlen(st);i++){
	  if(st[i]=='0'){
	  	st_t[index] = st[i];  	
	  	count=0;
	  }
	  else if(st[i]=='1' && count<4){
	     st_t[index] = st[i];
	     count++;
	  }
	  else{
	    st_t[index]=st[i];
	    st_t[++index]='0';
	    count=0;
	  }
	  st_t[++index]='\0';
	}
	printf("%s",st_t);
}