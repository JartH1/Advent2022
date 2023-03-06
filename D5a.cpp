#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>

using namespace std;

std::vector< vector <char> > Rearrange(std::vector< vector <char> > LayoutStart, int amount, int start, int stop) {

    int test = 4;
    std::vector< vector <char> > Layout;


    std::vector<char>::iterator package;
    //std::cout << "IAMHERE";
    std::vector <char> VectorToTakeFrom = LayoutStart[start-1];
    std::vector <char> VectorToDeliverTo = LayoutStart[stop-1];
    std::vector <char> VectorToTakeFromTemp = VectorToTakeFrom;
    std::vector <char> VectorToAdd;

    //std::cout << amount;
    

    /*for (int i = 0; i < amount; i++) {
        VectorToTakeFrom = VectorToTakeFromTemp;
        int n = VectorToTakeFrom.size();
        //package = VectorToTakeFrom[n-1];
        //std::cout <<  n << ' ';
        std::cout << VectorToTakeFrom[n-1] << ' ';
        //std::printf("Package char is  %c \n", *package);
        VectorToDeliverTo.insert(VectorToDeliverTo.end(), VectorToTakeFrom[n-1]);
        VectorToTakeFromTemp = std::vector <char>(VectorToTakeFrom.begin(), VectorToTakeFrom.end()-1);
        //std::cout << VectorToDeliverTo.size();
    }*/
    for (int i = 0; i < amount; i++) {
        VectorToTakeFrom = VectorToTakeFromTemp;
        int n = VectorToTakeFrom.size();
        VectorToAdd.insert(VectorToAdd.begin(), VectorToTakeFrom[n-1]);
        VectorToTakeFromTemp = std::vector <char>(VectorToTakeFrom.begin(), VectorToTakeFrom.end()-1);
    }   
    VectorToDeliverTo.insert(VectorToDeliverTo.end(), VectorToAdd.begin(), VectorToAdd.end());

    /*std::vector <char> ModifiedStartVector = VectorToTakeFrom;
    std::vector <char> ModifiedDeliveryVector = VectorToDeliverTo;

    LayoutStart[start] = ModifiedStartVector;
    LayoutStart[stop] = ModifiedDeliveryVector;*/
    Layout = LayoutStart;
    Layout[start -1] = VectorToTakeFromTemp;
    Layout[stop -1] = VectorToDeliverTo;




    return Layout;
}
 






std::vector<int> ExtractData(std::string line) {

    int amount, start, stop;
    std::vector<int> Output;


    amount = std::stoi(line.substr(5, (line.find("from"))-6));
    start = std::stoi(line.substr(((line.find("from"))+5), 1));
    stop = std::stoi(line.substr(line.find("from")+10, 1));

    Output.push_back(amount);
    Output.push_back(start);
    Output.push_back(stop);


    return Output;
}

int main() {

    std::string line;

    std::ifstream commands ("inputD5aCommands.txt");
    std::ifstream layoutRaw ("inputD5a.txt");
    int amount;
    int start;
    int stop;
    std::vector<char> Vector1, Vector2, Vector3, Vector4, Vector5, Vector6, Vector7, Vector8, Vector9;


    if (layoutRaw.is_open()){
        for (int i = 0; i < 8; i++) {
                getline(layoutRaw, line);
                if (line[1] != ' '){
                    Vector1.insert(Vector1.begin(), line[1]);
                    }

                if (line[5] != ' '){
                    Vector2.insert(Vector2.begin(), line[5]);
                    }   

                if (line[9] != ' '){
                    Vector3.insert(Vector3.begin(), line[9]);
                    }

                if (line[13] != ' '){    
                    Vector4.insert(Vector4.begin(), line[13]);
                    }

                if (line[17] != ' '){       
                    Vector5.insert(Vector5.begin(), line[17]);
                }   

                if (line[21] != ' '){
                Vector6.insert(Vector6.begin(), line[21]);
                }

                if (line[25] != ' '){
                Vector7.insert(Vector7.begin(), line[25]);
                }

                if (line[29] != ' '){
                Vector8.insert(Vector8.begin(), line[29]);
                }

                if (line[33] != ' '){
                    Vector9.insert(Vector9.begin(), line[33]);
                }
            }
    }


    else {
        std::printf("file is not open");
    }  

    std::vector<vector <char> > LayoutStart;
    LayoutStart.insert(LayoutStart.end(), Vector1);
    LayoutStart.insert(LayoutStart.end(), Vector2);
    LayoutStart.insert(LayoutStart.end(), Vector3);
    LayoutStart.insert(LayoutStart.end(), Vector4);
    LayoutStart.insert(LayoutStart.end(), Vector5);
    LayoutStart.insert(LayoutStart.end(), Vector6);
    LayoutStart.insert(LayoutStart.end(), Vector7);
    LayoutStart.insert(LayoutStart.end(), Vector8);
    LayoutStart.insert(LayoutStart.end(), Vector9);



    if (commands.is_open()) {
        while(commands.peek()!=EOF) {
            getline(commands, line);

            std::vector<int> Output = ExtractData(line);
            for (int x : Output){
                //cout << x << " ";
                amount = Output[0];
                start = Output[1];
                stop = Output[2];
            }

            LayoutStart = Rearrange(LayoutStart, amount, start, stop);
            //std::cout << "YOOOs";
            /*for (int i = 0; i < LayoutStart.size(); i++) {
                //std::printf("Last value is %c", LayoutStart[i].end());
                std::cout << LayoutStart[i].end() << ' '

            }*/

            /*std::printf("the numbers are %i, %i and %i\n", int Output[0], start, stop);*/
            

            /*layout = Rearrange(layout, amount, start, stop);*/
                }

                
            std::cout << "Ik ben klaar";
            int testing = 4;
    }
    else {
        std::printf("file is not open");
    }
    std::printf("Dit is het einde van het scripje")
}
