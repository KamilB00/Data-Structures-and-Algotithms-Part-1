//
// Created by Kamil Bonkowski on 30/03/2021.
//

#ifndef DATASTRUCTURES_FILE_H
#define DATASTRUCTURES_FILE_H
#include <iostream>
#include <regex>
#include<string>

using namespace std;

class File {
public:

    File(string file_name) {
        int amount = 0;
        int lower = 0;
        int upper = 0;

           fstream file;
           file.open(file_name, ios::out);

           cout << "How many numbers should be created ? :";
           cin >> amount;

           do {
               cout << "Lower Bounds: ";
               cin >> lower;
               cout << "Upper Bounds: ";
               cin >> upper;

               if (lower >= upper) {
                   cout << "Incorrect range, please try again !" << endl;
               }
           } while (lower >= upper);


           if (file.good()) {
               cout << "File created successfully" << endl;
               file << amount << endl;
               std::random_device rd;
               std::mt19937 gen(rd());
               std::uniform_real_distribution<> dis(lower, upper);

               cout << "Please wait, values are being loaded to the file..." << endl;
               for (int i = 0; i < amount; i++) {
                   file << (int) dis(gen) << endl;
               }
               file.close();
               cout << "Filling accomplished successfully !" << endl;
           } else {
               cout << "File not found" << endl;
           }
       }



};


#endif //DATASTRUCTURES_FILE_H
