//Alain Gionet
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

#include "Datapoint.h"

void creeFichier(std::set<Datapoint> dataz);
int main()
{
	std::set<Datapoint> data;
	std::string id, timestamp, line, line2;
	double latitude, longitude, temperature;
	std::ifstream test("rawdata.txt");
	std::ifstream linestream("rawdata.txt");
	while (!linestream == NULL)
	{
		
			getline(test, line);
			try {
			//std::cout << line << " **length= "<< line.length() << std::endl;
			if (line.length() < 25 && line.length() > 0) {
				linestream >> latitude >> longitude >> id;
				throw 1;
				
			}
			else {
				linestream >> latitude >> longitude >> id >> temperature >> timestamp;
				temperature = (temperature - 32) * (5.0 / 9.0);
				//	std::cout << latitude << longitude << id << temperature << timestamp <<" &&&&" <<std::endl;
				data.insert(Datapoint(latitude, longitude, temperature, timestamp));
			}
		}
		catch (const int& code) {
			std::cout << "Erreur une ligne incomplete a ete ignore " << std::endl;
		}

	}
	test.close();
	linestream.close();
	creeFichier(data);
}
void creeFichier(std::set<Datapoint> data) {
	std::ofstream outfile("candata.txt");
	std::set<Datapoint>::iterator it;
	for (it = data.begin(); it != data.end(); ++it) {
		outfile << it->getTime() << " " << it->getLattitude() << " " << it->getLongitude() << " " << it->getTemp() << std::endl;
	}
	outfile.close();
}