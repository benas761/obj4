#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

// 1 vector

struct w { //for 1 vector
    int count;
    std::string word;
    w(std::string s, int c) { word = s; count = c; }
    bool operator<(w a) const { return this->count < a.count; }
};
std::string input1(); // for 1 vector and 1 map
std::vector<w> vecread1(std::string in);
void merge1(std::vector<w>& v);
void out1(std::ostream& print, std::vector<w> v);

// 1 map
std::map<std::string, int> mapread1(std::string in);
void merge1(std::map<std::string, int>& m);
void out1(std::ostream& print, std::map<std::string, int> m);

// 2 vector
struct vecw{
    int count;
    std::string word;
    std::vector<int> lines;
    vecw(std::string s, int c, int l) { word = s; count = c; lines.push_back(l); }
    bool operator<(vecw a){ return this->count < a.count; }
};
std::string input2();
std::vector<vecw> vecread2(std::string in);
void merge2(std::vector<vecw>& v);
void out2(std::ostream& print, std::vector<vecw> v);

// 2 map

struct mapw{
    int count;
    std::set<int> lines;
    mapw(int c, int l) { count = c; lines.insert(l); }
};
std::map<std::string, mapw> mapread2(std::string in);
void merge2(std::map<std::string, mapw>& m);
void out2(std::ostream& print, std::map<std::string, mapw> m);

// 3 vector
std::vector<std::string> vecinput3();
void out3(std::ostream& print, std::vector<std::string>& v) { for(auto i : v) print << i << std::endl; }

// 3 map
std::map<std::string, unsigned> mapinput3();
void out3(std::ostream& print, std::map<std::string, unsigned>& v) { for(auto i : v) print << i.first << std::endl; }

int main()
{
    // 1 vector
    std::vector<w> v1 = vecread1(input1());
    merge1(v1);

    std::ofstream frvec1("1 vec.txt");
    out1(frvec1, v1); frvec1.close();
    v1.clear();

    // 1 map
    std::map<std::string, int> m1 = mapread1(input1());
    merge1(m1);
    std::ofstream frmap1("1 map.txt");
    out1(frmap1, m1); frmap1.close();
    m1.clear();

    // 2 vector
    std::vector<vecw> v2 = vecread2(input2());
    merge2(v2);
    std::ofstream frvec2("2 vec.txt");
    out2(frvec2, v2); frvec2.close();
    v2.clear();

    // 2 map
    std::map<std::string, mapw> m2 = mapread2(input2());
    merge2(m2);
    std::ofstream frmap2("2 map.txt");
    out2(frmap2, m2); frmap2.close();
    m2.clear();

    // 3 vector
    std::vector<std::string> v3 = vecinput3();
    std::ofstream frvec3("3 vec.txt");
    out3(frvec3, v3); frvec3.close();
    v3.clear();

    // 3 map
    std::map<std::string, unsigned> m3 = mapinput3();
    std::ofstream frmap3("3 map.txt");
    out3(frmap3, m3); frmap3.close();

    return 0;
}

// 1 vector

std::string input1() { // for 1 vector and 1 map
    std::string in = "";
    char t;
    std::ifstream fr("in12.txt");
    while(fr>>std::noskipws>>t){ // ima po 1 simboli
        if((t>64 && t<91) || (t>96 && t<123) || t==' ' || t=='\n') { // pasalina viska, isskyrus raides ir tarpus
            if(t>64 && t<91) t+=97-65; // pavercia didziasias raides mazosomis
            in+=t;
        }
    }
    fr.close();
    return in;
}


std::vector<w> vecread1(std::string in){
    std::vector<w> v;
    std::string t;
    std::istringstream ss(in);
    while(ss>>t) {
        bool sameWordExists = false;
        for(auto it = v.begin(); it != v.end(); it++) if(it->word == t) {
            it->count++;
            sameWordExists = true;
            break;
        }
        if(!sameWordExists) v.emplace_back(t, 1);
    }
    return v;
}

void merge1(std::vector<w>& v){
    v.erase( std::remove_if(v.begin(), v.end(), [](w a) {return a.count==1;}), v.end() );
    v.shrink_to_fit();
}

void out1(std::ostream& print, std::vector<w> v) {
    for(auto i : v)
        print << std::setw(20) << std::left << i.word << std::setw(5) << std::left << i.count << std::endl;
}

// 1 map

std::map<std::string, int> mapread1(std::string in){
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

void merge1(std::map<std::string, int>& m){
    for(auto it=m.begin(); it!=m.end();) {
        if(it->second == 1) it = m.erase(it);
        else it++;
    }
}

void out1(std::ostream& print, std::map<std::string, int> m) {
    for(auto i : m)
        print << std::setw(20) << std::left << i.first << std::setw(5) << std::left << i.second << std::endl;
}

// 2 vector

std::string input2() {
    std::string in = "";
    char t;
    std::ifstream fr("in12.txt");
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

std::vector<vecw> vecread2(std::string in){
    std::vector<vecw> v;
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

void merge2(std::vector<vecw>& v){
    for(auto i=v.begin(); i<v.end(); i++)
        (*i).lines.erase( unique( (*i).lines.begin(), (*i).lines.end() ), (*i).lines.end() ); // istrina vienodas eilutes
    v.erase( std::remove_if(v.begin(), v.end(), [](vecw a) {return a.count==1;}), v.end() ); // istrina nesikartojancius zodzius
    v.shrink_to_fit();
}

void out2(std::ostream& print, std::vector<vecw> v) {
    for(vecw i : v) {
            print << std::setw(10) << std::left << i.word << std::setw(5) << std::left << i.count << i.lines.front();
            for(auto j = i.lines.begin()+1; j<i.lines.end(); j++) print << '\n' << std::setw(15) << " " << *j;
            print << std::endl;
    }
}

// 2 map

std::map<std::string, mapw> mapread2(std::string in){
    std::map<std::string, mapw> m;
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
            else { mapw tt(1, line); m.emplace(t, tt); }
        }
    }
    return m;
}

void merge2(std::map<std::string, mapw>& m){
    for(auto it=m.begin(); it!=m.end();) {
        if((*it).second.count == 1) it = m.erase(it);
        else it++;
    }
}

void out2(std::ostream& print, std::map<std::string, mapw> m) {
    for(auto i : m) {
            print << std::setw(20) << std::left << i.first << std::setw(5) << std::left << i.second.count << *(i.second.lines.begin());
            for(auto it = std::next(i.second.lines.begin(), 1); it!=i.second.lines.end(); it++) print << '\n' << std::setw(25) << " " << *it;
            print << std::endl;
    }
}

// 3 vector

std::vector<std::string> vecinput3() {
    std::vector<std::string> v;
    std::ifstream fd("in3.txt");
    std::string str, st;
    char t;
    while(fd>>std::noskipws>>t) {
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<='9' || t=='.' || t=='/' || t==':' || t=='-') int temp=0; // Nereikalinga operacija, kad prie else prieiti
        else t = ' ';
        str+=t;
    }
    std::istringstream ss(str);
    while(ss>>st) if(st.find("www") != std::string::npos || st.find("http") != std::string::npos) v.push_back(st);
    fd.close();
    return v;
}

// 3 map

std::map<std::string, unsigned> mapinput3() {
    std::map<std::string, unsigned> m;
    std::ifstream fd("in3.txt");
    std::string str, st;
    char t;
    while(fd>>std::noskipws>>t) {
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<='9' || t=='.' || t=='/') t=t;
        else t = ' ';
        str+=t;
    }
    std::istringstream ss(str);
    while(ss>>st) if(st.find("www") != std::string::npos || st.find("http") != std::string::npos) m.emplace(st, 0);
    fd.close();
    return m;
}
