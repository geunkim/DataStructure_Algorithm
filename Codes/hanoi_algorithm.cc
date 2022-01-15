#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if(n == 1)
		cout << "(" << n <<"): " << from << " => " << to << endl;
	else 
	{
		hanoi(n-1, from, to, by); 
		cout << "(" << n <<"): " << from << " => " << to << endl;
		hanoi(n-1, by, from, to);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "원반의 수: ";
	cin >> n;

	hanoi(n, 1, 2, 3); 

	return 0;
}