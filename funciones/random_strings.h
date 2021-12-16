#ifndef _FUNCTIONS_RANDOM_
#define _FUNCTIONS_RANDOM_

#include "util.h"

void random_string(int n = 100) {
    
    srand(time(0));
    std::ofstream outfile ("./test/in/size100");
 
    for(int i = 0; i < n; i++) {
        std::string c = cod[rand()%4];

        switch (c.at(1))
        {
        case '1':
            //std::cout << c << std::endl;
            //std::cout << C1[rand()%5] << std::endl;
            outfile << C1[rand()%5];
            break;
        case '2':
            //std::cout << c << std::endl;
            //std::cout << C2[rand()%29] << std::endl;
            outfile << C2[rand()%29];
            break;
        case '3':
            // std::cout << c << std::endl;
            // std::cout << C3[rand()%61] << std::endl;
            outfile << C3[rand()%61];
            break;
        case '4':
            // std::cout << c << std::endl;
            // std::cout << char(rand()%95+32) << std::endl;
            outfile << char(rand()%95+32);
            break;
        default:
            break;
        }
    }
    outfile.close();

}

#endif