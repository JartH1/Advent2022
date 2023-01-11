#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

int main() {

    int array_len=0;
    int line_len=0;
    char string1;
    char string2;
    char string3;
    std::string line;
    std::ifstream in ("inputD3a.txt");
    const string ALPHABET = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index;
    int index1;
    int total=0;
    array<int, 53> map1;
    array<int, 53> map2;
    array<int, 53> map3;
    array<int, 53> overlap;
    int common_chars = 0;
    int num_of_lines;

    if (in.is_open()) {
        /*Get the amount of lines in the array and get the amount of empty rows*/
        while(in.peek()!=EOF) {
            getline(in, line);
            array_len++;
            std::fill(map1.begin(),  map1.end(), 0);
            std::fill(map2.begin(),  map2.end(), 0);
            std::fill(map3.begin(),  map3.end(), 0);
            std::fill(overlap.begin(),  overlap.end(), 0);
            for (char c1 : line){
                index = ALPHABET.find(c1);
                map1[index]++;
                }
            std::printf("map1 value is %i", map1);
            getline(in, line);
            array_len++;
            for (char c2 : line){
                index = ALPHABET.find(c2);
                map2[index]++;
                }
            getline(in, line);
            array_len++;
            std::printf("array position is %i\n", array_len);
            for (char c3 : line){
                index = ALPHABET.find(c3);
                map3[index]++;
                }
            for (int i=0;i<53;i++){
                if (map1[i] > 0)
                {
                    map1[i] = 1;
                }
                if (map2[i] > 0)
                {
                    map2[i] = 1;
                }
                if (map3[i] > 0)
                {
                    map3[i] = 1;
                }
                overlap[i] = map1[i] + map2[i] + map3[i];
                if (overlap[i] == 3)
                {
                    std::printf("blabla %i", i);
                    total += i;
                }
                
            }
            /*index1 = overlap.find(3); */

        }    
        std::printf("The number of lines in the array is %d\n", array_len);
        std::printf("The total score is  %d\n", total);

    }
    else {
        std::printf("file is not open");
    }
        /*clear in*/
    in.clear();
    in.seekg(0);


    


} 