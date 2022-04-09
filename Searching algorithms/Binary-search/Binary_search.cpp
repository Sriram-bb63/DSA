#include <iostream>
using namespace std;

int binarysearch(int arr[], int x, int left, int right)
{
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] > x) {
			return binarysearch(arr, x, left, mid-1);
		}
		else {
			return binarysearch(arr, x, mid+1, right);
		}
	}
	else {
		return -1;
	}
}


int main()
{
	int arr[] = {7, 5, 3, 6, 9, 8, 4, 2, 1, 0};
	int x = 3;
	int len = sizeof(arr) / sizeof(arr[0]);
	cout<<binarysearch(arr, x, 0, len)<<endl;
	return 0;
}