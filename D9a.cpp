#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>
#include <regex>
#include <list>
using namespace std;

std::list<int> xCorHeadList;
std::list<int> yCorHeadList;
int xCorHead = 0;
int yCorHead = 0;
std::list<int> xCorTailList;
std::list<int> yCorTailList;
std::list<int> xTailListToAppend;
std::list<int> yTailListToAppend;

std::list<int>  TailPositions(int HeadStartx, int HeadStarty, int HeadEndx, int HeadEndy, char Direction, int TailStartx, int TailStarty){
    

    
    std::list<int> xTailList;
    std::list<int> yTailList;
    std::list<int> TotalTailListXY;
    int xTailPos = TailStartx;
    int yTailPos = TailStarty;
    int xHeadPos = HeadStartx;
    int yHeadPos = HeadStarty;
    int steps;



    if ((Direction == 'U') || (Direction == 'D')){
        steps = HeadEndy - HeadStarty;
        
        if (HeadStartx == TailStartx) {
            for (int j = 0; j < abs(steps); j++){
                
                if (Direction == 'U') {
                    yHeadPos = yHeadPos + 1;
                    if (abs(yHeadPos - yTailPos) > 1){
                        yTailPos = yHeadPos - 1;
                    }
                    else {
                        yTailPos = yTailPos;
                    }
                }

                else if (Direction == 'D'){
                    yHeadPos = yHeadPos - 1;
                    if (abs(yHeadPos - yTailPos) > 1){
                        yTailPos = yHeadPos + 1;
                    }
                    else {
                        yTailPos = yTailPos;
                    }

                }
                yTailList.push_back(yTailPos);
                xTailList.push_back(TailStartx);
                //std::printf("{%c, %i}, {%i, %i}, {%i, %i} \n", Direction, steps, xHeadPos, yHeadPos, xTailPos, yTailPos);


            }

        }
        else {
            for (int j = 0; j < abs(steps); j++){
                if (Direction == 'U') {
                    yHeadPos = yHeadPos + 1;
                    if ((abs(yHeadPos - yTailPos) > 1) || (abs(xHeadPos - xTailPos) > 1)){
                        yTailPos = yHeadPos - 1;
                        xTailPos = xHeadPos;
                    }
                    else {

                    }
                }
                else if (Direction == 'D') {
                    yHeadPos = yHeadPos - 1;
                        if ((abs(yHeadPos - yTailPos) > 1) || (abs(xHeadPos - xTailPos) > 1)){
                        yTailPos = yHeadPos + 1;
                        xTailPos = xHeadPos;
                    }
                    else {

                    }

                }
                yTailList.push_back(yTailPos);
                xTailList.push_back(xTailPos);
                std::printf("{%c, %i}, {%i, %i}, {%i, %i} \n", Direction, steps, xHeadPos, yHeadPos, xTailPos, yTailPos);

            }

    
        }
    }


    else if ((Direction == 'R') || (Direction == 'L')){
        steps = HeadEndx - HeadStartx;
        
        if (HeadStarty == TailStarty) {
            for (int j = 0; j < steps; j++){
                
                if (Direction == 'R') {
                    xHeadPos = xHeadPos + 1;
                    if (abs(xHeadPos - xTailPos) > 1){
                        xTailPos = xHeadPos - 1;
                    }
                    else {
                        xTailPos = xTailPos;
                    }
                }

                else if (Direction == 'L'){
                    xHeadPos = xHeadPos - 1;
                    if (abs(xHeadPos - xTailPos) > 1){
                        xTailPos = xHeadPos + 1;
                    }
                    else {
                        xTailPos = xTailPos;
                    }

                }
                xTailList.push_back(xTailPos);
                yTailList.push_back(TailStarty);
                //std::printf("{%c, %i}, {%i, %i}, {%i, %i} \n", Direction, steps, xHeadPos, yHeadPos, xTailPos, yTailPos);


            }

        }
        else {
            for (int j = 0; j < steps; j++){
                if (Direction == 'R') {
                    xHeadPos = xHeadPos + 1;
                    if ((abs(yHeadPos - yTailPos) > 1) || (abs(xHeadPos - xTailPos) > 1)){
                        xTailPos = xHeadPos - 1;
                        yTailPos = yHeadPos;
                    }
                    else {

                    }
                }
                else if (Direction == 'L') {
                    xHeadPos = xHeadPos - 1;
                        if ((abs(yHeadPos - yTailPos) > 1) || (abs(xHeadPos - xTailPos) > 1)){
                        xTailPos = xHeadPos + 1;
                        yTailPos = yHeadPos;
                    }
                    else {

                    }

                }
                yTailList.push_back(yTailPos);
                xTailList.push_back(xTailPos);
                //std::printf("{%c, %i}, {%i, %i}, {%i, %i} \n", Direction, steps, xHeadPos, yHeadPos, xTailPos, yTailPos);

            }
        }

    }
    

    
    TotalTailListXY = xTailList;
    TotalTailListXY.insert(TotalTailListXY.end(), yTailList.begin(), yTailList.end());


    return TotalTailListXY;
}

bool IsNotUnique(vector<int> InputVector, vector<vector<int> > UniqueVectorArray){
    bool ThisVectorIsNotUnique = false;

        for (int j = 0; j < UniqueVectorArray.size(); j++){
            
            if ((InputVector[0] == UniqueVectorArray[j][0]) & (InputVector[1] == UniqueVectorArray[j][1]))
            {
                ThisVectorIsNotUnique = true;
            }
        }

    return ThisVectorIsNotUnique;
}

int main() {


    xCorTailList.push_back(0);
    yCorTailList.push_back(0);

    int count = 0;
    std::string line;
    std::ifstream commands ("inputD9.txt");
    if(commands.is_open()) 
	{
        
		while(commands.peek()!=EOF)
		{
			getline(commands, line);
            char direction = line[0];
            int amount = std::stoi(line.substr(2, line.length()));
            int yCorHeadPrev = yCorHead;
            int xCorHeadPrev = xCorHead;

            if (direction == 'U')
            {
                yCorHead = yCorHead + amount;
                yCorHeadList.push_back(yCorHead);
            }
            else if (direction == 'D')
            {
                 yCorHead = yCorHead - amount;
                 yCorHeadList.push_back(yCorHead);
            }
            else if (direction == 'R')
            {
                xCorHead = xCorHead + amount;
                xCorHeadList.push_back(xCorHead);
            }
            else if (direction == 'L')
            {
                xCorHead = xCorHead - amount;
                xCorHeadList.push_back(xCorHead);
            }
            //std::printf("number is %i", amount);
            //std::printf("coordinates are now%i, %i      \n", xCorHead, yCorHead);

            
            std::list<int> Output = TailPositions(xCorHeadPrev, yCorHeadPrev, xCorHead, yCorHead, direction, xCorTailList.back(), yCorTailList.back());
            int ListSize = Output.size();
            for (int j = 0; j < ListSize; j++){
                int Coordinate = Output.front();
                if (j < (ListSize / 2))
                {
                    xCorTailList.push_back(Coordinate);
                }
                else 
                {
                    yCorTailList.push_back(Coordinate);
                }
                Output.pop_front();

            }

            
            
			count +=1;  //Can do things while reading alread
		}
		/*commands.close();*/
		//std::printf("Number of lines in the file are: %i", count);
        //std::printf("Number of Tail Coordinates is %i", xCorTailList.size());
        //std::printf("Number of Tail Coordinates is %i", yCorTailList.size());

    }

    int TailCount = 0;

    vector<vector<int> > UniqueVector;
    std::printf("Size of yCorTailList is %i \n", yCorTailList.size());

    for (int j = 0; j < yCorTailList.size(); j++){
        int x = xCorTailList.front();
        xCorTailList.pop_front();
        int y = yCorTailList.front();
        yCorTailList.pop_front();
        vector<int> XYVector;
        XYVector.push_back(x);
        XYVector.push_back(y);
        


        bool IsXYVectorNotUnique = IsNotUnique(XYVector, UniqueVector);

        if (!IsXYVectorNotUnique){
            TailCount += 1;
            vector<int> vect;
            vect.push_back(x);
            vect.push_back(y);
            UniqueVector.push_back(vect);
        }
    }
 
std:printf("Number of unique positions of the tail is %i", TailCount);
} 


