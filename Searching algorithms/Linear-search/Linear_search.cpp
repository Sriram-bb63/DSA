#include <iostream>
using namespace std;

int main()
{
	int arr[] = {7, 5, 3, 6, 9, 8, 4, 2, 0, 1};
	int x = 9;
	int len = sizeof(arr) / sizeof(arr[0]);
	int pos;
	for (int i = 0; i < len; i++) {
		if (arr[i] == x) {
			pos = i;
			break;
		}
		else {
			pos = -1;
		}
	}
	cout<<pos<<endl;
	return 0;
}