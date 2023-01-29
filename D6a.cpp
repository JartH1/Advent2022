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


    if (commands.is_open()) {
        while(commands.peek()!=EOF) {
            getline(commands, line);
            //std::printf("length of the line is %c", line.size());
            for (int i = numberZ - 1; i < line.size(); i++) {
                cout << i << " ";
                }
                for (int j = 0; j < numberZ; j++) {
                    int recursion(n) {
                    if (n == 0) {
                        return 
                    }
                    return(n-1)
                    if line[i] 
                }
                char c1 = line[i];
                int index1 = ALPHABET.find(c1);
                cout << index1 << " ";
                char c2 = line[i-1];
                int index2 = ALPHABET.find(c2);
                char c3 = line[i-2];
                int index3 = ALPHABET.find(c3);
                char c4 = line[i-3];
                int index4 = ALPHABET.find(c4);
                cout << index2 << " ";
                cout << index3 << " ";
                cout << index4 << "     ";
                
                if ((index1 != index2) and (index1 != index3) and (index1 != index4) and (index2 != index4) and (index2 != index3) and (index3 != index4)) {       
                    std::printf("GOTONEEEE with number %c", i);
                    counter++;           
                    }
                else {
                    //std::printf("Not a match");
                }

            }


            cout << counter << " bls ";


                }

                
    }
    else {
        std::printf("file is not open");
    }
}
