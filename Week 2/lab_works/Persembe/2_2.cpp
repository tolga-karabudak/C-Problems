#include<stdio.h>


typedef struct{
	int x,y,z,w;
	char c;
}adress_t;

int search_nick(adress_t adr[100], int i)
{
	int j=0;
	int a=0;
	for(j;j<i;j++)
	{
		if(adr[j].c!=adr[i].c)
			a++;

	}
	if(a!=i)
		return 1;
	else
		return 0;
}

void display(adress_t *adr, int i)
{
	int a=0;
	int arr[100];
	for(int b=0;b<i;b++)
	{	
		if((adr+b)->x==(adr+b+1)->x&&(adr+b)->y==(adr+b+1)->y)
		{			
			*(arr+a++)=b;
			*(arr+a++)=b+1;
			
		}		
	}
	int arr2[a];
	int chech=0;
	int k;
	for(k=0;k<a;k++)
	{	
		if(search_nick(adr,a)==0)
		{
			*(arr2+k)=a;
			printf("%d.%d.%d.%d.'%c'\n",adr[k].x,adr[k].y,adr[k].z,adr[k].w,adr[k].c);
			chech++;		
		}	
	}
	
	if(chech==0)
		printf("aynı yok");
	else
	{
		for(int w=0;w<k;w++)
		{
			printf("%d.%d.%d.%d.'%c'\n",adr[w].x,adr[w].y,adr[w].z,adr[w].w,adr[w].c);
		}
		
	}

	
	
	
	
/*	for(int k=0;k<a;k++)
	{
		if(if(adr+k)->c!=(adr+k+1)->c)
			printf("%d.%d.%d.%d.'%c'\n",adr[k].x,adr[k].y,adr[k].z,adr[k].w,adr[k].c);
		
	}
*/	
}
int main()
{
	adress_t adr[100];
	int same[100];
	int c_same=0;
	int i=0;	
	do{
		printf("Enter the numeric address and nickname: ");
		scanf("%d.%d.%d.%d.%c",&(adr+i)->x,&(adr+i)->y,&(adr+i)->z,&(adr+i)->w,&(adr+i)->c);
		if(i>0&&(adr+i)->x!=0,(adr+i)->y!=0,(adr+i)->z!=0,(adr+i)->w!=0)
		{
			while(search_nick(adr,i))
			{
				printf("Existing name!\nEnter another nickname: ");
				scanf(" %c",&adr[i].c);				
			}	
		}
		i++;
			
	}while((adr-1+i)->x!=0,(adr-1+i)->y!=0,(adr-1+i)->z!=0,(adr-1+i)->w!=0);	
//	int z=0;
	
//			printf("%d.%d.%d.%d.%c\n",adr[x].x,adr[x].y,adr[x].z,adr[x].w,adr[x].c);
/*	int check[i-1][i-1];
	for(int e=0;e<i-1;e++)
	{
		for(int w=0;w<i-1;w++)
			check[e][w]=0;
	}
	
	
	for(int a=0;a<i-1;a++)
	{
		for(int b=a+1;b<i;b++)
		{
			if((adr+a)->x==(adr+b)->x&&(adr+a)->y==(adr+b)->y)
			{
			printf("%d.%d.%d.%d.'%c'\n",adr[a].x,adr[a].y,adr[a].z,adr[a].w,adr[a].c);
			printf("%d.%d.%d.%d.'%c'\n",adr[b].x,adr[b].y,adr[b].z,adr[b].w,adr[b].c);
			}
		}
	}*/
/*	int b=0;
	int  a=0;
	int counter=0;
	check[b][a]=(adr+b)->x;
	check[b][a+1]=(adr+b)->y;
	for(b=1;b<i-1;b++)
	{	if((adr+b)->x!=(adr+b-1)->x&&(adr+b)->y==(adr+b-1)->y)
		{
			a=0;
			check[b][a]=(adr+b)->x;
			check[b][a+1]=(adr+b)->y;
			counter++;
		}		
	}
	
	for(int z=0;z<counter;z++)
	{
		printf("%d.%d",check[z][0],check[z][1]);

	}*/
	display(adr,i-1);
	
	
	
	
}
