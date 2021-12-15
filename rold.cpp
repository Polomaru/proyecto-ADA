#include "util.h"

std::vector<std::string> B = {"00","01","10","11"};
std::vector<std::string> cod = {"C1","C2","C3","C4"};

std::string OPT(std::string s, int i, int j)
{
    std::string scod = codificar(s[i],cod[j]);

    if(!scod.empty() and i == 0) return B[j] + scod;
    else if (scod.empty()) return  SMAX;

    std::string t1, t2, t3;
    t1 = traduccion(cod[j],cod[(j+1)%4]);
    t2 = traduccion(cod[j],cod[(j+2)%4]);
    t3 = traduccion(cod[j],cod[(j+3)%4]);

    std::string m1, m2, m3, m4;

    m1 = OPT(s,i-1, j) + scod;
    m2 = OPT(s,i-1, (j+1)%4) + t1 + scod;
    m3 = OPT(s,i-1, (j+1)%4) + t2 + scod;
    m4 = OPT(s,i-1, (j+1)%4) + t3 + scod;

    int v[] = { m1.size(),m2.size(),m3.size(),m4.size() };
    int* i1;   
    i1 = std::min_element(v, v+4);   

    std::cout<< m1.size()<<std::endl;
    std::cout<< m1<<std::endl;
    std::cout<< m2.size()<<std::endl;
    std::cout<< m2<<std::endl;
    std::cout<< m3.size()<<std::endl;
    std::cout<< m3<<std::endl;
    std::cout<< m4.size()<<std::endl;
    std::cout<< m4<<std::endl<<"\n";

    if(*i1 == m1.size()) return m1;
    else if(*i1 == m2.size()) return m2;
    else if(*i1 == m3.size()) return m3;
    else if(*i1 == m4.size()) return m4; 

}

std::string min_cod_recursivo(std::string s)
{
    std::string m1, m2, m3, m4;

    m1 = OPT(s,s.size()-1, 0);
    m2 = OPT(s,s.size()-1, 1);
    m3 = OPT(s,s.size()-1, 2);
    m4 = OPT(s,s.size()-1, 3);

    int v[] = { m1.size(),m2.size(),m3.size(),m4.size() };
    int* i1;   
    i1 = std::min_element(v, v+4);  
     
    std::cout<< m1.size()<<std::endl;
    std::cout<< m1<<std::endl;
    std::cout<< m2.size()<<std::endl;
    std::cout<< m2<<std::endl;
    std::cout<< m3.size()<<std::endl;
    std::cout<< m3<<std::endl;
    std::cout<< m4.size()<<std::endl;
    std::cout<< m4<<std::endl<<"\n";

    std::cout<<*i1<<std::endl;
    if(*i1 == m1.size()) return m1;
    else if(*i1 == m2.size()) return m2;
    else if(*i1 == m3.size()) return m3;
    else if(*i1 == m4.size()) return m4; 
}

int main()
{
    std::cout<<min_cod_recursivo("`0");
}