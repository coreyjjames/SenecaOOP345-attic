// simple example illustrating with clarify how variable argument (variadic) templates work

// see fastforward.cpp

#include <iostream>
using namespace std;

template <typename T> 
void print(const T& t) {
// std::cout << __PRETTY_FUNCTION__ << "\n";
    cout << t << endl;
}

template <typename First, typename... Rest> 
void print(const First& first, const Rest&... rest) {
// std::cout << __PRETTY_FUNCTION__ << "\n";
    cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(int argc, char**argv)
{
    print(1); // calls first overloaded template
    
    // these call the second overloaded variadic template, 
    // which uses recursive template expansion as needed.
    print(10, 20);
    // expands templete which generates
    // print(10);
    // print(20);

    print(100, 200, 300);
    // expands templete which generates
    // print(100);
    // print(200);
    // print(300);

    print("first", 2, "third", 3.14159);
    // expands templete which generates
    // print("first");
    // print(2);
    // print("third");
    // print(3.14159);
}
