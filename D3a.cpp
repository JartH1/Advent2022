#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int array_len=0;
    int line_len=0;
    char string1;
    char string2;
    std::string line;
    std::ifstream in ("inputD3a.txt");
    const string ALPHABET = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index;
    int total=0;


    if (in.is_open()) {
        /*Get the amount of lines in the array and get the amount of empty rows*/
        while(in.peek()!=EOF) {
            getline(in, line);
            std::printf("length of the line is %i\n", line.length());
            for (int q = 0; q<(line.length()/2); q++)
            {
                for (int j = (line.length()/2); j<line.length(); j++)
                {
                    if (line[q] == line[j]) 
                    {
                        index = ALPHABET.find(line[j]);
                        
                         
                    }
                }
                
            }
            std::printf("the charachter that both halves of the string have is %c \n", ALPHABET[index]);
            std::printf("the index of the char is %i\n", index);
            total += index; 
            array_len++;
        }   

        std::printf("The number of lines in the array is %d\n", array_len);
        std::printf("The number of points is %d\n", total);

        /*clear in*/
        in.clear();
        in.seekg(0);

    }
    else {
        std::printf("file is not open");
    }

} 