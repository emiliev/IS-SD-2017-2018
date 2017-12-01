//
//  main.cpp
//  Dynamic Array
//
//  Created by Emil Iliev on 10/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <fstream>

template <typename T>
class DynamicArray{
    private:
        T* container = nullptr;
    DynamicArray():container(nullptr){}

};

using namespace std;
int main(int argc, const char * argv[]) {
    
    //TODO:- new file with random population!!!
    ifstream input("us_cities.txt");
    ofstream coutput("us_cities.txt",  ios::out );
    if(input && coutput){
        while (!input.eof()) {
            string text;
            input>>text;
            cout<<text.length()<< " "<<text<< endl;
            int population = rand() % 100000;

            int length = (int) (text.length()) + 1;
            coutput.write((char*) &length, sizeof(length));
            coutput.write((char*) &text, length);
            coutput.write((char*) &population, sizeof(population));
        }
    }
    
    

//    cout<<endl;
//    for(int index = 0; index < argc; ++index){
//        cout<<argv[index]<<endl;
//    }

//    char* f1 = new char[2];
//    strcpy(f1, "c");
//    char* f2 = new char[2];
//    strcpy(f1, "b");
//
//    cout<<sum(f1, f2);
//

    
    
    
    clock_t start;
    double duration;
    start = std::clock();
    int n = 100000;
    
//    for(int index = 0; index < n; ++index){
//        for(int index1 = 0; index1 < n; ++index1){
//
//        }
//    }
//
//    for(int index = 0; index < n; ++index){
//        for(int c = 1; c < n; c *=2){
//            cout<<c<<endl;
//        }
//
//    }

//    int i = 0;
//    for(int index = 1; index < n; index *= 2){
//        for(int index1 = 1; index1 < n; index1 *=2){
//            cout<<index1<<endl;
//            i++;
//        }
//    }

    
    
    
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';

    
    
    return 0;
}
