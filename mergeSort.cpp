#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include <time.h>
//#define swap(x, y) { int temp = x; x = y; y = temp; }
using namespace std;

void fillArray(vector<int> &array, int n)
{
	time_t t;
	time(&t);      //get current time
	srand(t);     //gives current time as seed for random number generator
	for(int i = 0; i < n; i++)
	{
		array[i] = rand()%(10*n);    //Doing mod to avoid very large numbers
	}
}

void printArray(vector<int> &array, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}


// using swap macro result sin more running time for some reason. 
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void merge(vector<int> &array, int low, int mid, int high)
{
	int n1= mid-low+2;
	int n2= high-mid+1;
	vector<int> left(n1), right(n2);   // Extra space for large values at the end.
	
	for(int i=0;i<n1-1;i++)
	left[i]=array[low+i];
	for(int i=0;i<n2-1;i++)
	right[i]=array[mid+1+i];
	
	left[n1-1]=INT_MAX;
	right[n2-1]=INT_MAX;  // This is great idea (Taken from CLRS). It saves us from writing 
						 // 2 loops in the end.
	
	int i=0,j=0,k=low;
	while(k<high+1)
	{
		if(left[i]<=right[j])
			array[k++]=left[i++];
		else
			array[k++]=right[j++];
	}
}



void mergeSort(vector<int> &array, int low, int high)  
{
	if(low>=high)
	return;
	int mid = (low+high)/2;
	mergeSort(array,low,mid);
	mergeSort(array,mid+1,high);
	merge(array,low,mid,high);
}




int main()
{
	int n;
	clock_t start, end;
    double cpu_time_used;
    
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	
	vector<int> array(n);
	
	fillArray(array, n);
	
	start = clock();
	mergeSort(array, 0,n-1);
//	printArray(array,n);
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time taken  %0.8f\n",cpu_time_used);
	if(is_sorted(array.begin(),array.end())) cout << "YES" << endl; // check

}
