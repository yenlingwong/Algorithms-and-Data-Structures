/*
CH-231-A
a2_p5.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main() {
    map<string, string> m;
    string data, name, dob;
    string search_name;
    
    ifstream myfile("data.txt");
    if (myfile.is_open()) {
        while(!myfile.eof()) {
            getline(myfile, data);
// read the data from a file called “data.txt” 
// name followed by a corresponding birthday date on different lines repeated for many persons. 

            string delimiter = "0123456789";
            size_t position = data.find_first_of(delimiter);
            name = data.substr(0, position - 1);
            dob = data.substr(position, data.length() - 1);
            m.insert(pair<string, string>(name, dob));
// use a map to store names and birthday dates.
        }
    } else {
        cout << "Unable to open file!" << endl;
    }
    myfile.close();

    cout << "Whose birthdate are you searching for?" << endl;
    cout << "Please do not add an additional space after the name." << endl;
    getline(cin, search_name);
// asking for a name from the keyboard

    map<string, string>::iterator itera;
    itera = m.find(search_name);
    if (itera != m.end()) {
        cout << itera->second << endl;
// printing on the standard output the corresponding birthday date.
    } else {
        cout << "Name not found!" << endl;
    }

    return 0;
}