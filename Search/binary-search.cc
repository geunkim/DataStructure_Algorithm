#include <iostream>
#define SIZE 9

using namespace std;

int main(int argc, char const *argv[])
{
	int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	bool found = false;
	int start = 0;
	int end = SIZE - 1;
	int searchnum;
	int mid;

	cout << "search number: ";
	cin >> searchnum; cin.ignore();

	do {
		if (start != end) mid = (start + end)/2;
		if (start == end) mid = start;
		cout << "start: " << start << ", end: " << end << ", mid: " << mid << endl;

		if(data[mid] == searchnum) { found = true; break;}
		else if(data[mid] < searchnum) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}while(start <= end);

	if(found) { cout << searchnum << " is in the data set" << endl;}
	else { cout << searchnum << " is not in the data set" << endl;}

	return 0;
}