#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>

using namespace std;
const string ALPHABET = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";



int main() {

    std::string line;
    std::ifstream commands ("inputD6a.txt");


    int n;
    int counter = 0;
    int numberZ = 14;


    if (commands.is_open()) 
    {
        while(commands.peek()!=EOF) 
        {
            getline(commands, line);
            //std::printf("length of the line is %c", line.size());
            for (int i = 0; i < line.size()-numberZ; i++) 
            {
                cout << i << " ";
                std::string line2asses = line.substr(i, numberZ);
                std::string tempALPHABET = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                
                int count = 0;
                //cout << count << " ";
                for (char c1 : line2asses)
                {
                    int index = tempALPHABET.find(c1);
                    //cout << index << "   ";
                    if ((index != -1) && (tempALPHABET.length() == (ALPHABET.length() - (numberZ-1))))
                    {
                        std::printf("The end point of the unique string is %i    ", i+numberZ+1);
                        int rememberThisNumber = 1;
                    }
                    else if (index != -1) 
                    {
                        tempALPHABET.erase(index, 1);
                        //count = count+1;
                        
                    }
                    else 
                    {
                    }
                    //cout << tempALPHABET.length() << "    \n";
                }
            }
        }
    }
    else 
    {
        std::printf("file is not open");
    }
}

