#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int result;
	ofstream outfile("random_data.bin", ios::binary);
	int flag[256] = {0,};


	if(!outfile.is_open()){
		cout << "out 파일이 열리지 않습니다." << endl;
	}

	srand((unsigned)time(0));

	int count = 0;
	while(count < 100) {
		result = rand() % 255;
		if(flag[result] == 0) {
			flag[result] = 1;
			cout << "(" << count << ")" << result << endl;
			outfile.write((char *)&result, sizeof(result));
			count++;
		}
	}
	
	outfile.close();

	ifstream infile("random_data.bin", ios::binary);

	if(!infile.is_open()){
		cout << "infile 파일이 열리지 않습니다." << endl;
	}

	for(int i = 0; i < 100; i++){
		infile.read((char *)&result, sizeof(result));
		cout << "[" << i << "]" << result << endl;
	}

	infile.close();

	return 0;
}
