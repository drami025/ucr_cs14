#include<iostream>
#include<vector>

using namespace std;

void makeVec(vector<int>& myVect)
{
	for(unsigned i = 0; i < 51; i+=3)
	{
		myVect.push_back(i);
	}
}

int binarySearch(int begin, int end, int num, const vector<int>& vec)
{	
		int mid = (end + begin)/2;
		
		if(vec.at(mid) == num)
		{
			return mid;
		}
		
		if(end == begin)
		{
			return -1;
		}
		
		if(num <= vec.at(mid))
			return binarySearch(begin, mid, num, vec);
		else
			return binarySearch(mid + 1, end, num, vec);
}

int main()
{
	vector<int> myVect;
	
	makeVec(myVect);
	cout << endl;
	
	cout << binarySearch(0, myVect.size() - 1, 33, myVect);
	
	cout << endl;
	
	
	
	return 0;
}
