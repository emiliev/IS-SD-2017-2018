//
//  main.cpp
//  binary_files
//
//  Created by Emil Iliev on 10/20/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "City.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    ifstream input("newFile.bat", ios::binary | ios::in);
    ofstream output("newFile.bat", ios::binary | ios::out);
    if (input) {
        while (!input.eof()){
            City randomCity(input);
            randomCity.represent();
            randomCity.writeToFile(output);
        }

    }
    else {
        cout<<"Error\n";
    }
    input.close();
    
    return 0;
}
