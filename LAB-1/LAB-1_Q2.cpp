#include<iostream>
#include<string>
using namespace std;

class Exam{
	string studentName;
	string date;
	int *score;
	public:
		Exam(string name, string date, int sc)
		{
			studentName = name;
			this->date = date;
			score =  new int(sc);
		}
		
		void setScore(int s){
			*score = s;
		}
		int getScore(){
			return *score;
		}
		void display(){
			cout << "Student Name: "<<studentName<<endl;
			cout<<"Date: "<<date<<endl;
			cout<<"Score: "<<*score<<endl;
		}
		
		~Exam()
		{
			delete score;
		}
};

int main(){
	Exam e1("Sadaf","25-09-2009",67);
	e1.display();
	Exam e2(e1);
	e2.display();
	e2.setScore(90);
	cout<<"\nResult after changes: "<<endl;
	e1.display(); // due to shallow copy the value of score changes
	e2.display(); // for both e1 and e2 as they have shared memory.
	
}
