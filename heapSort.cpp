#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include <time.h>
#define parent(i) i>>1;
#define left(i) i<<1;
#define right(i) ((i<<1) + 1);
using namespace std;

// Summary: Gives results slightly worst than that of merge sort. Advantage is, Heapsort
// does it in place.

//left,right,parent macros gives better performence.
//Using bitwise operators for extra optimization.

void fillArray(vector<int> &array, int n)
{
	time_t t;
	time(&t);    //get current time
	srand(t);   //gives current time as seed for random number generator
	for(int i = 1; i <= n; i++)
	{
		array[i] = rand()%(10*n);   //Doing mod to avoid very large numbers
	}
}
void printArray(vector<int> &array, int n)
{
	for(int i = 1; i <=n; i++)
	{
		printf("%d ", array[i]);
	}
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void max_heapify(vector<int> &a, int index,int heap_size)  // O(h) time.
{
	int l= left(index);
	int r= right(index);
	int largest;
	
	if(l<=heap_size && a[l]>a[index])
	largest=l;
	else largest=index;
	
	if(r<=heap_size && a[r]>a[largest])
	largest=r;
	
	if(largest!=index)
	{
	swap(a[largest],a[index]);
	max_heapify(a,largest,heap_size);
	}
}


void build_max_heap(vector<int> &a, int n)   // O(n) time.
{
	for(int i=n/2;i>=1;i--)
	max_heapify(a,i,n);
}

void heapSort(vector<int> &array, int n)
{
	int heap_size=n;
	build_max_heap(array,n);
	for(int i=n;i>=1;i--)
	{
		swap(array[1],array[i]);
		heap_size--;
		max_heapify(array,1,heap_size);
	}
}



int main()
{
	int n;
	clock_t start, end;
    double cpu_time_used;
    
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	
	vector<int> array(n+1);
	
	
	fillArray(array, n);
	start = clock();
	heapSort(array,n);
	end = clock();
	
	
	//printArray(array,n);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time taken  %0.8f\n",cpu_time_used);
	if(is_sorted(array.begin(),array.end())) cout << "YES" << endl;

}

