#include<iostream>
#include<string>
using namespace std;

// firstly define a simple function 
// secondly use inline
// check the .
inline string::size_type compersize(string s1,string s2 )
{
    return s1.size()>s2.size()?s1.size():s2.size();
}

int main()
{
    string s1("hello,world");
    string s2="this is second";
    string::size_type length=compersize(s1,s2);
    cout<<length<<endl;
    return 0;
}