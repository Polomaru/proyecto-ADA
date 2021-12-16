#ifndef _FUNCTIONS_RECU_
#define _FUNCTIONS_RECU_
#include "util.h"

std::pair<std::string,int> OPT(std::string s, int i, int j)
{
    std::string scod = codificar(s[i],cod[j]);

    int scodsize = (scod.empty())? MAX : scod.size();

    if(!scod.empty() and i == 0) return std::make_pair(B[j] + scod, 2 + scod.size());
    else if (scod.empty()) return std::make_pair("", MAX);

    std::string t1, t2, t3;
    t1 = traduccion(cod[j],cod[(j+1)%4]);
    t2 = traduccion(cod[j],cod[(j+2)%4]);
    t3 = traduccion(cod[j],cod[(j+3)%4]);

    std::pair<std::string,int> p1, p2, p3, p4;

    p1 = OPT(s,i-1, j);
    p2 = OPT(s,i-1, (j+1)%4);
    p3 = OPT(s,i-1, (j+2)%4);
    p4 = OPT(s,i-1, (j+3)%4);

    std::string m1, m2, m3, m4;

    m1 = p1.first + scod;
    m2 = p2.first + t1 + scod;
    m3 = p3.first + t2 + scod;
    m4 = p4.first + t3 + scod;

    int v[] = { int(p1.second) + scodsize, 
    p2.second + int(t1.size()) + scodsize,
    p3.second + int(t2.size()) + scodsize, 
    p4.second + int(t3.size()) + scodsize};

    int* i1;   
    i1 = std::min_element(v, v+4);   

    if(*i1 == v[0]) return std::make_pair(m1, p1.second + scodsize);
    else if(*i1 == v[1]) return std::make_pair(m2, p2.second + t1.size() + scodsize);
    else if(*i1 == v[2]) return std::make_pair(m3, p3.second + t2.size() + scodsize);
    else if(*i1 == v[3]) return std::make_pair(m4, p4.second + t3.size() + scodsize); 

}

std::string min_cod_recursivo(std::string s)
{
    std::pair<std::string,int> p1, p2, p3, p4;
    std::string m1, m2, m3, m4;

    p1 = OPT(s,s.size()-1, 0);
    p2 = OPT(s,s.size()-1, 1);
    p3 = OPT(s,s.size()-1, 2);
    p4 = OPT(s,s.size()-1, 3);

    int v[] = { p1.second,p2.second,p3.second,p4.second };
    int* i1;     
    i1 = std::min_element(v, v+4);  

    if(*i1 == p1.second) return p1.first;
    else if(*i1 == p2.second) return p2.first;
    else if(*i1 == p3.second) return p3.first;
    else if(*i1 == p4.second) return p4.first; 
}
#endif
