#include <vector>
using namespace std;
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        if(isEmpty()) return ;
        pq.push_back(element);
        int lastIndex=getSize()-1;
        int childIndex=lastIndex,parentIndex=(childIndex-1)/2;
        while(parentIndex>0){
            if(pq[parentIndex]<pq[childIndex]){
                int tmp=pq[parentIndex];
                pq[parentIndex]=pq[childIndex];
                pq[childIndex]=tmp;
            }
            else break;
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()) return 0;
        int ans=pq[0];
        int last=pq[getSize()-1];
        pq[0]=last;
        pq.pop_back();
        int parentIndex=0,childIndex1,childIndex2,maxChildIndex,tmp,lastIndex=getSize()-1;
        while(parentIndex<lastIndex){
            childIndex1=2*parentIndex+1;
            childIndex2=2*parentIndex+2;
            if(childIndex1>lastIndex) break;
            else if (childIndex1==lastIndex) maxChildIndex=childIndex1;
            else maxChildIndex=(pq[childIndex1]>pq[childIndex2])?childIndex1:childIndex2;
            if(pq[parentIndex]<pq[maxChildIndex]){
                tmp=pq[parentIndex];
                pq[parentIndex]=pq[maxChildIndex];
                pq[maxChildIndex]=tmp;
            }else break;
            parentIndex=maxChildIndex;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return 0==getSize();
    }
};