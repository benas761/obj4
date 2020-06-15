#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#define exists !=std::string::npos

using namespace std;

map<string, unsigned> v;

void in() {
    ifstream fd("in.txt");
    string str, st;
    char t;
    while(fd>>std::noskipws>>t) {
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<='9' || t=='.' || t=='/' || t=='-') t=t;
        else t = ' ';
        str+=t;
    }
    std::istringstream ss(str);
    while(ss>>st) if(st.find("www") exists || st.find("http") exists) v.emplace(st, 0);
    fd.close();
}



void out(ostream& print) {
    for(auto i = v.begin(); i!=v.end(); i++) print << (*i).first << "\n\n";
}

int main()
{
    in();
    ofstream fr("results.txt");
    out(fr);
    fr.close();
    //out(cout);
    return 0;
}
