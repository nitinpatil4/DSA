#include <iostream>
using namespace std;

//partition fuction 

int partition(int arr[],int s,int e){
    //choose pivot
    int pivotindex=s;
    int pivotelement=arr[s];
    
    //count element less than pivot element
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivotelement){
            count++;
        }
    }
    
    //defining the right index
    int rightindex =s+count;
    swap(arr[pivotindex],arr[rightindex]);
    pivotindex=rightindex; 
    
    //ensure that left elements are small or right element are grater than pivotelement
    
    int i=s;
    int j=e;
    
    while(i< pivotindex && j>pivotindex){
        while(arr[i]<=pivotelement){
            i++;
        }
        while(arr[j]>pivotelement){
            j--;
        }
        
    }
    if(i< pivotindex && j>pivotindex){
        swap(arr[i],arr[j]);
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){
    //base case
    if(s>=e) return;
    //partition call
    int p=partition(arr,s,e);
    //recursive call
    //left case 
    quicksort(arr,s,p-1);
    
    //right case
    quicksort(arr,p+1,e);
    
}
int main() {
  int arr[] ={8,4,3,1,10,15,20};
  int n=7;
  int s=0;
  int e=n-1;
  quicksort(arr,s,e);
  
  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
  return 0;
  
}
