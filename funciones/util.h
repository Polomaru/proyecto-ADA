#ifndef _FUNCTIONS_UTIL_
#define _FUNCTIONS_UTIL_

#include <iostream>
#include <bitset>
#include <unordered_map>
#include <tuple>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdexcept>

int MAX = 900000;

std::vector<std::string> B = {"00","01","10","11"};
std::vector<std::string> cod = {"C1","C2","C3","C4"};

const char C1[] = {'a', 'e', 'i', 'o', 'u'};
const char C2[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '0','1','2','3','4','5','6','7','8', '9', char(32), '!', '"', '#', '$', '%','&' ,'\'', '('};
const char C3[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '[', '\\', ']', '^', '_',
        '{', '|', '}', '~'};
bool es_vocal_minuscula(char c)
{
    const char minusculas[] = {'a', 'e', 'i', 'o', 'u'};
    for (auto i : minusculas) if (c==i) return true;
    return false;
}

bool es_vocal_mayuscula(char c)
{
    const char mayusculas[] = {'A', 'E', 'I', 'O', 'U'};
    for (auto i: mayusculas) if (c==i) return true;
    return false;

}

bool esta_en_c1(char c)
{
    return es_vocal_minuscula(c);
}

bool esta_en_c2(char c)
{
    return es_vocal_mayuscula(c) || es_vocal_minuscula(c) || ('0' <= c && c <= '9') || (32 <= c && c <= 40);
}

bool esta_en_c3(char c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (91 <= c && c <= 95) || (123 <= c && c <= 126);
}

bool esta_en_c4(char c)
{
    return (32 <= c && c <= 126);
}


std::string interseccion_minima (char c1, char c2)
{
    if (esta_en_c1(c1) && esta_en_c1(c2))
    {
         return "C1";
    }
    else if (esta_en_c2(c1) && esta_en_c2(c2))
    {
        return "C2";
    }
    else if (esta_en_c3(c1) && esta_en_c3(c2))
    {
        return "C3";
    }
    return "C4";
}


std::string codificar(char c, std::string codificacion)
{
    if (codificacion == "C1")
    {
        
        for (int i = 0; i < sizeof(C1)/sizeof(C1[0]); i++)
        {
            if (c == C1[i])
            {
                return std::bitset<3>(i).to_string();   
            }
        }
        return "";
    }
    if (codificacion == "C2")
    {
        
        for (int i = 0; i < sizeof(C2)/sizeof(C2[0]); i++)
        {
            if (c == C2[i])
            {
                return std::bitset<5>(i).to_string();   
            }
        }
        return ""; 
    }
    if (codificacion == "C3")
    {
        
        for (int i = 0; i < sizeof(C3)/sizeof(C3[0]); i++)
        {
            if (c == C3[i])
            {
                return std::bitset<6>(i).to_string();   
            }
        }
        return "";
    }
    if (codificacion == "C4")
    {
         return std::bitset<7>(int(c)-32).to_string();
    }
}

std::string traduccion(std::string actual, std::string anterior )
{
    if (anterior == "C1")
    {
        if (actual == "C2")
        {
            return std::bitset<3>(5).to_string();
        }
        if (actual == "C3")
        {
            return std::bitset<3>(6).to_string();
        }
        if (actual == "C4")
        {
            return std::bitset<3>(7).to_string();
        }
        
    }
    else if (anterior == "C2")
    {
        if (actual == "C3")
        {
            return std::bitset<5>(29).to_string();
        }
        if (actual == "C4")
        {
            return std::bitset<5>(30).to_string();
        }
        if (actual == "C1")
        {
            return std::bitset<5>(31).to_string();
        }
    }
    else if (anterior == "C3")
    {
        if (actual == "C4")
        {
            return std::bitset<6>(61).to_string();
        }
        if (actual == "C1")
        {
            return std::bitset<6>(62).to_string();
        }
        if (actual == "C2")
        {
            return std::bitset<6>(63).to_string();
        }
        
    }
    else if (anterior == "C4")
    {
        if (actual == "C1")
        {
            return std::bitset<7>(125).to_string();
        }
        if (actual == "C2")
        {
            return std::bitset<7>(126).to_string();
        }
        if (actual == "C3")
        {
            return std::bitset<7>(127).to_string();
        }
    }
}

int minelement (int v [])
{
    return *(std::min_element(v, v + 4));
}
#endif