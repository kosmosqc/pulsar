//Alain Gionet
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Datapoint.h"

std::vector<Datapoint>enOrdre(std::vector<Datapoint> data);

int main()
{
    std::vector<Datapoint> data;
    std::ifstream linestream("rawdata.txt");
    std::string id,timestamp;
    double latitude,longitude,temprature;
    while (linestream >> latitude >> longitude >> id >> temprature >> timestamp)
    {
        data.push_back(Datapoint(latitude, longitude, temprature, timestamp));
    }
    linestream.close();

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