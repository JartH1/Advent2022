#include <iostream>
#include <fstream>
#include <string>

int main() {

    int array_len=0;
    int counter=1;
    int counter1=0;
    int calories=0;
    int number_of_elves=0;
    int max_calories =0;
    std::string line;
    std::ifstream in ("inputD1a.txt");


    if (in.is_open()) {
        /*Get the amount of lines in the array and get the amount of empty rows*/
        while(in.peek()!=EOF) {
            getline(in, line);
            array_len++;
            if(line.empty()) {
            number_of_elves++;
            } 
            else {}
        }    
        std::printf("The number of lines in the array is %d\n", array_len);

        int raw_array[array_len];
        std::printf("the number of elves is %d", number_of_elves);
        int calorie_array[number_of_elves];

        in.clear();
        in.seekg(0);


        /*Sum all calories untill there is an empty line, place value in array, compare with max value to see if max can be replaced*/
        while (in.peek() !=EOF) {
            while(getline(in,line)) {
                if(line.empty()) {
                    calorie_array[counter1] = calories;

                    if(calories > max_calories){
                        max_calories = calories;
                    } else {}
                    calories = 0;
                    counter1++;
                } else {
                    calories += stoi(line);
                }
            }
        }

        /*summarize and print conclusions*/
        std::printf("the top three amount of calories are: %d, %d and %d", calorie_array[0], calorie_array[1], calorie_array[2]);
        std::sort(calorie_array, calorie_array + number_of_elves);
        std::printf("the top three amount of calories are: %d, %d and %d", calorie_array[number_of_elves-1], calorie_array[number_of_elves-2], calorie_array[number_of_elves-3]);
        int top3_calories = calorie_array[number_of_elves-1] + calorie_array[number_of_elves-2] +calorie_array[number_of_elves-3];
        std::printf("the total amount of calories of the three most calorie carrying elves is: %d", top3_calories);
    } else {
        std::printf("file is not open");
    }

    return 0;
}
