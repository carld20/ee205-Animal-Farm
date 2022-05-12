///////////////////////////////////////////////////////////////////////////////
////          University of Hawaii, College of Engineering
///// @brief  Lab 07d - AnimaL Farm1 - EE 205 - Spr 2022
////
//// Usage:  Animal Farm1
////
//// File: main.c
////
////
////
//// @author Carl Domingo <carld20@hawaii.edu>
//// @date   03/08/2022
/////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <exception>  // For try/catch blocks
#include <iostream>
#include <cstring>

#include "Cat.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
    cout << "Starting Animal Farm2" << endl ;

    initializeDatabase() ;

#ifdef DEBUG
    {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(testCat.getCollarColor() == White);
      assert(!testCat.isFixed());
      assert(!testCat.validate());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatExist(&testCat)) ;
   }
#endif

    bool result ;
    result = addCat( new Cat( "Dominick", FEMALE, MAINE_COON, 15.0, Black )) ;
    assert( result ) ;
    if( !result ) throw logic_error ("Animal Farm2: addCat() failed" ) ;
    result = addCat( new Cat( "Seabass", MALE, PERSIAN , 2.3, White )) ;
    assert( result ) ;
    result = addCat( new Cat( "Brae", FEMALE, PERSIAN, 19.7, Red )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kebin", FEMALE, MANX, 25.9, Blue )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kurris", MALE, SHORTHAIR, 13.4, Blue )) ;
    assert( result ) ;
    result = addCat( new Cat( "Paul", MALE, MAINE_COON, 8.2, Green )) ;
    assert( result ) ;
    result = addCat( new Cat( "Dan Dan", FEMALE, MANX, 22.3, Pink )) ;
    assert( result ) ;
    result = addCat( new Cat( "Alden", MALE, PERSIAN, 32.1, Red )) ;
    assert( result ) ;
    result = addCat( new Cat( "Jeriel", FEMALE, MAINE_COON, 15.7, White )) ;
    assert( result ) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *paul = findCatByName("Paul");
      assert(paul != nullptr);
      // Test not finding a cat
      assert(findCatByName("Paul's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(paul) == true);
      try {
         deleteCat(paul); // Verify that Bella's not there
      } catch (exception const &e) {}

      paul = nullptr;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with Animal Farm2" ;

    return( EXIT_SUCCESS ) ;
}



