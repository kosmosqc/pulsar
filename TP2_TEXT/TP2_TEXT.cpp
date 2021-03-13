//Alain Gionet
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include "Datapoint.h"

void creeFichier(std::set<Datapoint> dataz);
int main()
{
	std::set<Datapoint> data;
	std::string id, timestamp, line;
	double latitude, longitude, temperature;

	std::ifstream linestream("rawdata.txt");
	while (!linestream == NULL)
	{

		linestream >> latitude >> longitude >> id >> temperature >> timestamp;
		temperature = (temperature - 32) * (5.0 / 9.0);
		data.insert(Datapoint(latitude, longitude, temperature, timestamp));

	}
	linestream.close();
	creeFichier(data);
}
void creeFichier(std::set<Datapoint> data) {
	std::ofstream outfile("candata.txt");
	std::set<Datapoint>::iterator it;
	for (it = data.begin(); it != data.end(); ++it) {
		std::cout << it->getTime() << " " << it->getLattitude() << " " << it->getLongitude() << " " << it->getTemp() << std::endl;
	}
	outfile.close();
}