//
//  City.hpp
//  binary_files
//
//  Created by Emil Iliev on 10/22/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef City_hpp
#define City_hpp

#include <stdio.h>
#include <fstream>
#include <string.h>

class City{
    
        char* cityName;
        int population;
        void copyFrom(const City& other);
    
    public:
        City();
        City(std::ifstream& input);
        City(const City& other);
        ~City();
        City& operator=(const City& other);

        void writeToFile(std::ofstream& output);
    
        int getPopulation() const;
        char* getName() const;
        void setPopulation(int newPopulation);
        void setName(char* newName);
    
        void represent();
    
};

#endif /* City_hpp */
