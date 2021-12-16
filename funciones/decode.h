#ifndef _FUNCTIONS_DECO_
#define _FUNCTIONS_DECO_
#include "util.h"

int retraduccion(std::string s, int size)
{
    if (size == 3)
    {
        if (s == std::bitset<3>(5).to_string()) return 1;
        else if (s == std::bitset<3>(6).to_string()) return 2;
        else if (s == std::bitset<3>(7).to_string()) return 3;
    }
    else if (size == 5)
    {
        if (s == std::bitset<5>(29).to_string()) return 2;
        else if (s == std::bitset<5>(30).to_string()) return 3;
        else if (s == std::bitset<5>(31).to_string()) return 0;
    }
    else if (size == 6)
    {
        if (s == std::bitset<6>(61).to_string()) return 3;
        else if (s == std::bitset<6>(62).to_string()) return 0;
        else if (s == std::bitset<6>(63).to_string()) return 1;
    }
    else if (size == 7)
    {
        if (s == std::bitset<7>(125).to_string()) return 0;
        else if (s == std::bitset<7>(126).to_string()) return 1;
        else if (s == std::bitset<7>(127).to_string()) return 2;
    }
    return -1;
}
char decodec1(std::string s)
{
    int number = std::stoi(s, 0, 2);
    return C1[number];
}
char decodec2(std::string s)
{
    int number = std::stoi(s, 0, 2);
    return C2[number];
}
char decodec3(std::string s)
{
    int number = std::stoi(s, 0, 2);
    return C3[number];
}
char decodec4(std::string s)
{
    int number = std::stoi(s, 0, 2);
    return ' ' + number ;
}

std::vector<std::string> B = {"00","01","10","11"};
std::vector<std::string> cod = {"C1","C2","C3","C4"};

std::string decode(std::string s)
{
    std::string sreturn;

    int codact;

    std::string temp = s.substr(0,2);
    codact = std::stoi(temp, 0, 2);
    

    for(int i = 2; i < s.size();)
    {
        if(codact == 0 )
        {
            temp = s.substr(i,3);
            int retraduc = retraduccion(temp,temp.size());

            if( retraduc == -1) sreturn += decodec1(temp);
            else codact = retraduc;
            i+=3;
        }
        else if(codact == 1 )
        {
            temp = s.substr(i,5);
            int retraduc = retraduccion(temp,temp.size());
            
            if( retraduc == -1) sreturn += decodec2(temp);
            else codact = retraduc;

            i+=5;
        }
        else if(codact == 2 )
        {
            temp = s.substr(i,6);
            int retraduc = retraduccion(temp,temp.size());
            
            if( retraduc == -1) sreturn += decodec3(temp);
            else codact = retraduc;

            i+=6;
        }
        else if(codact == 3 )
        {
            temp = s.substr(i,7);
            int retraduc = retraduccion(temp,temp.size());
            
            if( retraduc == -1) sreturn += decodec4(temp);
            else codact = retraduc;

            i+=7;
        }
    }
    return sreturn;
}
#endif