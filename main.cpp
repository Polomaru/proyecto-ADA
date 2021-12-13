#include "util.h"

int main()
{
    std::string cadena;
    getline(std::cin,cadena);
    std::string output = "";

    std::string temp;
    std::string temp_anterior = "C0";
    
    std::string sep = " ";

    for (int i = 0; i < cadena.length() - 1; i+=2)
    {
    //    std::cout << cadena.size()<<std::endl; 
       temp = interseccion_minima(cadena[i], cadena[i+1]);
       if (temp_anterior != temp)
       {
           if (temp_anterior == "C0")
           {
               output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + sep;
           }
           else
           {
               if (temp_anterior == "C1")
               {
                   if (temp == "C2")
                   {
                       output += std::bitset<3>(5).to_string() + sep;
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<3>(6).to_string() + sep;
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<3>(7).to_string() + sep;
                   }
                   
               }
               else if (temp_anterior == "C2")
               {
                   if (temp == "C3")
                   {
                       output += std::bitset<5>(29).to_string() + sep;
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<5>(30).to_string() + sep;
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<5>(31).to_string() + sep;
                   }
               }
               else if (temp_anterior == "C3")
               {
                   if (temp == "C4")
                   {
                       output += std::bitset<6>(61).to_string() + sep;
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<6>(62).to_string() + sep;
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<6>(63).to_string() + sep;
                   }
                   
               }
               else if (temp_anterior == "C4")
               {
                   if (temp == "C1")
                   {
                       output += std::bitset<7>(125).to_string() + sep;
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<7>(126).to_string() + sep;
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<7>(127).to_string() + sep;
                   }
               }
           }
       }
       output += codificar(cadena[i], temp) + sep;
       output += codificar(cadena[i+1], temp) + sep;
       temp_anterior = temp;
    }

    if (cadena.length() % 2 != 0)
    {
        if (cadena.length() == 1)
        {
            temp = interseccion_minima(cadena.back(), cadena.back());
            output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + sep; 
            output += codificar(cadena.back(), temp);
        }
        else
        {
            temp = interseccion_minima(cadena[cadena.length()-2], cadena.back());
            if (temp_anterior != temp)
       {
           if (temp_anterior == "C0")
           {
               output += std::bitset<2>(int(temp[1] - '0') - 1).to_string() + sep;
           }
           else
           {
               if (temp_anterior == "C1")
               {
                   if (temp == "C2")
                   {
                       output += std::bitset<3>(5).to_string() + sep;
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<3>(6).to_string() + sep;
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<3>(7).to_string() + sep;
                   }
                   
               }
               else if (temp_anterior == "C2")
               {
                   if (temp == "C3")
                   {
                       output += std::bitset<5>(29).to_string() + sep;
                   }
                   if (temp == "C4")
                   {
                       output += std::bitset<5>(30).to_string() + sep;
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<5>(31).to_string() + sep;
                   }
               }
               else if (temp_anterior == "C3")
               {
                   if (temp == "C4")
                   {
                       output += std::bitset<6>(61).to_string() + sep;
                   }
                   if (temp == "C1")
                   {
                       output += std::bitset<6>(62).to_string() + sep;
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<6>(63).to_string() + sep;
                   }
                   
               }
               else if (temp_anterior == "C4")
               {
                   if (temp == "C1")
                   {
                       output += std::bitset<7>(125).to_string() + sep;
                   }
                   if (temp == "C2")
                   {
                       output += std::bitset<7>(126).to_string() + sep;
                   }
                   if (temp == "C3")
                   {
                       output += std::bitset<7>(127).to_string() + sep;
                   }
               }
           }
       }
            output += codificar(cadena.back(), temp) + sep;
        }
    }
        

    std::cout << output;
}

