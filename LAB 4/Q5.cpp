#include <iostream>
using namespace std;

void sortBirthYears(int arr[], int n) {
    int count2022 = 0, count2023 = 0, count2024 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2022) {
        	count2022++;
		}
        else if (arr[i] == 2023){
        	count2023++;
		} 
        else if (arr[i] == 2024){
        	count2024++;
		} 
    }
    int index = 0;
    for (int i = 0; i < count2022; i++){
    	arr[index++] = 2022;
	} 
    for (int i = 0; i < count2023; i++){
    	arr[index++] = 2023;
	} 
    for (int i = 0; i < count2024; i++){
    	arr[index++] = 2024;
	} 
}

int main() {
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBirthYears(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
