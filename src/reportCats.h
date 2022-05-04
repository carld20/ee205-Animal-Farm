///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Cat.h"

extern bool printAllCats();
extern Cat* findCatByName( const char* name );
extern const char* genderCat( const enum Genders gender );
extern const char* breedCat(  const enum Breeds breed );
extern const char* colorCat(  const enum Colors collarColor );