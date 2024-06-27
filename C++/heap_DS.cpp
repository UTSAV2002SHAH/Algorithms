#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


#define vi vector<int>
#define pii pai<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtine_popcount(x)



// heap Sort
// heap is a type of tree but may not be ballenced
// convert array into a heap
//Complete Binary Tree: A heap is a complete binary tree, 
//which means that all levels of the tree are fully filled except possibly the last level,
//which is filled from left to right.
//Heap Property: A heap satisfies the heap property, which can be either the "min heap property" or the "max heap property".
//In a min heap, the value of each node is less than or equal to the values of its children. 
//In a max heap, the value of each node is greater than or equal to the values of its children.

// Max heapify fuction
//                  till   from
void heapify(vi &a, int n, int i){
	int maxidx = i;
	int r = 2*i+2;
	int l = 2*i+1;
	
	if(l<n && a[maxidx]<a[l]){
		maxidx = l;
	}
	if(r<n && a[maxidx]<a[r]){
		maxidx = r;
	}
	
	if(maxidx != i){
		swap(a[i], a[maxidx]);
		heapify(a,n	,maxidx);
	}
	
	
		
}

// heapsortfuction
void heapsort(vi a)
{
	int n = a.size();
	
	for(int i=n/2;i>=0;i++){
		heapify(a, n, i);
	}
	
	for(int i=n-1;i>0;i--){
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

int main()
{
	// size of array
	int n;
	cin>>n;
	
	// vector container
	vi a(n);
	
	rep(i,0,n)
		cin >> a[i];
	
	heapsort(a);
	
	for(int i=0;i<a.size();i++){
		cout << a[i];
	}
}
