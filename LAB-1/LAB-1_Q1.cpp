#include<iostream>
using namespace std;

class BankAccount{
	private:
		
		int accNumber;
		double balance;
	public:
		BankAccount(int acc=0, double bal=0.0){
			accNumber = acc;
			balance = bal;
		}
		
		BankAccount(const BankAccount& obj){
			accNumber = obj.accNumber;
			balance = obj.balance;
		}
		
		void deduct(double amount)
		{
			if(amount> balance){
				cout<<"Insufficent Balance!"<<endl;
			}
			else{
				balance -= amount;
			}
		}
		
		double getBalance(){
			return balance;
		}
};

int main(){
	BankAccount account1;
	cout<<"Account1 balance is "<< account1.getBalance()<<endl;
	BankAccount account2(2345432,1000);
	cout<<"Account2 balance is "<< account2.getBalance()<<endl;
	BankAccount account3(account2);
	account3.deduct(200);
	cout<<"Account3 balance is "<< account3.getBalance()<<endl;
	cout<<"Account2 balance is "<< account2.getBalance()<<endl;
	
	
	
	

}