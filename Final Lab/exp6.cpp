#include <iostream>
using namespace std;

// Function to check (a+b)
bool checkAplusB(string s) {
    return (s == "a" || s == "b");
}

// Function to check ba(a+b)
bool checkBAplusB(string s) {
    if (s.length() == 3) {
        if (s[0] == 'b' && s[1] == 'a' && checkAplusB(string(1, s[2])))
            return true;
    }
    return false;
}

// Function to check a + ba(a+b)
bool checkAplusBAplusB(string s) {
    if (s == "a") return true;        // single 'a'
    if (checkBAplusB(s)) return true; // 'ba(a+b)'
    return false;
}

// Function to check [a + ba(a+b)]*
bool checkStarPattern(string s) {
    int i = 0;
    while (i < s.length()) {
        // Try to match "a"
        if (s[i] == 'a') {
            i++;
        }
        // Try to match "ba(a+b)"
        else if (i + 2 < s.length() && s[i] == 'b' && s[i+1] == 'a' &&
                 (s[i+2] == 'a' || s[i+2] == 'b')) {
            i += 3;
        }
        // No match
        else {
            return false;
        }
    }
    return true;
}

// Function to check b* a
bool checkBApattern(string s, string &rest) {
    int i = 0;
    // Count leading 'b's
    while (i < s.length() && s[i] == 'b') i++;

    // Next must be exactly one 'a'
    if (i < s.length() && s[i] == 'a') {
        i++;
        rest = s.substr(i); // rest of the string after b*a
        return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string to check b* a [a + ba(a+b)]* : ";
    cin >> input;

    string rest;
    if (checkBApattern(input, rest)) {
        if (checkStarPattern(rest)) {
            cout << "String matches the expression b* a [a + ba(a+b)]*\n";
        } else {
            cout << "String does NOT match [a + ba(a+b)]* part\n";
        }
    } else {
        cout << "String does NOT match b* a part\n";
    }

    return 0;
}

