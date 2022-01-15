/* 

	File: sequential-search.cc

	Author: Geun-Hyung Kim

	Description: 정수가 저장된 파일에서 정수 데이터를 읽어서 원하는 정수를 검색하는 순차탐색 프로그램

*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> fileread(string fname) {

	vector<int> buffer;
	int data;

	fstream in(fname, ios::in | ios::binary);

	for(int i = 0; i < 100; i++){
		in.read((char *)&data, sizeof(data));
		buffer.push_back(data);
	}

	return buffer;
}

bool sequentialSearch(vector<int> data, int num) {

	bool result = false;


	return result;
}

int main(int argc, char const *argv[])
{
	string fname;
	int searchnum;
	bool found;

	cout << "파일 이름을 입력하시오:";
	cin >> fname; cin.ignore();

	cout << "검색할 수는 입력하시오(1 ~ 255): ";
	cin >> searchnum; cin.ignore();

	found = sequentialSearch(fileread(fname), searchnum);

	return 0;
}