#include <iostream>
#include <bitset>
#include <unordered_map>
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
        const char C2[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '0','1','2','3','4','5','6','7','8', '9', char(32), '!', '"', '#', '$', '%','&' ,'\'', '('};
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
        const char C3[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
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
    getline(std::cin,cadena);
    std::string output = "";

    std::string temp;
    std::string temp_anterior = "C0";
    
    for (int i = 0; i < cadena.length() - 1; i+=2)
    {
    //    std::cout << cadena.size()<<std::endl; 
       temp = interseccion_minima(cadena[i], cadena[i+1]);
       if (temp_anterior != temp)
       {
           if (temp_anterior == "C0")
           {
               output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + " ";
           }
           else
           {
               if (temp_anterior == "C1")
               {
                   if (temp == "C2")
                   {
                       output += std::bitset<3>(5).to_string() + " ";
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<3>(6).to_string() + " ";
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<3>(7).to_string() + " ";
                   }
                   
               }
               else if (temp_anterior == "C2")
               {
                   if (temp == "C3")
                   {
                       output += std::bitset<5>(29).to_string() + " ";
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<5>(30).to_string() + " ";
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<5>(31).to_string() + " ";
                   }
               }
               else if (temp_anterior == "C3")
               {
                   if (temp == "C4")
                   {
                       output += std::bitset<6>(61).to_string() + " ";
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<6>(62).to_string() + " ";
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<6>(63).to_string() + " ";
                   }
                   
               }
               else if (temp_anterior == "C4")
               {
                   if (temp == "C1")
                   {
                       output += std::bitset<7>(125).to_string() + " ";
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<7>(126).to_string() + " ";
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<7>(127).to_string() + " ";
                   }
               }
           }
       }
       output += codificar(cadena[i], temp) + " ";
       output += codificar(cadena[i+1], temp) + " ";
       temp_anterior = temp;
    }

    if (cadena.length() % 2 != 0)
    {
        if (cadena.length() == 1)
        {
            temp = interseccion_minima(cadena.back(), cadena.back());
            output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + " "; 
            output += codificar(cadena.back(), temp);
        }
        else
        {
            temp = interseccion_minima(cadena[cadena.length()-2], cadena.back());
            if (temp_anterior != temp)
       {
           if (temp_anterior == "C0")
           {
               output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + " ";
           }
           else
           {
               if (temp_anterior == "C1")
               {
                   if (temp == "C2")
                   {
                       output += std::bitset<3>(5).to_string() + " ";
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<3>(6).to_string() + " ";
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<3>(7).to_string() + " ";
                   }
                   
               }
               else if (temp_anterior == "C2")
               {
                   if (temp == "C3")
                   {
                       output += std::bitset<5>(29).to_string() + " ";
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<5>(30).to_string() + " ";
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<5>(31).to_string() + " ";
                   }
               }
               else if (temp_anterior == "C3")
               {
                   if (temp == "C4")
                   {
                       output += std::bitset<6>(61).to_string() + " ";
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<6>(62).to_string() + " ";
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<6>(63).to_string() + " ";
                   }
                   
               }
               else if (temp_anterior == "C4")
               {
                   if (temp == "C1")
                   {
                       output += std::bitset<7>(125).to_string() + " ";
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<7>(126).to_string() + " ";
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<7>(127).to_string() + " ";
                   }
               }
           }
       }
            output += codificar(cadena.back(), temp) + " ";
        }
    }
        

    std::cout << output;
}

