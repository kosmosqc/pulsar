#ifndef __Datapoint_H__
#define __Datapoint_H__

#include <iostream>
#include <string>
class Datapoint
{
private:
	std::string timestamp;
	double longitude;
	double lattitude;
	double temp;
public:

	Datapoint(double lattitude, double longitude, double temp, std::string timestamp) {
		this->lattitude = lattitude;
		this->longitude = longitude;
		this->temp = temp;
		this->timestamp = timestamp;

	}
	bool operator< (const Datapoint& autre) const {
		if (lattitude == autre.lattitude) {
			//std::cout << "longitude #1 " << longitude << " <  longitude #2 " << autre.longitude << " Resultat bool = " << (longitude < autre.longitude) << std::endl;
			return longitude < autre.longitude;
		}
		else
		{
			//std::cout << "Lattidue #1 " << lattitude << " >  Lattidue #2 " << autre.lattitude << " Resultat bool = " << (lattitude > autre.lattitude) << std::endl;
			return lattitude > autre.lattitude;
		}
	}
	double getLattitude()const { return this->lattitude; };
	double getLongitude()const { return this->longitude; };
	double getTemp()const { return this->temp; };
	std::string getTime()const { return this->timestamp; };

}; __Datapoint_H__
#endif
