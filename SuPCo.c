#include<stdio.h>
/* 
        
goods:-
1.food
2.medicine
3.iron and steel
4.machinery
5.cotton and silk
*/
struct goods
{
	float surplus,need,gbought;
};
struct region
{
	char rname[32];
	struct goods g[5];

}c[32];
int noreg=-1;

void regionstatus()
{
	int i;
	char region[32];
		printf("Enter the region name:");
		fflush(stdin);
		gets(region);
	for(i=0;i<=noreg;i++)
	{
		if(	strcmp(c[i].rname,region)==0)
		{
			printf("\nRegion Name:");
			puts(c[i].rname);
			printf("Surplus food:%f",c[i].g[0].surplus);
			printf("\nSurplus medicine:%f",c[i].g[1].surplus);
			printf("\nSurplus iron and steel:%f",c[i].g[2].surplus);
			printf("\nSurplus machinery:%f",c[i].g[3].surplus);
			printf("\nSurplus cotton and silk:%f",c[i].g[4].surplus);
			printf("\nBrought food:%f",c[i].g[0].gbought);
			printf("\nBrought medicine:%f",c[i].g[1].gbought);
			printf("\nBrought iron and steel:%f",c[i].g[2].gbought);
			printf("\nBrought machinery:%f",c[i].g[3].gbought);
			printf("\nBrought cotton and silk:%f",c[i].g[4].gbought);	
		}	
	}
}
void displaysurplus(int opt)
{
	int i;
	for(i=0;i<=noreg;i++)
	{
		printf("\nRegion Name:");
		puts(c[i].rname);
		printf("Surplus=%f",c[i].g[opt-1].surplus);
	}	
}
void Register( int i)
{
	int j,t;
		printf("Enter the region name:");
		fflush(stdin);
		gets(c[i].rname);
		printf("1.Surplus Registeration\n2.Quit\nEnter the option:");
		scanf("%d",&t);
		switch(t)
			{
				case 1:	
					printf("ENTER ALL VALUES IN TONNES\n");
					printf("Enter the amount of extra food:");
					scanf("%f",&c[i].g[0].surplus);
					printf("Enter the amount of extra medicine:");
					scanf("%f",&c[i].g[1].surplus);
					printf("Enter the amount of extra iron and steel:");
					scanf("%f",&c[i].g[2].surplus);
					printf("Enter the amount of extra machinery:");
					scanf("%f",&c[i].g[3].surplus);
					printf("Enter the amount of extra cotton and silk:");
					scanf("%f",&c[i].g[4].surplus);
					printf("\nRegistering...\nREGISTERED");
					break;
				case 2:
					printf("\nQuiting Registeration...");
					noreg--;
					break;
				default:
					printf("INVALID OPTION!");
			}
}
void buysurplus()
{
	int i,j;
	char opt;
	char region[32];
	printf("Enter your region:");
	fflush(stdin);
	gets(region);
	for(i=0;i<=noreg;i++)
	{
		if(	strcmp(c[i].rname,region)==0)
		{
			do
			{
				int gno;
				printf("1.food\n2.medicine\n3.iron and steel\n4.machinery\n5.cotton and silk\nEnter the goods option:");
				scanf("%d",&gno);
				displaysurplus(gno);
				printf("\n\nEnter from which region to buy:");
				char regname[32];
				fflush(stdin);
				gets(regname);
				for(j=0;j<=noreg;j++)
				{
					if(	strcmp(c[j].rname,regname)==0)
					{
						printf("Enter the number of goods needed:");
						scanf("%f",&c[i].g[gno-1].need);
						printf("\nAmount needed:%f",c[i].g[gno-1].need);
						c[j].g[gno-1].surplus-=c[i].g[gno-1].need;//updated the surplus of region buyed
						c[i].g[gno-1].gbought=c[i].g[gno-1].need;
						printf("\nUPDATING...PLEASE WAIT!\nYOU have bought %f ton goods from %s.",c[i].g[gno-1].need,regname);
					}		
				}
				printf("\nDo you want to continue buying?(y/n):");
				fflush(stdin);
				scanf("%c",&opt);
			}while(opt=='y');	
		}
	}
}
void main()
{
	printf("SuPCo represents Sustainable Production and Consumption/n");
	int ch1,ch3;
	char ch;
	do
	{
		printf("\n1.Register\n2.Buy\n3.Surplus List\n4.Regional Status\n5.Quit\nEnter your choice:");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
				noreg++;
				Register(noreg);
				break;
			case 2:
				buysurplus();
				break;
			case 3:
				printf("\n1.food\n2.medicine\n3.iron and steel\n4.machinery\n5.cotton and silk\nEnter the goods option:");
				scanf("%d",&ch3);
				displaysurplus(ch3);
				break;
			case 4:
				regionstatus();
				break;
			case 5:
				printf("\nTHANK YOU!");
				break;
			default:
				printf("\nINVALID STATEMENT!");
		}
		printf("\n\nDo you want to continue(y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
}
