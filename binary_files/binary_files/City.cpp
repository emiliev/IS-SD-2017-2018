//
//  City.cpp
//  binary_files
//
//  Created by Emil Iliev on 10/22/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "City.hpp"
#include <iostream>

City::City(): cityName(nullptr), population(0){}

//read data from file and initialize object
City::City(std::ifstream& input){
    //nameLength, name, population
    int nameLength;
    input.read((char*)&nameLength, sizeof(nameLength));
    
    //allocate memory..
    this->cityName = new char[nameLength];
    input.read(cityName, nameLength);
    input.read((char*) &population, sizeof(population));
}

City::City(const City &other){
    copyFrom(other);
}

City& City::operator=(const City &other){
    if(this != &other){
        delete [] cityName;
        cityName = nullptr;
        copyFrom(other);
    }
    
    return *this;
}

City::~City(){
    delete [] cityName;
    cityName = nullptr;
}

void City::writeToFile(std::ofstream &output){
    int nameLength = strlen(cityName) + 1;
    output.write((char*) &nameLength, sizeof(nameLength));
    output.write(cityName, nameLength);
    output.write((char*)&population, sizeof(population));
}

void City::copyFrom(const City &other){
    
    population = other.population;
    size_t cityNameLength = strlen(other.cityName) + 1;
    this->cityName = new char[cityNameLength];
    strcpy(cityName, other.cityName);
}

void City::setName(char *newName){
    delete [] cityName;
    int length = strlen(newName) + 1;
    cityName = new char[length];
    strcpy(cityName, newName);
}

void City::setPopulation(int newPopulation){
    newPopulation >= 0 ? population = newPopulation : population = 0;
}

int City::getPopulation() const {
    return population;
}

char* City::getName() const {
    return this->cityName;
}

void City::represent(){
    std::cout<<"Name: "<<this->cityName<<" \nPopulation: "<<population<<std::endl;
}





