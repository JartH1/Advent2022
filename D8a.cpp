#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>
using namespace std;

int main() {

    int count = 0;
    std::string line;
    std::ifstream commands ("inputD8a.txt");
    if(commands.is_open()) 
	{
        
		while(commands.peek()!=EOF)
		{
			getline(commands, line);
			count +=1;  //Can do things while reading alread
		}
		/*commands.close();*/
		std::printf("Number of lines in the file are: %i", count);
    }

    std::printf("size of line is %i", line.size());
    int Linesize = line.size();
    int ForrestMatrix[99][99];
    //int ForrestMatrix[10][10];

    commands.clear();
    commands.seekg (0, ios::beg);

        if(commands.is_open()) 
	    {
            int count1 = 0;
            while(commands.peek()!=EOF)
            {
                getline(commands, line);
                for (int i = 0; i < line.size(); i++){
                    char b = line[i];
                    int a = b - 48;
                    ForrestMatrix[count1][i] = a;
                }
                count1 +=1;  //Can do things while reading alread
            }
    }


    //AssessForrest(ForrestMatrix);
    //std::printf("We are done");


//int AssessForrest(int Matrix){
    int VisibleTrees = 0;
    int rows = sizeof(ForrestMatrix)/sizeof(ForrestMatrix[0]);
    int cols = sizeof(ForrestMatrix[0])/sizeof(ForrestMatrix[0][0]);

    int MaxView = 0;



    for (int j = 0; j < rows; j++){
        for (int i = 0; i < cols; i++){

            //int leftRow[i];
            //int rightRow[rows - i - 1];
            //int topColumn[j];
            //int bottomColum[cols- j - 1];
            bool TreeVisibleLeft = true;
            bool TreeVisibleRight = true;
            bool TreeVisibleTop = true;
            bool TreeVisibleBottom = true;

            int ViewRight = 0;
            int ViewLeft = 0; 
            int ViewTop = 0; 
            int ViewBottom = 0;

                if ((i == 0) || (j == 0) || (i == rows) || (j ==cols))
                {
                    if (ForrestMatrix[i][j] != 10){
                        VisibleTrees += 1;
                    }
                } 
                else {
                    for (int q = 0; q <= i - 1; q++){
                        //leftRow[q] = ForrestMatrix[q][j];
                        if ((ForrestMatrix[q][j] >= ForrestMatrix[i][j])){
                            TreeVisibleLeft = false;}
                        }
                    for (int k = i + 1; k < rows; k++){
                        //rightRow[k-i] = ForrestMatrix[k][j];
                        if ((ForrestMatrix[k][j] >= ForrestMatrix[i][j])){
                            TreeVisibleRight = false;}
                        }
                    
                    for (int z = 0; z <= j - 1; z++){
                        //topColumn[z] = ForrestMatrix[i][z];
                        if ((ForrestMatrix[i][z] >= ForrestMatrix[i][j])){
                            TreeVisibleTop = false;}
                        }
                    
                    for (int h = j + 1; h < cols; h++){
                        //bottomColum[h-j] = ForrestMatrix[i][h];
                        if ((ForrestMatrix[i][h] >= ForrestMatrix[i][j])){
                            TreeVisibleBottom = false;}
                        }
                    if (TreeVisibleBottom || TreeVisibleTop || TreeVisibleLeft || TreeVisibleRight){
                        VisibleTrees += 1;
                    
                    } 
                    
                }


                if ((i == 0) || (j == 0) || (i == rows) || (j ==cols))
                {
                    ViewRight = 0;
                    ViewLeft = 0;
                    ViewTop = 0;
                    ViewBottom = 0;
                } 
                else {
                    for (int q = i-1; q >= 0; q--){
                        //leftRow[q] = ForrestMatrix[q][j];
                        if (ForrestMatrix[q][j] < ForrestMatrix[i][j])
                        {
                            ViewLeft += 1;}
                        
                        else
                        {
                            ViewLeft += 1;
                            break;
                            //goto breakLeft;
                        }}
                    //breakLeft;
                    for (int k = i + 1; k < rows; k++){
                        //rightRow[k-i] = ForrestMatrix[k][j];
                        if (ForrestMatrix[k][j] < ForrestMatrix[i][j])
                        {
                            ViewRight += 1;
                        }
                        else
                        {
                            ViewRight += 1;
                            break;
                            //goto breakRight;
                        }
                        }
                    //breakRight;
                    for (int z = j - 1; z >= 0; z--){
                        //topColumn[z] = ForrestMatrix[i][z];
                        if ((ForrestMatrix[i][z] < ForrestMatrix[i][j]))
                        {
                            ViewTop += 1;
                        }
                        else
                        {
                            ViewTop += 1;
                            break;
                        }
                    }
                    for (int h = j + 1; h < cols; h++){
                        //bottomColum[h-j] = ForrestMatrix[i][h];
                        if ((ForrestMatrix[i][h] < ForrestMatrix[i][j]))
                        {
                            ViewBottom += 1;
                        }
                        else
                        {
                            ViewBottom += 1;
                            break;
                        }  
                    
                }

            MaxView = std::max(MaxView, ViewLeft * ViewRight * ViewTop * ViewBottom);
            std::printf("Values are %i, %i, %i, %i and therefore    ", ViewRight, ViewLeft, ViewTop, ViewBottom);
            std::printf("Max value is now %i \n", MaxView);

                
        }
        }
    }
    std::printf("amount of visible trees is %i", VisibleTrees);
} 
