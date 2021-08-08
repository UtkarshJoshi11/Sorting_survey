#include <iostream>
#include<algorithm>
#include<vector>
#include <ctime>

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

//inner loop finds coorect osition of the element in the sorted part.
//Invariant: at the beginning of the i^th iteration array a[1..i-1] is sorted.  

void insertionSort(vector<int> &array, int n)
{
	for(int i=0;i<n;i++)
	{	
		int temp = array[i];
		int j= i-1;
		while(j>=0 && temp<array[j])
		{
			array[j+1]= array[j];
			j--;
		}
		array[++j]=temp;
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
	insertionSort(array, n);
	end = clock();
	
	
	//printArray(array, n);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time taken  %0.8f\n",cpu_time_used);
	if(is_sorted(array.begin(),array.end())) cout << "YES" << endl;

}
