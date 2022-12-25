#include <iostream>
#include <fstream>
#include <string>

int main() {

    int array_len=0;
    char RPS_competitor;
    char RPS_own;
    int points=0;
    std::string line;
    std::ifstream in ("inputD2a.txt");


    if (in.is_open()) {
        /*Get the amount of lines in the array and get the amount of empty rows*/
        while(in.peek()!=EOF) {
            getline(in, line);
            array_len++;
        }   

        std::printf("The number of lines in the array is %d\n", array_len);

        /*clear in*/
        in.clear();
        in.seekg(0);

        /*Walk through all rows and determine the scores*/
        while(in.peek()!=EOF) {
            getline(in, line);
            RPS_competitor = line[0];
            RPS_own = line.back();
            /*Competitor has rock*/
            if (RPS_competitor == 'A') {
                /*You have rock*/
                if (RPS_own == 'X')
                {
                    points += 3; /*1 point for choosing rock, 3 points for draw*/
                }
                /*You have paper*/
                else if (RPS_own == 'Y')
                {
                    points += 4; /* 2 points for choosing paper, 6 points for winning*/
                }
                /*You have scisors*/
                else if (RPS_own == 'Z')
                {
                    points += 8; /*3 points for choosing scissors*/
                }
            }
            /*Competitor has Paper*/
            else if (RPS_competitor == 'B') {
                if (RPS_own == 'X')
                {
                    points += 1; /*1 point for choosing rock*/
                }
                else if (RPS_own == 'Y')
                {
                    points += 5; /*2 points for choosing paper, 3 points for draw*/
                }
                else if (RPS_own == 'Z')
                {
                    points += 9; /* 3 points for choosing scissors, 6 points for winning*/
                }
            }
            /*Competitor has Scisors*/
            else if (RPS_competitor == 'C') {
                if (RPS_own == 'X')
                {
                    points +=2; /* 1 point for choosing rock, 6 points for winning*/
                }
                else if (RPS_own == 'Y')
                {
                    points += 6; /* 2 points for choosing rock */
                }
                else if (RPS_own == 'Z')
                {
                    points += 7;/* 3 points for choosing scissors, 3 points for draw */
                }
            }  
        }    
        std::printf("total amount of points is %i", points);    
    }
    else {
        std::printf("file is not open");
    }

} 