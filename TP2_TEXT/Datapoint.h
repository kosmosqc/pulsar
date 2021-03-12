#ifndef __Datapoint_H__
#define __Datapoint_H__

#include <iostream>
#include <string>
class Datapoint
{
protected:
	std::string timestamp;
	double longitude;
	double lattitude;
	double temp;
public:
	bool operator< (const Datapoint& autre) const {
		if (lattitude == autre.lattitude) {
			return longitude < autre.longitude;
		}
		else {
			return lattitude > autre.lattitude;
		}
	}
	Datapoint(double lattitude, double longitude, double temp, std::string timestamp);
	double getLattitude();
	double getLongitude();
	double getTemp();
	std::string getTime();
	void setTemp(double temp);
		
}; __Datapoint_H__
#endif
