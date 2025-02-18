#include<iostream>
#include<string>
using namespace std;

// declare and intialise
string str("Hello ");
string str1 = "hi";
string str2('a', 5);
string str3;
getline(cin, str3);
int size1 = str.size();

//at functiom
str.length();
if (str.empty()) {
    cout << "String is empty!" << endl;
}
str.insert(5, " beautiful");
cout << str;  // Output "Hello beautiful"
string sub = str.substr(6, 5);
cout << sub << std::endl;
size_t found = str.find("world");
if (found != std::string::npos) {
    std::cout << "'world' found at index " << found << std::endl;
}
string str1 = "Hello, world!";
string str2 = str1;
sstring str = "The quick brown fox";
string sub = "quick";

size_t position = str.find(sub);
if (position != std::string::npos) {
    cout << "Found substring at index: " << position << std::endl;
} else {
    cout << "Substring not found" << std::endl;
}
std::string str1 = "apple";
std::string str2 = "banana";

if (str1 == str2) {
    std::cout << "Strings are equal" << std::endl;
} else {
    std::cout << "Strings are different" << std::endl;
}

if (str1 < str2) {
    std::cout << "str1 is lexicographically less than str2" << std::endl;
} else {
    std::cout << "str1 is lexicographically greater than or equal to str2" << std::endl;
}

// Using compare() function
int result = str1.compare(str2);  // Returns 0 if equal, < 0 if str1 is less, > 0 if str1 is greater
if (result == 0) {
    cout << "Strings are equal" << std::endl;
} else {
    cout << "Strings are different" << std::endl;
}