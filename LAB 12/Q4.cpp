#include<iostream>
#include<string>
using namespace std;
void LPS(string pattern,int lps[]){
	int m = pattern.length();
	lps[0] = 0;
	int j = 0;
	int i = 1;
	while(i<m){
		if(pattern[i] == pattern[j]){
			j++;
			lps[i] = j;
			i++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	
}
void KMP(string text,string pattern){
	int m = pattern.length();
	int n = text.length();
	int lps[m] = {0};
	LPS(pattern,lps);
	int i = 0;
	int j = 0;
	while(i < n){
		if(pattern[j] ==text[i]){
			i++;
			j++;
			if(j==m){
				cout<<i-j<< " ";
				j = lps[j-1];
			}
		}
		else{
			if(i< n && pattern[j] != text[i]){
				if(j != 0){
					j = lps[j-1];
				}
				else{
					i++;
				}
			}
			
		}
	}
}

int main(){
	string text = "ababababc";
	string pattern = "abab";
	cout<<"KMP\n";
	cout<<"[";
	KMP(text,pattern);
	cout<<"]";
}