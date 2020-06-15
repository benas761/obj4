#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

std::string input() {
    std::string in = "";
    char t;
    std::ifstream fr("inputText.txt");
    while(fr>>std::noskipws>>t){ // ima po 1 simboli
        if((t>64 && t<91) || (t>96 && t<123) || t==' ' || t=='\n') { // pasalina viska, isskyrus raides ir tarpus
            if(t>64 && t<91) t+=97-65; // pavercia didziasias raides mazosomis
            in+=t;
        }
    }
    fr.close();
    return in;
}

std::map<std::string, int> read(std::string in){
    std::map<std::string, int> m;
    std::string t;
    std::istringstream ss(in);
    int line = 0;
    while(ss>>t) {
        auto it = m.find(t);
        if(it!=m.end()) it->second++;
        else m.emplace(t, 1);
    }
    return m;
}

void merge(std::map<std::string, int>& m){
    for(auto it=m.begin(); it!=m.end();) {
        if(it->second == 1) it = m.erase(it);
        else it++;
    }
}

void out(std::ostream& print, std::map<std::string, int> m) {
    for(auto i : m)
        print << std::setw(20) << std::left << i.first << std::setw(5) << std::left << i.second << std::endl;
}

int main()
{
    std::map<std::string, int> m = read(input());
    merge(m);

    std::ofstream fr("results.txt");
    out(fr, m);
    //out(std::cout, m);
    fr.close();
    return 0;
}
