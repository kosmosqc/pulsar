#include "Datapoint.h"

Datapoint::Datapoint(double lattitude, double longitude, double temp, std::string timestamp) {
	this->lattitude = lattitude;
	this->longitude = longitude;
	this->temp = temp;
	this->timestamp = timestamp;

}
Datapoint::Datapoint() {

}
double Datapoint::getLattitude() {
	return this->lattitude;
}
double Datapoint::getLongitude() {
	return this->longitude;
}
double Datapoint::getTemp() {
	return this->temp;
}
std::string Datapoint::getTime() {
	return this->timestamp;
}
void Datapoint::setTemp(double temp) {
	this->temp = temp;
}