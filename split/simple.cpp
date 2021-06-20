#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int main(){
	
	string date1 = "/2021/06/06";
    string date2 = "/2021/06/07";
	string tmp;
	
    stringstream ss(date1);
	while(getline(ss, tmp, '/'))
		cout << tmp << " ";
	
    cout << endl;

    ss.clear();
    ss.str(date2);
	while(getline(ss, tmp, '/'))
		cout << tmp << " ";
	
    cout << endl;
    

	return 0;
}
