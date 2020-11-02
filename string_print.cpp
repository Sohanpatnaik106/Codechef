#include"iostream"
#include"string"
using namespace std;

string input_string() {
    string name;
    cout << "Enter the name : ";
    cin >> name;
    return name;
}

int input_no_of_times() {
    int no;
    cout << "Enter the number of times yout want to print : ";
    cin >> no;
    return no;
}

void print_string(string nm, int y) {
    cout << "The string " << nm << " is printed " << y << " times" << endl; 
    for(int i = 0; i < y; i++) {
        cout << nm << endl;
    }
}

int main() {
    string nm;
    nm = input_string();
    int y;
    y = input_no_of_times();
    
    print_string(nm, y);
    return 0;
}