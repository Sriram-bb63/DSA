#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// len=10; i=[0,9]=>[4-8]; j=[]
void jumpsearch(int x, int arr[])
{
	int step = 5;
	int len = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + len);
	for (int i = step; i < len; i = i + step) {
		if (x < arr[i]) {
			for (int j = i - step; j < i; j++) {
				if (arr[j] == x) {
					cout<<j<<endl;
					break;
				}
				else {
					cout<<-1<<endl;
				}
			}
		}
	}
}

int main()
{
	int arr[] = {7, 5, 3, 6, 9, 8, 4, 2, 0, 1};
	int x = 6;
	jumpsearch(x, arr);
	return 0;
}