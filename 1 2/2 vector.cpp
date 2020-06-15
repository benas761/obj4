#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct w{
    int count;
    std::string word;
    std::vector<int> lines;
    w(std::string s, int c, int l) { word = s; count = c; lines.push_back(l); }
    bool operator<(w a){ return this->count < a.count; }
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

std::vector<w> read(std::string in){
    std::vector<w> v;
    std::string t;
    std::istringstream ss(in);
    int line = 0;
    while(ss>>t) {
        if(t=="000") line++;
        else {
            bool sameWordExists = false;
            for(auto it = v.begin(); it != v.end(); it++) if(it->word == t) {
                it->count++;
                (*it).lines.push_back(line);
                sameWordExists = true;
                break;
            }
            if(!sameWordExists) v.emplace_back(t, 1, line);
        }
    }
    return v;
}

void merge(std::vector<w>& v){
    for(auto i=v.begin(); i<v.end(); i++)
        (*i).lines.erase( unique( (*i).lines.begin(), (*i).lines.end() ), (*i).lines.end() ); // istrina vienodas eilutes
    v.erase( std::remove_if(v.begin(), v.end(), [](w a) {return a.count==1;}), v.end() ); // istrina nesikartojancius zodzius
    v.shrink_to_fit();
}

void out(std::ostream& print, std::vector<w> v) {
    for(w i : v) {
            print << std::setw(10) << std::left << i.word << std::setw(5) << std::left << i.count << i.lines.front();
            for(auto j = i.lines.begin()+1; j<i.lines.end(); j++) print << '\n' << std::setw(15) << " " << *j;
            print << std::endl;
    }
}

int main()
{
    std::vector<w> v = read(input());
    merge(v);
    //sort(v.begin(), v.end(), [](w a, w b) {return a.count<b.count;});
    std::ofstream fr("results.txt");
    out(fr, v);
    fr.close();
    return 0;
}
