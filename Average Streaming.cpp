// 
//
//  Lab 10
//
//  Created by Mohammed Shehab on 4/1/2020.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include "Average.h"

using namespace std;

const string FILE_NAME = "Data.txt";
void generate_random(long size);
void start();

int main()
{
    int select = -1;

    do
    {
        cout << "1- Generate random data\n";
        cout << "2- Start reading stream data\n";
        cout << "Please enter your choose (to exit enter 0): ";
        cin >> select;
        switch (select)
        {
        case 1: {
            int size = 0;
            cout << " Enter number of elements do you want to generate: ";
            cin >> size;
            generate_random(size);
        }; break;
        case 2: {
            start(); }; break;
        default:
            break;
        }
    } 
    while (select > 0);
    
    return 0;
}

void generate_random(long size)
{
    ofstream file(FILE_NAME, ios::out);
    long i;
    for (i = 0; i < size; ++i)
    {
        cout << ".";
        if (i % 15 == 0)
        {
            cout << "\r";
        }
        file << rand() % 1000 << "\n";
    }
    file.close();
    cout << endl;
    cout << i <<" element(s) are generated.\n";
}

void start() {
    Average worker = Average();
    ifstream file(FILE_NAME, ios::in);
    string line; // Temp string buffer to read data from file.
    if (!file)
    {
        cout << "File " << FILE_NAME << " does not exist.\n";
        return;
    }

    while (getline(file, line))
    {
        // Start streaming data from file.
        int v = stoi(line);
        worker.update(v);
    }
    worker.calculate_real();
    double error_rate = abs(worker.get_avg_real() - worker.get_avg_stream());
    cout << "Real average = " << worker.get_avg_real() << endl;
    cout << "Stream average = " << worker.get_avg_stream() << endl;
    cout << "-------------------------\n";
    cout << "Error rate = " << error_rate << endl;
    cout << "-------------------------\n";
}