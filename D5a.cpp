#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>

using namespace std;

std::vector< vector <char> > Rearrange(std::vector< vector <char> > LayoutStart, int amount, int start, int stop) {



    std::vector< vector <char> > Layout;

    std::vector<char>::iterator package;
    std::vector <char> VectorToTakeFrom = LayoutStart[start];
    std::vector <char> VectorToDeliverTo = LayoutStart[stop];

    for (int i = 0; i < amount; i++) {
        package = VectorToTakeFrom.end();
        std::printf("Here we are %c", *package);
        //VectorToDeliverTo.insert(VectorToDeliverTo.end(), VectorToTakeFrom.end());
        VectorToTakeFrom.pop_back();
    }
    std::vector <char> ModifiedStartVector = VectorToTakeFrom;
    std::vector <char> ModifiedDeliveryVector = VectorToDeliverTo;

    LayoutStart[start] = ModifiedStartVector;
    LayoutStart[stop] = ModifiedDeliveryVector;

    Layout = LayoutStart;


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
    std::vector<char> Vector1, Vector2, Vector3, Vector4, Vector5, Vector6, Vector7, Vector8, Vector9 ;


    if (layoutRaw.is_open()){
        for (int i = 0; i < 8; i++) {
                getline(layoutRaw, line);
                Vector1.insert(Vector1.begin(), line[1]);
                Vector2.insert(Vector2.begin(), line[5]);
                Vector3.insert(Vector3.begin(), line[9]);
                Vector4.insert(Vector4.begin(), line[13]);
                Vector5.insert(Vector5.begin(), line[17]);
                Vector6.insert(Vector6.begin(), line[21]);
                Vector7.insert(Vector7.begin(), line[25]);
                Vector8.insert(Vector8.begin(), line[29]);
                Vector9.insert(Vector9.begin(), line[33]);
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
                cout << x << " ";
                amount = Output[0];
                start = Output[1];
                stop = Output[2];
            }

            LayoutStart = Rearrange(LayoutStart, amount, start, stop);
            std::cout << "YOOOs";

            /*std::printf("the numbers are %i, %i and %i\n", int Output[0], start, stop);*/
            

            /*layout = Rearrange(layout, amount, start, stop);*/
                }
    }
    else {
        std::printf("file is not open");
    }

}
