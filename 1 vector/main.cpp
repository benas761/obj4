#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct w{
    int count;
    std::string word;
    w(std::string s, int c) { word = s; count = c; }
    bool operator<(w a) const { return this->count < a.count; }
};

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

std::vector<w> read(std::string in){
    std::vector<w> v;
    std::string t;
    std::istringstream ss(in);
    while(ss>>t) v.emplace_back(t, 1);
    return v;
}

void merge(std::vector<w>& v){
    for(auto i=v.begin(); i<v.end(); i++) {
        for(auto j=i; j<v.end(); j++) {
            if((*i).word == (*j).word) {
                (*i).count+=(*j).count;
                j = v.erase(j);
                j=i; // Kazkodel vienodus zodzius kitaip palieka.
            }
        }
    }
    v.erase( std::remove_if(v.begin(), v.end(), [](w a) {return a.count==1;}), v.end() );
    v.shrink_to_fit();
}

void out(std::ostream& print, std::vector<w> v) {
    for(auto i : v)
        print << std::setw(20) << std::left << i.word << std::setw(5) << std::left << i.count << std::endl;
}

int main()
{
    std::vector<w> v = read(input());
    merge(v);

    std::ofstream fr("results.txt");
    out(fr, v);
    fr.close();
    out(std::cout, v);
    return 0;
}
