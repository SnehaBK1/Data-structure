#include <stdio.h>
#define MAX 10
void linear_prob(int[]);
void display(int[]);
void linear_prob(int a[MAX])
{
int flag, key, i, address, count;
char ans;
do
{
flag=0;
count=0;

printf("\n Enter 4 digit Key : ");
scanf("%4d", &key);
address=key%10;
if(a[address]== -1)
a[address] = key;
else
{
printf("\nCollision Detected...!!!\n");
i=0;
while(i<MAX)
{
if (a[i]!=-1)
count++;
i++;
}
if(count == MAX)
{
printf("\n Hash table is full \n");
display(a);
return;
}

printf("\nCollision avoided successfully using LINEAR PROBING\n");

for(i=address+1; i<MAX; i++)
if(a[i] == -1)
{
a[i] = key;
flag =1;
break;
}
i=0;
while((i<address) && (flag==0))
{
if(a[i] == -1)
{
a[i] = key;
flag=1;
break;
}
i++;
}
}
printf("\n Do you wish to continue ? (y/n) ");
fflush(stdin);
scanf(" %c",&ans);
} while(ans=='y' || ans == 'Y') ;
}
void display(int a[MAX])
{
int i;
printf("\n The HASH TABLE is\n Address \t Key");
for(i=0; i<MAX; i++)
printf("\n %d \t %d ", i, a[i]);
}
void main()
{
int a[MAX], i, choice;
for (i=0;i<MAX;i++)
a[i] = -1;
while(1)
{
printf("\n Collision handling by Linear Probing ");
printf("\n1. Insert into Hash table");
printf("\n2. Display Hash table");
printf("\n3. Exit");
printf("\n Enter your Choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1: linear_prob(a);
break;
case 2: display(a);
break;
case 3: return;
default: printf("\n Invalid Choice");
}
}
}