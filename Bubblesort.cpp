#include <iostream>
#include<vector>
#include <time.h>

using namespace std;

void fillArray(vector<int> &array, int n)
{
	time_t t;
	time(&t);    //get current time
	srand(t);   //gives current time as seed for random number generator
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


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//inner loop places maximum element at the appropriate position.
//Invariant: at the beginning of the i^th iteration a[n-i,..n] is sorted.

void bubbleSort(vector<int> &array, int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
            swap(array[j],array[j+1]);
            swapped=1;
            }
        }
        if(!swapped) break;
    }
}


int main()
{
	int n;
	clock_t start, end;
    double cpu_time_used;
	printf("Enter the no. of numbers: ");
	scanf("%d", &n);
	
	vector<int> array(n);
	fillArray(array, n);
	
	start = clock();
	bubbleSort(array, n);
	end = clock();
	
//	printArray(array, n);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("    %f     time taken",cpu_time_used);

}
