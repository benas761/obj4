#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>

std::set<std::string> in() {
	std::set<std::string> v;
    std::ifstream fd("in.txt");
    std::string str, st;
    char t;
    while(fd>>std::noskipws>>t) {
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<='9' || t=='.' || t=='/' || t=='-') t=t;
        else t = ' ';
        str+=t;
    }
    std::istringstream ss(str);
    while(ss>>st) if(std::count(st.begin(), st.end(), '.')>1) {
    	bool near=false;
    	for(int i=0; i<st.length()-1; i++) if(st[i]=='.' && st[i+1]=='.') near = true;
    	if(!near) v.emplace(st);
    }
    fd.close();
    return v;
}



void out(std::ostream& print, std::set<std::string> v) {
    for(auto i = v.begin(); i!=v.end(); i++) print << (*i) << "\n\n";
}

int main()
{
	std::set<std::string> s = in();
    std::ofstream fr("results.txt");
    out(fr, s);
    //out(cout);
    return 0;
}

