#ifndef _FUNCTIONS_HEU_
#define _FUNCTIONS_HEU_
#include "util.h"

std::string min_cod_heu(std::string cadena)
{
    std::string output = "";

    std::string temp;
    std::string temp_anterior = "C0";

    for (int i = 0; i < cadena.length() - 1; i+=2)
    { 
       temp = interseccion_minima(cadena[i], cadena[i+1]);
       if (temp_anterior != temp)
       {
           if (temp_anterior == "C0")
           {
               output += std::bitset<2>(int(temp[1] - '0') - 1).to_string();
           }
           else
           {
               output += traduccion(temp,temp_anterior);
           }
       }
       output += codificar(cadena[i], temp);
       output += codificar(cadena[i+1], temp);
       temp_anterior = temp;
    }

    if (cadena.length() % 2 != 0)
    {
        if (cadena.length() == 1)
        {
            temp = interseccion_minima(cadena.back(), cadena.back());
            output += std::bitset<2>(int(temp[1] - '0') - 1).to_string(); 
            output += codificar(cadena.back(), temp);
        }
        else
        {
            temp = interseccion_minima(cadena[cadena.length()-2], cadena.back());
            if (temp_anterior != temp)
            {
                if (temp_anterior == "C0")
                {
                    output += std::bitset<2>(int(temp[1] - '0') - 1).to_string();
                }
                else
                {
                    output += traduccion(temp,temp_anterior);
                }
            }
            output += codificar(cadena.back(), temp);
        }
    }
    return output;
}
#endif