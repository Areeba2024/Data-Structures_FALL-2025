#include<iostream>
#include<string>
using namespace std;
#define d 256
void RabinKarp(string text,string pattern,int q){
	int m = text.length();
	int n = pattern.length();
	int p = 0 ; 
	int t = 0 ;
	int h = 1; 
	if(n == 0 || n>m){
		cout<<"No pattern exists!"<<endl;
		return;
	}
	
	for(int i=0;i<n-1;i++){
		h = (h*d) % q;    
	}
	
	for(int i=0;i<n;i++){
		p = (d * p + pattern[i])%q;
		t = (d * t + text[i])%q;
	}
	for(int i=0;i<=m-n;i++){
		if(p==t){
			bool match = true;
			for(int j=0;j<n;j++ ){
				if(pattern[j] != text[i+j]){
					match = false;
					break;
				}
			}
		
			if(match){
				cout<<i<<" ";
			}
			else{
				cout<<"\nFalse Positive at index: "<<i<<endl;
			}
		}
			if(i < m-n){
				t = (d * (t-text[i]*h) + text[i+n])%q;
			
			if(t < 0){
				t = t + q;
			}
		}
	}
}
int main(){
	string text = "Data structures and Algorithms are fun. Algorithms make tasks easier";
	string pattern = "Algorithms";
	cout<<"\n RABIN KARP\n";
	int q = 101;
	RabinKarp(text,pattern,q);
}