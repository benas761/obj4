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
    std::ifstream fr("inputText.txt");
    while(fr>>std::noskipws>>t){ // ima po 1 simboli
        if((t>64 && t<91) || (t>96 && t<123) || t==' ' || t=='\n') { // pasalina viska, isskyrus raides ir tarpus
            if(t>64 && t<91) t+=97-65; // pavercia didziasias raides mazosomis
            if(t=='\n') in+=" 000 "; // Issaugo \n perskaitomu formatu
            else in+=t;
        }
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
        else {
            auto it = m.find(t);
            if(it!=m.end()) {
                (*it).second.count++;
                (*it).second.lines.emplace_hint((*it).second.lines.end(), line);
            }
            else { w tt(1, line); m.emplace(t, tt); }
        }
    }
    return m;
}

void merge(std::map<std::string, w>& m){
    for(auto it=m.begin(); it!=m.end();) {
        if((*it).second.count == 1) it = m.erase(it);
        else it++;
    }
}

void out(std::ostream& print, std::map<std::string, w> m) {
    for(auto i : m) {
            print << std::setw(20) << std::left << i.first << std::setw(5) << std::left << i.second.count << *(i.second.lines.begin());
            for(auto it = std::next(i.second.lines.begin(), 1); it!=i.second.lines.end(); it++) print << '\n' << std::setw(25) << " " << *it;
            print << std::endl;
    }
}

int main()
{
    std::map<std::string, w> m = read(input());
    merge(m);

    std::ofstream fr("results.txt");
    out(fr, m);
    fr.close();
    return 0;
}
