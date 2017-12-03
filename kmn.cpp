#include <iostream>

#include <stdlib.h>

using namespace std;

int main()
{
 	int numbers, k, kvals[25], prevKvals[25], steps = 1, addition[25][100], count = 0, groups[25][100], min, groupnum, value, sum, ok = 1, nums[100];
 	cout << "\nHow many numbers you want to enter: ";
 	cin >> numbers;
 	cout << "\nEnter value of k: ";
 	cin >> k;
 	for(int i = 0; i < numbers; i++)
 	{
 		 cout << "\nEnter Number " << i+1 << ": ";
 		 cin >> nums[i];
 	}
 	for(int i = 0; i < 3; i++)
 	{
 		 kvals[i] = nums[i];
 	}
 	cout << "our nos are: ";
 	for(int i = 0; i < numbers; i++)
 	{
  		cout << nums[i] << ", ";
 	}
 	while(ok == 1)
 	{
  		cout << endl << "\nItration Number: " << steps;
  		for(int i = 0; i < k; i++)
  		{
            		for(int j = 0; j < numbers; j++)
            		{
    				addition[i][j] = abs(kvals[i] - nums[j]);
  			}
  		}
  		for(int i = 0; i < numbers; i++)
  		{
   			min = 100000;
            		for(int j = 0; j < k; j++)
            		{
    				if(addition[j][i] < min)
    				{
        				min = addition[j][i];
        				value = nums[i];
        				groupnum = j;
    				}
   			}
   			groups[groupnum][i] = value;
  		}
  	cout << endl << "\nCalculations" << endl;
  	for(int i = 0; i < numbers; i++)
  	{
        	for(int j = 0; j < k; j++)
            	{
    			cout << addition[j][i] << "\t";
   		}
   		cout << endl;
  	}
  	cout << endl << "\nGruops" << endl;
     	for(int i = 0; i < k; i++)
  	{
   		sum = 0;
   		count = 0;
   		cout << "\nGroup " << i+1 << ": ";
            	for(int j = 0; j < numbers; j++)
            	{
    			if(groups[i][j] !='\0')
    			{
     				cout << groups[i][j] << "\t";
     				sum += groups[i][j];
     				count++;
    			}
   		}
   		prevKvals[i] = kvals[i];
   		kvals[i] = sum/count;
   		cout << "\t=\t" << kvals[i] << endl;
  	}
  	for(int i = 0; i < 25; i++)
  	{
   		for(int j = 0; j < 100; j++)
   		{
    			groups[i][j] = '\0';
   		}
  	}
  	ok = 0;
  	for(int i = 0; i < k; i++)
  	{
   		if(prevKvals[i] != kvals[i])
   		{
       			ok = 1;
   		}
  	}
     	steps++;
 	} 
return 0;
}
