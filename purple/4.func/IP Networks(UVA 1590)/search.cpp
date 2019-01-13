#include <iostream>
#include <cstdio>
#include <vector>
#include <string> 
#include <fstream>
using namespace std;
int main(){
	int num = 0;
	fstream f("in.txt");
	vector<string> words;
	string line;
	while(getline(f, line))
		words.push_back(line);
	for(int i=0;i<words.size();i++)
	{
		if(words[i].length()<5) num++;
		if(num==38919){cout<<i;break;}
	}
	return 0;
} 
