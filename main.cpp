#include "funciones/dynamic.h"
#include "funciones/decode.h"
#include "funciones/heuristica.h"
#include "funciones/timer.h"
#include "funciones/random_strings.h"

void aleatorio()
{
    std::cout<<std::endl<<"De cuanto quiere la longitud del string?"<<std::endl;
    int choice;
    do
    {
        std::cout<<"\nSize: ";
        std::cin>>choice;
    } while(choice < 0 and choice > 1000000);
    random_string(choice);
    std::cout<<std::endl<<"Se ha generado un archivo de texto aleatorio"<<std::endl<<std::endl;
}
void codificar()
{
    std::cout<<std::endl<<"Qué archivo quiere codificar?"<<std::endl;
    std::string uwu, scodificar, result;
    std::fstream file;
    do
    {
        std::cout<<"Archivo: ";
        std::cin>>uwu;
        file.open("./test/in/codi/"+uwu);

    }while(!file.is_open());

    std::cout<<std::endl<<"Abierto!"<<std::endl;
    
    std::cout<<std::endl<<"De qué manera quiere codificarlo?"<<std::endl;


    std::cout<<std::endl<<"1. Codificación heuristica"<<std::endl;
    std::cout<<std::endl<<"2. Codificación óptima/dinámica"<<std::endl;
    int choice;
    do
    {
        std::cout<<"\nEliga una Opción: ";
        std::cin>>choice;
    } while(choice < 0 and choice > 3);
    
    std::getline(file, scodificar);

    
    if(choice == 1) result = min_cod_heu(scodificar);
    else result = min_cod_din(scodificar);


    std::cout<<"\nCómo desea guardarlo?: ";
    std::cin>>uwu;
    std::cout<<std::endl<<"Guardado!"<<std::endl<<std::endl;

    std::ofstream outfile ("./test/out/codi/" + uwu, std::ios::out | std::ios::binary);
    
    int size = result.size();
    outfile.write((char*) &size, sizeof(int));

    for(int i = 0; i<result.size(); i += 8)
    {
        auto str_byte = result.substr(i, 8);
        str_byte.resize(8, '0');
        auto byte = std::bitset<8>(str_byte);
        char cbyte = byte.to_ulong();

        outfile.write((char*) &cbyte, sizeof(char));
    }
}
void decodificar()
{
    std::cout<<std::endl<<"Qué archivo quiere decodificar?"<<std::endl;
    std::string uwu, sdecodificar = "", result;
    std::ifstream file;
    do
    {
        std::cout<<"Archivo: ";
        std::cin>>uwu;
        file.open("./test/in/decode/"+uwu, std::ios::binary);

    }while(!file.is_open());

    int size;
    file.read((char*) &size, sizeof(int));

    for(int i=0; i < roundUp(size,8); i+=8)
    {
        char temp;
        file.read((char*) &temp, sizeof(char));
        sdecodificar += std::bitset<8>(temp).to_string();
    }
    sdecodificar.resize(size);
    
    result = decode(sdecodificar);

    std::cout<<"\nCómo desea guardarlo?: ";
    std::cin>>uwu;
    std::cout<<std::endl<<"Guardado!"<<std::endl<<std::endl;
    std::ofstream outfile ("./test/out/decode/" + uwu, std::ios::out);
    outfile <<result;
}
int main()
{   
    int choice;
    while(true)
    {
        std::cout<<std::endl<<"MENU"<<std::endl;
        std::cout<<"1. Generar Aleatorio"<<std::endl;
        std::cout<<"2. Codificar"<<std::endl;
        std::cout<<"3. Decodificar"<<std::endl;

        do
        {
            std::cout<<"\nEliga una Opción: ";
            std::cin>>choice;
        }while(choice<0 and choice>4);
        

        switch (choice)
        {
        case 1:
            aleatorio();
            break;
        case 2:
            codificar();
            break;
        case 3:
            decodificar();
            break;
        }
    }
    random_string();
}