//Alain Gionet
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Datapoint.h"

std::vector<Datapoint>enOrdre(std::vector<Datapoint> data);

int main()
{
    std::ifstream inputFile("rawdata.txt");
    std::string ligne;
    std::vector<Datapoint> data;
    while (getline(inputFile, ligne))
    {
        std::istringstream ss(ligne);
        std::string id,timestamp;
        
        double latitude,longitude, temprature;
        ss >> latitude >> longitude >> id >> temprature >> timestamp;
        data.push_back(Datapoint(latitude, longitude, temprature, timestamp));
    }
    data = enOrdre(data);
    std::ofstream outfile("candata.txt");
    for (int i = 0; i < 10; i++)
    {
        double temp = data[i].getTemp();
        temp = (temp - 32) * (5.0/9.0);
        data[i].setTemp(temp);
        outfile << data[i].getTime() << " " << data[i].getLattitude() << " " << data[i].getLongitude() << " " << data[i].getTemp() << " " << std::endl;
    }
    outfile.close();
}
std::vector<Datapoint>enOrdre(std::vector<Datapoint> data) {
    std::sort(data.begin(), data.end());
    return data;
}