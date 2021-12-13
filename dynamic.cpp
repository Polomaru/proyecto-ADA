#include "util.h"

int MAX = 200000;

std::vector<std::string> B = {"00","01","10","11"};
std::vector<std::string> cod = {"C1","C2","C3","C4"};

std::string min_cod_din(std::string s)
{
    std::vector<std::vector<std::tuple<std::string, int, int>>> A;

    A.resize(s.size()+1, std::vector<std::tuple<std::string, int, int>>(4));
    int i, j;


    for (i = 0; i < s.size()+1; i++)
    {
        for (j = 0; j < 4; j++)
        {
            A[i][j] = std::make_tuple("",-1,-1);
        }
    }

    int m1, m2, m3, m4;

    std::string c1, c2, c3, c4;
    int ic1, ic2, ic3, ic4;

    std::string t1, t2, t3;

    for(i = 0; i < 4; i++)
    {
        A[0][i] = std::make_tuple(B[i] + " ", 0, -1);
    }

    for(i = 1; i <= s.size(); i++)
    {
        for(j = 0; j < 4; j++)
        {
            c1 = codificar(s[i-1], cod[j]);
            c2 = codificar(s[i-1], cod[(j+1)%4]);
            c3 = codificar(s[i-1], cod[(j+2)%4]);
            c4 = codificar(s[i-1], cod[(j+3)%4]);
            
            // std::cout<< c1 <<" "<< c2 <<" "<<c3<< " "<< c4<<std::endl;
            ic1 = c1.size();
            ic2 = c2.size();
            ic3 = c3.size();
            ic4 = c4.size();

            if(!ic1) ic1 = MAX;
            if(!ic2) ic2 = MAX;
            if(!ic3) ic3 = MAX;
            if(!ic4) ic4 = MAX;

            t1 = traduccion(cod[j],cod[(j+1)%4]);
            t2 = traduccion(cod[j],cod[(j+2)%4]);
            t3 = traduccion(cod[j],cod[(j+3)%4]);
            
            m1 = std::get<1>(A[i-1][j]) + ic1;
            m2 = std::get<1>(A[i-1][(j+1)%4]) + ic2 + t1.size();
            m3 = std::get<1>(A[i-1][(j+2)%4]) + ic3 + t2.size();
            m4 = std::get<1>(A[i-1][(j+3)%4]) + ic4 + t3.size();

            int v[] = { m1,m2,m3,m4 };
            int* i1;   
            i1 = std::min_element(v, v+3);   
            
            if(*i1 == m1) A[i][j] = std::make_tuple(c1 + " ", m1, j);
            else if (*i1 == m2) A[i][j] = std::make_tuple(c2 + " " + t1 + " ", m2, (j+1)%4);
            else if (*i1 == m3) A[i][j] = std::make_tuple(c3 + " " + t2 + " ", m3, (j+2)%4);
            else if (*i1 == m4) A[i][j] = std::make_tuple(c4 + " " + t3 + " ", m4, (j+3)%4);
        }
    }

    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < A[i].size(); j++)
        {
            std::cout << std::get<0>(A[i][j])<<", "<<std::get<1>(A[i][j])<<", "<<std::get<2>(A[i][j])<<" ...... ";
        }std::cout<<std::endl<<std::endl;
    }
    return "a";
}
int main()
{
    // std::string cadena;
    // getline(std::cin,cadena);
    auto a = min_cod_din("`0a");
}