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
	std::string id, timestamp, line;
	double latitude, longitude, temperature;
	std::ifstream fichierTest("rawdata.txt");
	std::ifstream fichier("rawdata.txt");
	while (!fichier == NULL)
	{
			getline(fichierTest, line);
		try {
			if (line.length() < 25 && line.length() > 0) {
				fichier >> latitude >> longitude >> id;
				throw 1;
			}
			else {
				fichier >> latitude >> longitude >> id >> temperature >> timestamp;
				temperature = (temperature - 32) * (5.0 / 9.0);
				data.insert(Datapoint(latitude, longitude, temperature, timestamp));
			}
		}
		catch (const int& code) {
			std::cout << "Erreur une ligne incomplete a ete ignore " << std::endl;
		}

	}
	fichierTest.close();
	fichier.close();
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