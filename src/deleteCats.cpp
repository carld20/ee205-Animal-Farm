///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <stdexcept>

#include "deleteCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;


bool deleteCat( Cat* removeCat ){
    assert( removeCat != nullptr );
    assert( validateDatabase() );

    if( removeCat == catDatabaseHeadPointer ) {
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete removeCat;
        totalCats--;

        assert(validateDatabase());
        return true;//if successful
    }

        Cat* iCat = catDatabaseHeadPointer;
        while( iCat != nullptr ){
            if( iCat->next == removeCat ){
                iCat->next = removeCat->next;
                delete removeCat;
                totalCats--;

                assert( validateDatabase() );
                return true;

            }
            iCat = iCat->next;

        }

    assert( validateDatabase() );
    throw invalid_argument( "Animal Farm2: cat name does not exist, can't be deleted");

}

bool deleteAllCats() {
    while( catDatabaseHeadPointer != nullptr ){
        deleteCat( catDatabaseHeadPointer );

    }
    return true;

}