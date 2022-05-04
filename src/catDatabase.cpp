///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

using namespace std;

int totalCats = 0;

Cat* catDatabaseHeadPointer;

//Checks if database is not negative
extern bool validateDatabase(){
    int validCats = 0;

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        if( !iCat->validate() ){
            return false;

        }

        Cat* foundCat = findCatByName( iCat->getName() ) ; //make findCatByName in reportCats; done
        if( foundCat != iCat ){
            cout << "Animal Farm2: Warning: Found a similar name ["<< iCat->getName() << "]" << endl;

        }
        validCats++;
    }

    if( validCats != totalCats ){
        cout << "Animal Farm2: Error: numberofCats [" << totalCats << "] does not equal [" << validCats << "]" << endl;

        return false;

    }

    return true;

}

//Reset database
void initializeDatabase(){
    if( catDatabaseHeadPointer != nullptr ){
        throw logic_error("Animal Farm2: delete old database first");

    }

    assert( validateDatabase() );

}

bool isCatExist( const Cat* aCat ){
    assert( aCat != nullptr );

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        if( iCat == aCat ){
            return true;

        }
    }
    assert( validateDatabase() );

    return false; //if cat not found
}
