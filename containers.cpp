#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

/**
 * @brief loading data from in_file to cars
 * @param cars: vector, will come in empty
 * @param in_file: input from csv file to transfer data from in_file to cars
 */
void Load_Data(std::vector<Car> &cars, const std::string &in_file)
{
    // TODO: Load data from file
    Car temp;
    csvstream csvin(in_file);

    // TODO: Create a Car structure with the column information
    std::map<std::string, std::string> row;

    // TODO: Add Car objects to the vector
    while (csvin >> row)
    {
        temp.vin = row["vin"];
        temp.make = row["car_make"];
        temp.year = std::stoi(row["car_year"]);
        temp.color = row["car_color,"];
        temp.value =std::stod(row["value"]);
        temp.state = row["state"];
        cars.push_back(temp);
    }
    return;
}

/**
 * @brief: This function checks for either the highest or lowest value depending
 * on the value of the operation parameter.
 * @param cars: sent vector of list of cars
 * @param operation: sent value, will be either MIN or MAX
 * @return
 */
Car Car_Value_Analytics(std::vector<Car> &cars, int operation)
{
    //uses minmax_elements to find values, and a lambda vector
    auto minmax_cars = std::minmax_element(cars.begin(), cars.end(),
                                           [](Car const& lhs, Car const& rhs)
                                           { return lhs.value < rhs.value;});

    if (operation == MAX)
    {
        return *minmax_cars.second;
    }
    else if (operation == MIN)
    {
        return *minmax_cars.first;
    }
    return Car();
}

/**
 * @brief: takes two paramerters, a vector and an integer, and create a
 * new vector with only cars listed by decade, sorted by low to high value.
 * @param cars: vector that contains the list of car data
 * @param decade: year inputted from main
 * @return: new_cars vector sorted by decade in least to most expensive order.
 */
std::vector<Car> Cars_from_decade(std::vector<Car> &cars, int decade)
{
    int year_last_digit = decade % 10; //to get last digit of the year
    decade = decade - year_last_digit; //set decade year to start at 0
    Car temp; //to store values temporarily
    std::vector<Car> new_cars; //new vector to be sent back

    //creating a new vector new_cars
    for (int i = decade; i < decade+10; i++)//to sort by decade
    {
        for (const auto& value: cars)
        {
            if(value.year == i)
            {
                temp.vin = value.value;
                temp.make = value.make;
                temp.year = value.year;
                temp.color = value.color;
                temp.value = value.value;
                temp.state = value.state;
                new_cars.push_back(temp);
            }
        }
    }
   //to sort new_cars with value data from least to greatest
    std::sort(new_cars.begin(), new_cars.end(),
              [](Car min, Car max){return min.value < max.value;});
    return new_cars;
}
