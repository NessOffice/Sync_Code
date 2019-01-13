#include <iostream>
#include <cstdio>
#include <vector>
#include <string> 
#include <fstream>
using namespace std;
int main(){
	int flag=1;
	fstream f1("my_out.txt");
	fstream f2("out.txt");
	vector<string> words1;
	vector<string> words2;
	string line;
	while(getline(f1, line))
		words1.push_back(line);
	while(getline(f2, line))
		words2.push_back(line);
	if(words1.size() != words2.size())
		cout<<"the length is different"<<endl;
	for(int i=0;i<words1.size() && i<words2.size();i++)
		if(words1[i] != words2[i]){
			cout<<i+1<<": yours="<<words1[i]<<"   key="<<words2[i]<<endl;
			flag = 0;	
		}
	if(flag && words1.size() == words2.size())
		cout<<"identical";
	return 0;
} 
