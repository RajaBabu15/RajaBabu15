#include<iostream>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
	if(value<=0) return 0;
	if(numDenominations<=0) return 0;
	int count=0;
	cout<<numDenominations<<"->>>>"<<value<<"::";
	for(int i=0;i<numDenominations;i++){
		if(value<denominations[i]) continue;
		else if(value==denominations[i]) count++;
		else count+=countWaysToMakeChange(denominations+i-1, numDenominations-i-1,value-denominations[i]);
	}
	return count;
}

#include <iostream>
using namespace std;


int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}