# include <termios.h>
# include <unistd.h>
# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
//# include <curses.h>
using namespace std;

int getch()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}




int main ()
{
int a[4][4] , f[4][4][2] , c , j , i , k , b , x , y , q , z , E[4];
for (i=0 ; i<4 ; i++)
for (j=0 ; j<4 ; j++)
a[i][j]=0;

// entekhab 2 khane ye avval
	// adad aval
	c=time(0);
	b=c%16;

	if (b<4)
	x=0;
	if (b>3 && b<8)
	x=1;
	if (b>7 && b<12)
	x=2;
	if (b>11)
	x=3;
	
	y=b%4;

	a[x][y]=2;

	
	// adad dovom
	
	c=c%15;
	if (c==0)
	c=2;
	b=b+c;
	b=b%16;

	if (b<4)
	x=0;
	if (b>3 && b<8)
	x=1;
	if (b>7 && b<12)
	x=2;
	if (b>11)
	x=3;
	
	y=b%4;

	a[x][y]=2;

	

	// cout
	for (j=3 ; j>-1 ; j=j-1)
	{
	for (i=0 ; i<4 ; i++)
	cout<<a[i][j]<<"         ";
	cout<<endl<<endl<<endl<<endl;
	}


	for (i=0 ; i<4 ; i++)
	for (j=0 ; j<4 ; j++)	
	f[i][j][0]=a[i][j];

	cout<<"if you want move up press (w) then enter"<<endl;
	cout<<"if you want move down press (s) then enter"<<endl;
	cout<<"if you want move left press (a) then enter"<<endl;
	cout<<"if you want move right press (d) then enter"<<endl;


char p='o';
while (p!='i')
{

	
	int d=0;
		while (d<12)
		{
		d=0;

	/*cin>>p;

	if (p=='w')
	z=1;
	if (p=='s')
	z=2;
	if (p=='a')
	z=3;
	if (p=='d')
	z=4;*/
	
	cout<<endl<<endl;




	p=getch();
	switch (p)
	{
		case 'w' :
		
		for (i=0 ; i<4 ; i++)
		{	for (k=0 ; k<5 ; k++)
			{	for (j=2 ; j>-1 ; j=j-1)
			 	if (a[i][j+1]==0) { a[i][j+1]=a[i][j]; a[i][j]=0; } 
			}
		
			for (k=0 ; k<5 ; k++)
			{	for (j=2 ; j>-1 ; j=j-1)
			 	if (a[i][j+1]==a[i][j]) {a[i][j+1]=2*a[i][j]; a[i][j]=0; k=7;}
			}
			
			for (k=0 ; k<5 ; k++)
			{	for (j=2 ; j>-1 ; j=j-1)
			 	if (a[i][j+1]==0) { a[i][j+1]=a[i][j]; a[i][j]=0; } 
			}
		
		}
		break;

		case 's' :
		
		for (i=0 ; i<4 ; i++)
		{	for (k=0 ; k<5 ; k++)
			{	for (j=1 ; j<4 ; j++)
			 	if (a[i][j-1]==0) { a[i][j-1]=a[i][j]; a[i][j]=0; } 
			}
		
			for (k=0 ; k<5 ; k++)
			{	for (j=1 ; j<4 ; j++)
			 	if (a[i][j-1]==a[i][j]) {a[i][j-1]=2*a[i][j]; a[i][j]=0; k=7;}
			}
			
			for (k=0 ; k<5 ; k++)
			{	for (j=1 ; j<4 ; j++)
			 	if (a[i][j-1]==0) { a[i][j-1]=a[i][j]; a[i][j]=0; } 
			}
		
		}
		break;

		case 'a' :

		for (j=0 ; j<4 ; j++)
		{	for (k=0 ; k<5 ; k++)
			{	for (i=1 ; i<4 ; i++)
			 	if (a[i-1][j]==0) { a[i-1][j]=a[i][j]; a[i][j]=0; } 
			}
		
			for (k=0 ; k<5 ; k++)
			{	for (i=1 ; i<4 ; i++)
			 	if (a[i-1][j]==a[i][j]) {a[i-1][j]=2*a[i][j]; a[i][j]=0; k=7;}
			}
			
			for (k=0 ; k<5 ; k++)
			{	for (i=1 ; i<4 ; i++)
			 	if (a[i-1][j]==0) { a[i-1][j]=a[i][j]; a[i][j]=0; } 
			}
		
		}
		break;

		case 'd' :
	
		for (j=0 ; j<4 ; j++)
		{	for (k=0 ; k<5 ; k++)
			{	for (i=2 ; i>-1 ; i=i-1)
			 	if (a[i+1][j]==0) { a[i+1][j]=a[i][j]; a[i][j]=0; } 
			}
		
			for (k=0 ; k<5 ; k++)
			{	for (i=2 ; i>-1 ; i=i-1)
			 	if (a[i+1][j]==a[i][j]) {a[i+1][j]=2*a[i][j]; a[i][j]=0; k=7;}
			}
			
			for (k=0 ; k<5 ; k++)
			{	for (i=2 ; i>-1 ; i=i-1)
			 	if (a[i+1][j]==0) { a[i+1][j]=a[i][j]; a[i][j]=0; } 
			}
		
		}
		break;
		
	}
	


	
		

	for (i=0 ; i<4 ; i++)
	for (j=0 ; j<4 ; j++)	
	f[i][j][1]=a[i][j];







	q=0;
	for (i=0 ; i<4 ; i++)
	for (j=0 ; j<4 ; j++)	
	if (f[i][j][0]!=f[i][j][1])
	q++;
	
	
		if (q!=0)
		{
		c=time(0);
		b=c%16;
	
		if (b<4)
		x=0;
		if (b>3 && b<8)
		x=1;
		if (b>7 && b<12)
		x=2;
		if (b>11)
		x=3;
		
		y=b%4;
			if (a[x][y]!=0)
			while (a[x][y]!=0)
			{c++;
			b=c%16;
		
			if (b<4)
			x=0;
			if (b>3 && b<8)
			x=1;
			if (b>7 && b<12)
			x=2;
			if (b>11)
			x=3;
			
			y=b%4;}
				
	
		a[x][y]=((c%2)+1)*2;
		
		}

		system("clear");
		
		//cout new
		for (j=3 ; j>-1 ; j=j-1)
		{
		for (i=0 ; i<3 ; i++)
		E[i]=0;
		E[3]=0;
		for (i=0 ; i<3 ; i++)
		{
		if (a[i][j]<10 && a[i][j]>-1)
		E[i]=9;

		if (a[i][j]<100 && a[i][j]>9)
		E[i]=8;

		if (a[i][j]<1000 && a[i][j]>99)
		E[i]=7;

		if (a[i][j]<10000 && a[i][j]>999)
		E[i]=6;

		if (a[i][j]<100000 && a[i][j]>9999)
		E[i]=5;

		if (a[i][j]<1000000 && a[i][j]>99999)
		E[i]=4;

		if (a[i][j]<10000000 && a[i][j]>999999)
		E[i]=3;

		if (a[i][j]<100000000 && a[i][j]>9999999)
		E[i]=2;

		if (a[i][j]<1000000000 && a[i][j]>99999999)
		E[i]=1;
		
		}		
		
		for (i=0 ; i<4 ; i++)
		{
		cout<<a[i][j];
		
		for (k=0 ; k<E[i] ; k++)
		cout<<" ";

		}

		
		cout<<endl<<endl<<endl<<endl;

		}



		/*// cout
		for (j=3 ; j>-1 ; j=j-1)
		{
		for (i=0 ; i<4 ; i++)
		cout<<a[i][j]<<"     ";
		cout<<endl<<endl<<endl;
		}
		//cout*/
		

		for (i=0 ; i<4 ; i++)
		for (j=0 ; j<4 ; j++)	
		f[i][j][0]=a[i][j];


		//tashkhis bakht
			if ( a[0][0]!=0  && a[0][1]!=0  && a[0][2]!=0  && a[0][3]!=0 && a[1][0]!=0 && a[1][1]!=0 && a[1][2]!=0 && a[1][3]!=0 && a[2][0]!=0 && a[2][1]!=0 && a[2][2]!=0 && a[2][3]!=0 && a[3][0]!=0 && a[3][1]!=0 && a[3][2]!=0 && a[3][3]!=0)
			{
			for (i=1 ; i<3 ; i++)
			for (j=1 ; j<3 ; j++)
			{
			if (a[i][j]!=a[i][j+1] &&  a[i][j]!=a[i][j-1] &&  a[i][j]!=a[i+1][j] &&  a[i][j]!=a[i-1][j])
			d++;
			}
			if (a[0][0]!=a[0][1] && a[0][0]!=a[1][0])
			d++;
			if (a[3][3]!=a[2][3] && a[3][3]!=a[3][2])
			d++;
			if (a[0][3]!=a[1][3] && a[0][3]!=a[0][2])
			d++;
			if (a[3][0]!=a[2][0] && a[3][0]!=a[3][1])
			d++;

			if (a[1][0]!=a[2][0])
			d++;
			if (a[0][1]!=a[0][2])
			d++;
			if (a[3][1]!=a[3][2])
			d++;
			if (a[1][3]!=a[2][3])
			d++;

			}
if (d==12)
p='i';
}
				}


		cout<<endl<<endl<<"*            "<<"GAME OVER"<<"            *"<<endl; 









return (0);

}

