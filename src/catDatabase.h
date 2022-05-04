///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstddef>

#include "Cat.h"

extern Cat* catDatabaseHeadPointer;     //Head pointer
extern int totalCats;                   //Total cats in database


//Implement initializeDatabase
extern void initializeDatabase();

//Implement validateDatabase
extern bool validateDatabase();

//Check if aCat already exist
extern bool isCatExist( const Cat* aCat );

