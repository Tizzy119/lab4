#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

 bool f(int n)
 {
 	while(n > 0)
 	{
 		if(n % 10 > 1)return false;
 		n /= 10;
 	}
 	return true;
 }

int main(int argc, char *argv[])
{using namespace std;

	string display[7]={"","","","","","",""};
	string displaya[7]={"","","","","","",""};

	string units[10]={"","jeden ","dwa ","trzy ","cztery ","pięć ","sześć ","siedem ","osiem ","dziewięć "};
	string teens[11]={"","dziesięć ","jedenaście ","dwanaście ","trzynaście ","czternaście ","piętnaście ","szesnaście ","siedemnaście ","osiemnaście ","dziewiętnaście "};
	string teens_2[9]={"","dwadzieścia ","trzydzieści ","czterdzieści ","pięćdziesiąt ","sześćdziesiąt ","siedemdziesiąt ","osiemdziesiąt ","dziewięćdziesiąt "};
	string hundreds[10]={"","sto ","dwieście ","trzysta ","czterysta ","pięćset ","sześćset ","siedemset ","osiemset ","dziewięćset "};
	
	int n = atoi(argv[1]);
	int counter;
	int digit[7] = {0,0,0,0,0,0,0};
	int digit_1[7] = {0,0,0,0,0,0,0};
	int number = 1;
	int number_copy = number;

	while(number > 0)
	{
		if(f(number*n))break;
		number++;
	}

	int number_ka = number*n;
	
		for(int i = 0; i < 7 && number != 0; i++)
		{
			digit[i] = number % 10;

			number = number/10;
		}	

	if(digit[0]>0 && digit[1] == 0)
	{
		display[0]=units[digit[0]];
	}
	if(digit[1] == 1)
	{	
		display[1]=teens[digit[0]+1];
		display[2]=hundreds[digit[2]];
	}
	if(digit[1] == 0 || digit[1] > 1)
	{
		display[1]=teens_2[digit[1]-1];
		display[0]=units[digit[0]];
		display[2]=hundreds[digit[2]];
	}

	//tysiące
	
	if(digit[3]>0 && digit[4] == 0)
	{
		display[3]=units[digit[3]];
	}
	if(digit[4] == 1)
	{	
		display[4]=teens[digit[3]+1];
		display[5]=hundreds[digit[5]];
	}
	if(digit[4] == 0 || digit[4] > 1)
	{
		display[4]=teens_2[digit[4]-1];
		display[3]=units[digit[3]];
		display[5]=hundreds[digit[5]];
	}
	
	cout<<"k wynosi:";

	if(digit[3] != 0 or digit[4] != 0 or digit[5] != 0)
		{
		cout<<display[5]<<display[4]<<display[3]<<" tys. ";
		}

	cout<<display[2]<<display[1]<<display[0]<<endl;

	if(number_copy == 0)
	{
		cout<<"zero"<<endl;
	}
	
	if(number_copy == 1000000)
	{
		cout<<"milion";
	}

	for(int i = 0; i < 7 && number_ka != 0; i++)
		{
			digit[i] = number_ka % 10;

			number_ka = number_ka/10;
		}	

	if(digit[0]>0 && digit[1] == 0)
	{
		displaya[0]=units[digit[0]];
	}
	if(digit[1] == 1)
	{	
		displaya[1]=teens[digit[0]+1];
		displaya[2]=hundreds[digit[2]];
	}
	if(digit[1] == 0 || digit[1] > 1)
	{
		displaya[1]=teens_2[digit[1]-1];
		displaya[0]=units[digit[0]];
		displaya[2]=hundreds[digit[2]];
	}

	//tysiące
	
	if(digit[3]>0 && digit[4] == 0)
	{
		displaya[3]=units[digit[3]];
	}
	if(digit[4] == 1)
	{	
		displaya[4]=teens[digit[3]+1];
		displaya[5]=hundreds[digit[5]];
	}
	if(digit[4] == 0 || digit[4] > 1)
	{
		displaya[4]=teens_2[digit[4]-1];
		displaya[3]=units[digit[3]];
		displaya[5]=hundreds[digit[5]];
	}
	
	cout<<"n*k wynosi: ";

	if(digit[3] != 0 or digit[4] != 0 or digit[5] != 0)
		{
		cout<<displaya[5]<<displaya[4]<<displaya[3]<<" tys. ";
		}

	cout<<displaya[2]<<displaya[1]<<displaya[0]<<endl;
}