#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

struct w{
    int count;
    std::set<int> lines;
    w(int c, int l) { count = c; lines.insert(l); }
};

std::string input() {
    std::string in = "";
    char t;
    std::ifstream fr("in.txt");
    while(fr>>std::noskipws>>t){ // ima po 1 simboli
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<='9' || t=='.' || t=='/' || t=='-' || t=='\n') { // pasalina viska, isskyrus raides ir tarpus
            if(t>64 && t<91) t+=97-65; // pavercia didziasias raides mazosomis
            else if(t=='\n') in+=" 000 "; // Issaugo \n perskaitomu formatu
            else in+=t;
        }
        else in+=' ';
    }
    fr.close();
    return in;
}

std::map<std::string, w> read(std::string in){
    std::map<std::string, w> m;
    std::string t;
    std::istringstream ss(in);
    int line = 0;
    while(ss>>t) {
        if(t=="000") line++;
        else if(std::count(t.begin(), t.end(), '.')>1) { // Ar turi nors 2 taskus
            bool near=false;
            for(int i=0; i<t.length()-1; i++) if(t[i]=='.' && t[i+1]=='.') near = true; // ar taskai vienas salia kito
            if(!near) {
                auto it = m.find(t);
                if(it!=m.end()) {
                    (*it).second.count++;
                    (*it).second.lines.emplace_hint((*it).second.lines.end(), line);
                }
                else { w tt(1, line); m.emplace(t, tt); }
            }
        }
    }
    return m;
}

void out(std::ostream& print, std::map<std::string, w> m) {
    for(auto i : m) {
            print << std::setw(100) << std::left << i.first << std::setw(5) << std::left << i.second.lines.size() <<'\n';
            for(auto it = i.second.lines.begin(); it!=i.second.lines.end(); it++) print << *it << " ";
            print << '\n';
    }
}

int main()
{
    std::map<std::string, w> m = read(input());

    std::ofstream fr("results.txt");
    out(fr, m);
    fr.close();
    return 0;
}
