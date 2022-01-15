#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int result;
	ofstream outfile("seq_decreased_data.bin", ios::binary);

	if(!outfile.is_open()){
		cout << "out 파일이 열리지 않습니다." << endl;
	}

	srand((unsigned)time(0));

	do {
		result = 1 + rand() % 1000;
	}while(result < 700 || result > 750);
	

	int count = 0;
	while(count < 100) {
		cout << "(" << count << ")" << result << endl;
		outfile.write((char *)&result, sizeof(result));
		result -= 1 + rand() % 12;		
		count++;
	}
	
	outfile.close();

	ifstream infile("seq_decreased_data.bin", ios::binary);

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
