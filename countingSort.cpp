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

void countingSort(vector<int> &array, int n)
{
	vector<int> hash(10 * n, 0);
	
	for(int i=0;i < n;i++)
	hash[array[i]]++;
	
	for(int i=0,j=0;i< 10 * n; i++)
	{
		while(hash[i]>0)
		{
			array[j++]=i;
			hash[i]--;
		}
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
	countingSort(array, n);
	end = clock();
	//printArray(array,n);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time taken  %0.8f\n",cpu_time_used);
	if(is_sorted(array.begin(),array.end())) cout << "YES" << endl;

}

