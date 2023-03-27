#include <iostream>
using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    if(n<=1) return ;
    for(int i=1;i<n;i++){
        int ele=arr[i];
        int childIndex=i;
        int parentIndex=(childIndex-1)/2;
        while(parentIndex>=0){
            if(arr[childIndex]<arr[parentIndex]){
                int tmp=arr[parentIndex];
                arr[parentIndex]=arr[childIndex];
                arr[childIndex]=tmp;
            }else{break;}
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }
}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}   