#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> in() {
	std::vector<std::string> v;
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
    	if(!near && std::find(v.begin(), v.end(), st) == v.end()) v.emplace_back(st);
    }
    fd.close();
    return v;
}



void out(std::ostream& print, std::vector<std::string> v) {
    for(auto i = v.begin(); i!=v.end(); i++) print << (*i) << "\n\n";
}

int main()
{
	std::vector<std::string> v = in();
    std::ofstream fr("results.txt");
    out(fr, v);
    //out(cout, v);
    return 0;
}

