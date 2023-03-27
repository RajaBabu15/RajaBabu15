#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOneBrute(int n){
    if(n==1) return 0;

    int minusOne=countMinStepsToOneBrute(n-1);
    int divTwo=INT_MAX-1,divThree=INT_MAX-1;
    if(n%2==0) divTwo = countMinStepsToOneBrute(n/2);
    if(n%3==0) divThree = countMinStepsToOneBrute(n/3);
    return min(1+minusOne,1+min(divTwo,divThree));
}  

int countMinStepsToOneMemorizationHelper(int n,int *ans){
    if(n==1) return 0;
    
    if(ans[n]!=-1) return ans[n];
    int minusOne=countMinStepsToOneBrute(n-1);
    int divTwo=INT_MAX-1,divThree=INT_MAX-1;
    if(n%2==0) divTwo = countMinStepsToOneBrute(n/2);
    if(n%3==0) divThree = countMinStepsToOneBrute(n/3);

    ans[n]=min(1+minusOne,1+min(divTwo,divThree));
    return min(1+minusOne,1+min(divTwo,divThree));

}

int countMinStepsToOneMemorization(int n){
    int * ans = new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    return countMinStepsToOneMemorizationHelper(n,ans);
}

int countMinStepsToOneIterative(int n){
    int ans[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    ans[4]=2;
    ans[5]=3;
    if(n<=5) return ans[n];
    for(int i=6;i<=n;i++){
        int minusOne=ans[i-1];
        int divTwo=INT_MAX-1,divThree=INT_MAX-1;
        if(i%2==0) divTwo = ans[i/2];
        if(i%3==0) divThree = ans[i/3];
        ans[i]=min(1+minusOne,1+min(divTwo,divThree));
    }
    return ans[n];
}


int countMinStepsToOne(int n)
{
	//Write your code here
    int brute=0,memorization=0,iterative=0;
    //brute=countMinStepsToOneBrute(n);
    //memorization=countMinStepsToOneMemorization(n);
    iterative=countMinStepsToOneIterative(n);
    return iterative;
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}