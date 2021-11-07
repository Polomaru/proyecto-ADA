#include <iostream>
#include <bitset>

bool es_vocal_minuscula(char c){
    const char minusculas[] = {'a', 'e', 'i', 'o', 'u'};
    for (auto i : minusculas)
    {
        if (c==i) return true;
    } 
    return false;
}

bool es_vocal_mayuscula(char c){
    const char mayusculas[] = {'A', 'E', 'I', 'O', 'U'};
    for (auto i: mayusculas)
    {
        if (c==i) return true;
    }
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
        const char C1[] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < sizeof(C1)/sizeof(C1[0]); i++)
        {
            if (c == C1[i])
            {
                return std::bitset<3>(i).to_string();   
            }
        }
    }
    if (codificacion == "C2")
    {
        const char C2[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '0','1','2','3','4','5','6','7','8', '9', ' ', '!', '"', '#', '$', '%','&' ,'\'', '('};
        for (int i = 0; i < sizeof(C2)/sizeof(C2[0]); i++)
        {
            if (c == C2[i])
            {
                return std::bitset<5>(i).to_string();   
            }
        }
    }
    if (codificacion == "C3")
    {
        const char C3[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0','1','2','3','4','5','6','7','8', '9',
        '[', '\\', ']', '^', '_',
        '{', '|', '}', '~'};
        for (int i = 0; i < sizeof(C3)/sizeof(C3[0]); i++)
        {
            if (c == C3[i])
            {
                return std::bitset<6>(i).to_string();   
            }
        }
    }
    if (codificacion == "C4")
    {
         return std::bitset<7>(int(c)-32).to_string();
    }
}

int main()
{
    std::string cadena;
    std::cin >> cadena;
    
    std::string output = "";

    std::string temp;
    std::string temp_anterior;
    
    for (int i = 0; i < cadena.size(); i+=2)
    {
       temp = interseccion_minima(cadena[i], cadena[i+1]);
       output += codificar(cadena[i], temp);
    }
}

