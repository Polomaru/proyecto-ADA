#include "util.h"



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
        A[0][i] = std::make_tuple(B[i], 2, -1);
    }

    for(i = 1; i <= s.size(); i++)
    {
        A[i][0] = std::make_tuple(" ", MAX, -1);
        A[i][1] = std::make_tuple(" ", MAX, -1);
        A[i][2] = std::make_tuple(" ", MAX, -1);
        A[i][3] = std::make_tuple(" ", MAX, -1);

        for(j = 0; j < 4; j++)
        {
            c1 = codificar(s[i-1], cod[j]);

            ic1 = c1.size();

            if(ic1) 
            {
                t1 = traduccion(cod[j],cod[(j+1)%4]);
                t2 = traduccion(cod[j],cod[(j+2)%4]);
                t3 = traduccion(cod[j],cod[(j+3)%4]);
                
                m1 = std::get<1>(A[i-1][j]) + ic1;
                m2 = std::get<1>(A[i-1][(j+1)%4]) + ic1 + t1.size();
                m3 = std::get<1>(A[i-1][(j+2)%4]) + ic1 + t2.size();
                m4 = std::get<1>(A[i-1][(j+3)%4]) + ic1 + t3.size();

                int v[] = { m1,m2,m3,m4 };
                int i1 = minelement(v);   
                
                if(i1 == m1) A[i][j] = std::make_tuple(c1, m1, j);
                else if (i1 == m2) A[i][j] = std::make_tuple(t1 + c1, m2, (j+1)%4);
                else if (i1 == m3) A[i][j] = std::make_tuple(t2 + c1, m3, (j+2)%4);
                else if (i1 == m4) A[i][j] = std::make_tuple(t3 + c1, m4, (j+3)%4);
            }

            
        }
    }
    std::string sreturn = "";
    

    int v1[] = { std::get<1>(A[s.size()][0]),std::get<1>(A[s.size()][1]),std::get<1>(A[s.size()][2]),std::get<1>(A[s.size()][3])};
    int minnum = minelement(v1);
    int idlast;
    
    if (minnum == std::get<1>(A[s.size()][0])) idlast = 0;
    else if (minnum == std::get<1>(A[s.size()][1])) idlast = 1;
    else if (minnum == std::get<1>(A[s.size()][2])) idlast = 2;
    else if (minnum == std::get<1>(A[s.size()][3])) idlast = 3;

    for (i = s.size(); i >= 0 ; i--)
    {
        sreturn = std::get<0>(A[i][idlast]) + sreturn ;
        idlast = std::get<2>(A[i][idlast]);
    }
    return sreturn;
}
int main()
{
    auto i = min_cod_din("`0aa");

    std::cout<<i.size()<<std::endl;
    std::cout<<i;

}