#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string input = "Hello World 123";
    regex reg("([A-Z]+)([a-z]+)");
    smatch sm;

    if (regex_match(input, reg)) {
        cout << "All match" << endl;
    }
    else if (regex_search(input, sm, reg)) {
        while (regex_search(input, sm, reg)) {
            cout << "Partial match: (0: all, 1: lv1, 2: lv2, ...)" << endl;
            for (int i = 0; i < sm.size(); i++)
                cout << "[" << i << "] " << sm[i] << endl;
            cout << endl;
            input = sm.suffix().str();
        }
    }
    else {
        cout << "Not Match!" << endl;
    }

    input = regex_replace("Hello World 123", reg, "*****"); 
    cout << input << endl;
    return 0;
}
