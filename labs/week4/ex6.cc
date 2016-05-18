#include<iostream>
#include<vector>


using namespace std;

static int bsearch(int array[], int target, int array_len)
{
	int high = array_len, low = -1, probe;
	
	while(high - low > 1)
	{
		probe = (low + high)/2;
		if(array[probe] > target)
			high = probe;
		else
			low = probe;
	}
		
	return(low == -1 || array[low] != target)
		return -1;
	else
		return low;
}
//=========================Pros========================================
// -Saves memory in the stack since not called recursively.
//



//=========================Cons========================================
// -Need to know length of the array before hand
// - 
int main()
{
		int arr[25]; 
		for(unsigned i = 0, j = 0; i < 100; i+=4, j++)
		{
			arr[j] = i;
		}
		
		cout << bsearch(arr, 28, 25) << endl;
		return 0;
}
