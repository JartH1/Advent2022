#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>
#include <vector>

using namespace std;


class Document {
    public:
        string Name;
        int Size;
        string Type;
        int Layer;
        int ID;
        int MotherID;  //Next time use pointer or Document(class), use parent or root as name
        vector<int> Arr; // Better to have list of pointers with type Document
        bool SummingCompleted;
        string Path;
};



int main() {



    int count = 0;
    int layer = 0;
    int Id;
    int motherId;
    std::string dirName;
    int AmountCmdDot = 0;
    int AmountCmdSlash = 0;
    int AmountCmdDir = 0;
    std::string path = "Home";
    

    std::string line;
    std::ifstream commands ("inputD7a.txt");
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
    Document Filebook[count]; //Instead of using static Array, should use a linked list
    int x = 0;
    commands.clear();
    commands.seekg (0, ios::beg);

    if (commands.is_open()) 
    {
        while(commands.peek()!=EOF) 
        {
            getline(commands, line);
            //std::printf("length of the line is %i", line.size());
            Filebook[x] = Document();

            if (line.substr(0,1) == "$")  //Identify a command
            {
                if (line.substr(2,2) == "cd") 
                {
                    if (line.substr(5,2) == "..")
                    {
                        layer -=1;
                        Id = motherId;
                        dirName = Filebook[Id].Name;
                        motherId = Filebook[Id].MotherID;
                        Filebook[x].Type = "Command ..";
                        AmountCmdDot += 1;
                        char slash = '/';
                        int characterLocation = path.find_last_of('/');
                        path = path.substr(0, characterLocation);
                        //std::printf("slice can be found %i \n", characterLocation);
                    }

                
                        
            
                    else if (line.substr(5,1) == "/")
                    {
                        layer = 0;
                        Id = 0;
                        motherId = -1;
                        dirName = "/";
                        Filebook[x].Type = "Command /";
                        AmountCmdSlash += 1;
                        path = "Home";
                    }
                    else
                    {
                        layer +=1;
                        dirName = line.substr(5,(line.length()-5)); 
                        Filebook[x].Type = "Command open Dir";
                        for (int i = 0; i < x; i++) {
                            if((Filebook[i].Name == dirName) & (Filebook[i].Path == path)){
                                Id = Filebook[i].ID;
                                motherId = Filebook[i].MotherID;
                            }
                            else {}
                        }   
                        AmountCmdDir +=1;   
                        path = path + "/" + dirName;

                    }
                }
                else if (line.substr(2,2) == "ls")
                {
                    int lookForward = 0;
                    Filebook[x].Type = "Command ls";

                }
            }
            else if (line.substr(0,3) == "dir")
            {
                Filebook[x].Name = line.substr(4,(line.length()-4));
                //printf("Dir name is %s   \n", Filebook[x].Name.c_str());
                Filebook[x].Type = "Dir";
                Filebook[x].ID = x;
                Filebook[x].MotherID = Id;
                Filebook[x].Layer = layer;
                Filebook[x].Path = path;
            }
            else
            {
                int splitIndex = line.find(" ");
                Filebook[x].Size = std::stoi(line.substr(0,splitIndex));
                Filebook[x].Name = line.substr(splitIndex, line.length() - splitIndex);
                Filebook[x].Type = "File";
                //Filebook[x].Size() = docSize;
                //printf("Document name is %s   \n", Filebook[x].Name.c_str());
                //printf("Document size is %i   \n", Filebook[x].Size);
                Filebook[x].ID = x;
                Filebook[x].MotherID = Id;
                Filebook[x].Layer = layer;
                Filebook[x].SummingCompleted = true;
                Filebook[x].Path = path;

            }
            x +=1;
            //std::printf("%s \n", path.c_str());
        
        }
    }
    else 
    {
        std::printf("file is not open");
    }
    Filebook[0].Name = "/";
    Filebook[0].Type = "Dir";
    std::printf("We are done");

//Find all daughter files
    for (int j = 0; j < count; j++) {
        if ((Filebook[j].Name != "") & (Filebook[j].Type != "")) {
            Filebook[Filebook[j].MotherID].Arr.push_back(j);
        }   
        else {}

    }

//Fill in size of all daughter files
    for (int q = 0; q < 16; q++){  //Recursive or left side search binary tree algorithm.
        for (int j = 0; j < count; j++) {
            if ((Filebook[j].Arr.size() != 0)) {
                int filesizeSum = 0;
                int counter = 0;
                for (int k = 0; k < Filebook[j].Arr.size(); k++) {
                    if (Filebook[Filebook[j].Arr[k]].SummingCompleted == true)
                    {
                        filesizeSum += Filebook[Filebook[j].Arr[k]].Size;    
                        counter += 1;
                    }
                }
                if (counter == Filebook[j].Arr.size()) {
                    Filebook[j].SummingCompleted = true;
                    Filebook[j].Size = filesizeSum;
                }
            }   
            else {
                Filebook[j].SummingCompleted = true;
                }


        }
    }
    int SmallDirSize = 0;
    int TotalSizeWithoutDir = 0;
    int Delta = 10000000;

    for (int j = 0; j < count; j++){
        if ((Filebook[j].Type == "Dir") & (Filebook[j].Size < 100000)){
            SmallDirSize += Filebook[j].Size;
            //std::printf("Size of newest dir is %i making the sum %i \n", Filebook[j].Size, SmallDirSize);
        }
        else {}
    }
    for (int j = 0; j < count; j++){
        if ((Filebook[j].Type == "Dir")){
            TotalSizeWithoutDir = 48381165 - Filebook[j].Size;
            if (TotalSizeWithoutDir <= 40000000){
                if ((40000000-TotalSizeWithoutDir) < Delta){
                    Delta = 40000000-TotalSizeWithoutDir;
                    std::printf("Size of the Dir that is needed to delete is %i because its %i away from 30k \n", Filebook[j].Size, Delta);
                }
            
            }
        }
        else {}   
    }
    int TotalDirSize = 0;
        for (int k = 0; k < count; k++){
            if ((Filebook[k].Type == "Dir")){
                int Delta1 = Filebook[k].Size - 8381165;
                TotalDirSize += Filebook[k].Size;
                std::printf("We are checking DIR size %i and Delta 1 is %i \n", Filebook[k].Size, Delta1);
                if (Delta1 > 0){
                        std::printf("Size of the second attemptt for Dir that is needed to delete is %i because its %i away from 30k \n", Filebook[k].Size, Delta1);
                    }
                
                }

            else {}

        }
        std::printf("Total Dir size is %i", TotalDirSize);
    std::printf("We are done");
}


