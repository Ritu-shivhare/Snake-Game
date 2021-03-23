#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void setup();
void draw();
void input();
void makelogic();
int h=30, w =30,x,y,fx,fy,flag,gameend,score;
int tailX[100], tailY[100];
int piece=0;
void makelogic()
{ int i;
   int prevx,prevy,prev2x,prev2y;
   prevx=tailX[0];
   prevy=tailY[0];
   tailX[0]=x;
   tailY[0]=y;
   for(i=1;i<=piece;i++)
   {
   	prev2x=tailX[i];
   	prev2y=tailY[i];
   	tailX[i]=prevx;
   	tailY[i]=prevy;
   	prevx=prev2x;
   	prevy=prev2y;
   }

switch(flag)
    {   case 1:
    	   {x--;
    	    break;
		   }
		case 2:
			{x++;
			break;
			}
		case 3:
			{y--;
			break;
			}
		case 4:
			{y++;
			break;
			}
	}
 if(x==1 || x==h||y==1||y==w)
  {
  gameend=1;}
  
 
if(x==fx && y==fy)
{label3:
	
    fx =rand()%30;
    if(fx==1)
  goto label3;
label4:
	fy= rand()%30;
	if(fy==1)
  goto label4;
score+=10;
piece++;

}
}


void input()
{ if(kbhit())
{
	switch(getch())
	{
		case '8':
			{flag=1;
			break;
			}
        case '2':
        	{flag=2;
        	break;
			}
	    case '4':
	    	{flag=3;
	    	break;
			}
		case '6':
			{flag=4;
			break;
			}
    }
}
	
	
	
}

void setup()
{x=w/2;
y=h/2;
   
	 label1:
	fx = rand()%30;
    if(fx==1)
  goto label1;
label2:
	fy= rand()%30;
	if(fy==1)
  goto label2;

gameend=0;
score=0;	



}
void draw()
{   
system("cls");
int i,j,k,ch;
for(i=1;i<=h;i++)
{for(j=1;j<=w;j++)
{if(i==h||i==1||j==w||j==1)
{printf("*");
}
else
	if(i==x && j==y)
	{printf("#");
	}
	else if
	(i==fx && j==fy)
	{printf("0");
	}
else
{ ch=0; 
  for(k=0;k<piece;k++)
{
	if(i==tailX[k] && j==tailY[k])
	{ printf("#");
	   ch=1;
	}
}
if(ch==0)
printf(" ");

}

    
}
printf("\n");}



printf("score: %d\n",score);
}

int main()
{  // system("cls");
	setup();
	while(gameend!=1)
	{
	input();
	draw();
	makelogic();

	}
	
 } 
