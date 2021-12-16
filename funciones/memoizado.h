#ifndef _FUNCTIONS_MEMO_
#define _FUNCTIONS_MEMO_
#include "util.h"

std::vector<std::vector<std::tuple<std::string, int, int>>> memoA;

std::tuple<std::string, int, int> OPTmemo(std::string s, int i, int j)
{
    if(std::get<1>(memoA[i][j]) < MAX  or i == 0) return memoA[i][j];

    std::string scod = codificar(s[i-1],cod[j]);
    
    int scodsize = (scod.empty())? MAX : scod.size();

    if(!scod.empty()) 
    {
        std::string t1, t2, t3;
        t1 = traduccion(cod[j],cod[(j+1)%4]);
        t2 = traduccion(cod[j],cod[(j+2)%4]);
        t3 = traduccion(cod[j],cod[(j+3)%4]);

        std::tuple<std::string, int, int> p1, p2, p3, p4;

        p1 = OPTmemo(s,i-1, j);
        p2 = OPTmemo(s,i-1, (j+1)%4);
        p3 = OPTmemo(s,i-1, (j+2)%4);
        p4 = OPTmemo(s,i-1, (j+3)%4);

        std::string m1, m2, m3, m4;

        m1 = scod;
        m2 = t1 + scod;
        m3 = t2 + scod;
        m4 = t3 + scod;

        int v[] = { int(std::get<1>(p1)) + scodsize, 
        std::get<1>(p2) + int(t1.size()) + scodsize,
        std::get<1>(p3) + int(t2.size()) + scodsize, 
        std::get<1>(p4) + int(t3.size()) + scodsize};

        int* i1;   
        i1 = std::min_element(v, v+4);   

        if(*i1 == v[0]) memoA[i][j] = std::make_tuple(m1, std::get<1>(p1) + scodsize, j);
        else if(*i1 == v[1]) memoA[i][j] = std::make_tuple(m2, std::get<1>(p2) + t1.size() + scodsize, (j+1)%4);
        else if(*i1 == v[2]) memoA[i][j] = std::make_tuple(m3, std::get<1>(p3) + t2.size() + scodsize, (j+2)%4);
        else if(*i1 == v[3]) memoA[i][j] = std::make_tuple(m4, std::get<1>(p4) + t3.size() + scodsize, (j+3)%4); 
    }
    return memoA[i][j];

}

std::string min_cod_memoizado(std::string s)
{
    memoA.resize(s.size()+1, std::vector<std::tuple<std::string, int, int>>(4));   
    std::string m1, m2, m3, m4;

    for (int i = 0; i < s.size()+1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            memoA[i][j] = std::make_tuple("",MAX,-1);
        }
    }

    for(int i = 0; i < 4; i++)
    {
        memoA[0][i] = std::make_tuple(B[i], 2, i);
    }

    std::tuple<std::string, int, int> p1, p2, p3, p4;
    p1 = OPTmemo(s,s.size(), 0);
    p2 = OPTmemo(s,s.size(), 1);
    p3 = OPTmemo(s,s.size(), 2);
    p4 = OPTmemo(s,s.size(), 3);

    int v[] = { std::get<1>(memoA[s.size()][0]), std::get<1>(memoA[s.size()][1]), std::get<1>(memoA[s.size()][2]), std::get<1>(memoA[s.size()][3])};
    int* i1;     
    i1 = std::min_element(v, v+4);  

    int caminofinal;
    if(*i1 == v[0]) caminofinal = 0;
    else if(*i1 == v[1]) caminofinal = 1;
    else if(*i1 == v[2]) caminofinal = 2;
    else if(*i1 == v[3]) caminofinal = 3;

    std::string sreturn = "";

    for(int i=s.size(); i >= 0; i--)
    {
        auto temp = memoA[i][caminofinal];
        sreturn = std::get<0>(temp) + sreturn;
        caminofinal = std::get<2>(temp);
    }
    
    return sreturn;
}

#endif