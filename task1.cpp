#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void checkingpalindrome(string String) {
    bool isPalindrome = true;  //assuming true 
    string str_cleaned;

    //For Palindrome: need to deal with Punctuation and Case 
      for (int i = 0; i < String.length(); i++) {
        if (isalnum(String[i])) {
            str_cleaned+= tolower(String[i]);}
    }

    //Actual logic for palindrome 
    for (int i = 0; i < str_cleaned.length() / 2; i++) {
        if (str_cleaned[i] != str_cleaned[str_cleaned.length() - i - 1]) {
            isPalindrome = false;
            break; //to end it as soon as we find one that isn't same 
        }
    }

    if (isPalindrome) {
        cout << "The string \"" << String << "\" is a palindrome." << endl;
    } else {
        cout << "The string \"" << String << "\" is not a palindrome." << endl;}
}

int main() {
    string input;
    cout << "Enter the string: ";
    getline(cin, input);  // to deal with the spaces
    checkingpalindrome(input);
    return 0;
}