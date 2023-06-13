/*
 * File: veclib.h
 * -------------------------------------------
 * This interface exports useful function for vector handling.
 */

#pragma once
#ifndef _veclib_h
#define _veclib_h
#include "vector.h"

void printVector(Vector<int> &vec);
void removeZeroElements(Vector<int> &vec);

#endif