#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define exists !=std::string::npos

using namespace std;

vector<string> v;

void in() {
    ifstream fd("in.txt");
    string str, st;
    char t;
    while(fd>>std::noskipws>>t) {
        if(t=='"' || t==39 /* ' */) t=' '; // Pritaikoma HTML kodui, kadangi niekas paprastu link'u nebenaudoja
        str+=t;
    }
    std::istringstream ss(str);
    while(ss>>st) if(st.find("www") exists || st.find("http") exists) v.push_back(st);
    fd.close();
}



void out(ostream& print) {
    for(auto i : v) print << i << endl;
}

int main()
{
    in();
    ofstream fr("results.txt");
    out(fr);
    fr.close();
    out(cout);
    return 0;
}
