/*
 * File: converter.h
 * -----------------------------------------------
 * This interfaces export useful function to convert things' value
 */

#pragma once
#ifndef _converter_h
#define _converter_h

/* degree */
double degC2F(double deg);
double degF2C(double deg);

/* distance */
double distM2I(double dist);
double distI2M(double dist);
double distM2F(double dist);
double distF2M(double dist);
double distF2I(double dist);
double distI2F(double dist);

double windChill(double windSpeed, double degF);
void windChillTable();
void error(std::string msg);

#endif