#include <bits/stdc++.h>
 
using namespace std;

int BinarySearch(int arr[],int l,int r,int key)
{
    int mid= (l+r)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        BinarySearch(arr,l,mid,key);
    }
    else
    {
        BinarySearch(arr,mid+1,r,key);
    }
    return -1;
}

int main()
{
    int n,arr[n],key,indx;
    cout<<"Enter size:";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    indx=BinarySearch(arr,0,n,key);
    cout<<indx;
}
