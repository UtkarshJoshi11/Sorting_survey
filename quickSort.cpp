#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include <time.h>

using namespace std;

void fillArray(vector<int> &array, int n)
{
	time_t t;
	time(&t);//get current time
	srand(t);//gives current time as seed for random number generator
	for(int i = 0; i < n; i++)
	{
		array[i] = rand()%(10*n);//Doing mod to avoid very large numbers
	}
}
void printArray(vector<int> &array, int n)
{
	for(int i = 0; i < n; i++)
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


// Invariant : All elements in low to i-1 are less than or equal to pivot
// All elements between index i to j-1 are greater than pivot
// ALl elements between j to high -1 are unprocessed

// After inner for loop completes, j == high hence no unprocessed elements
// indices <= i have elements <= pivot
// indeices i to high-1 have elements greater thna pivot
// swapping array[i+1] with array[high] places pivot in the correct position i.e subproblem is solved.
int partition(vector<int> &array, int low, int high)
{
	int pivot = array[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(array[j]<=pivot)
		{
		i++;
		swap(array[i],array[j]);
		}
	}
	i++;
	swap(array[i],array[high]);
	return i;
	
}

void quickSort(vector<int> &array, int low, int high)
{
	if(low<high)
	{
		int index= partition(array,low,high);
		quickSort(array, low, index-1);
	    quickSort(array, index+1,high);
    }
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
	quickSort(array,0, n-1);
	end = clock();
	//printArray(array,n);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time taken  %0.8f\n",cpu_time_used);
	if(is_sorted(array.begin(),array.end())) cout << "YES" << endl;

}
