#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

int main() {

    int array_len=0;
    int line_len=0;
    std::string string1;
    std::string string2;
    std::string line;
    std::string line2split;
    std::ifstream in ("inputD4a.txt");
    int total = 0;
    int total1 = 0;
    std::string komma = ",";
    std::string lijntje = "-"; 
    int pos;
    int min1;
    int min2;
    int max1;
    int max2;


    if (in.is_open()) {
        /*Get the amount of lines in the array and get the amount of empty rows*/
        while(in.peek()!=EOF) {
            getline(in, line);
            line2split = line;
            std::cout << line2split << std::endl;
            array_len++;
            pos = line.find(komma);
            string1 = line.substr(0, pos);
            string2 = line.substr(pos+1, line.length());

            pos = string1.find(lijntje);
            min1 = std::stoi(string1.substr(0, pos));
            max1 = std::stoi(string1.substr(pos+1, string1.length()));

            pos = string2.find(lijntje);
            min2 = std::stoi(string2.substr(0, pos));
            max2 = std::stoi(string2.substr(pos+1, string2.length()));

            std::cout << min1 << std::endl;
            std::cout << min2 << std::endl;
            std::cout << max1 << std::endl;
            std::cout << max2 << std::endl;

            if (((min1 <= min2) && (max1 >= max2)) || ((min2 <= min1) && (max2 >= max1))) {
                total++;
            }

            if (((min1 <= min2) && (max1 >= min2)) || ((min2 <= min1) && (max2 >= min1))) {
                total1++;
            }


            
        }
            /*index1 = overlap.find(3); */

        
        std::printf("The number of lines in the array is %d\n", array_len);
        std::printf("The total score is  %d\n", total);
        std::printf("The total score is  %d\n", total1);

    }
    else {
        std::printf("file is not open");
    }
        /*clear in*/
    in.clear();
    in.seekg(0);


    


} 