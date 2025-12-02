#include<iostream>
#include<string>
using namespace std;

void BruteForce(string text,string pattern){
	int m = text.length();
	int n = pattern.length();
	int count = 0;
	for(int i = 0;i<=m-n;i++){
		int j=0;
		while(j<n){
			count++;
			if (pattern[j] != text[i+j]){
			break;
		}
		j++;}
		if(j==n){
			cout << i << " ";
		}
	}
	cout<<"\nTotal Comparisions: "<<count<<endl;
}

int main()
{
	string text = "the quick brown fox jumps over the lazy dog";
	string pattern = "the";
	cout<<"\n BRUTE FORCE\n";
	BruteForce(text,pattern);
}