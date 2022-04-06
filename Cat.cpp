///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "Cat.h"
#include "reportCats.h"

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

using namespace std;

void Cat::zeroOutMember() {
    memset(name, 0, MAX_CAT_NAME);
    gender = Unknown;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;

}

Cat::Cat(){
    zeroOutMember();

}

Cat::Cat( const char *newName, const Genders newGender, const Breeds newBreed, const Weight newWeight ) : Cat(){
    setName( newName );
    setWeight( newWeight );
    setBreed( newBreed );
    setGender( newGender );

    assert(validate());

}

Cat::~Cat(){
    zeroOutMember();

}

const char *Cat::getName(){
    return name;

}

void Cat::setname( const char *newName ){
    validateName( newName );
    memset( name, 0 , MAX_CAT_NAME );
    strcpy( name, newName );

}

Genders Cat::setGender(){
    return gender;

}

Breeds Cat::setBreed() {
    return breed;

}

bool Cat::isFixed(){
    return isCatFixed;

}

Weight Cat::getWeight(){
    return weight;

}

bool Cat::print(){
    assert( validate() );

    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill( ' ' );
    cout << left;
    cout << boolalpha;
    FORMAT_LINE( "Cat", "name" )            << getName() << endl;
    FORMAT_LINE( "Cat", "gender" )          << genderCat( getGender() ) << endl;
    FORMAT_LINE( "Cat", "breed" )           << breedCat( getBreed() ) << endl;
    FORMAT_LINE( "Cat", "isFixed" )         << isFixed() << endl;
    FORMAT_LINE( "Cat", "weoight" )         << getWeight() << endl;

    return true;

}

bool Cat::validate() {
    try {
        validateName(name);
        validateWeight(weight);
        validateGender(gender);
        validateBreed(breed);
    } catch (exception const& e ) {
        cout << e.what() << endl;
        return false;

    }

    return true;

}

bool Cat::validateName( const char *newName ){
    if( newName == nullptr ) {
        throw invalid_argument(": name must not be NULL");
    }
    if( strlen(newName) <= 0 ) {
        throw invalid_argument(": name must be > 0");
    }
    if(strlen(newName) >= MAX_CAT_NAME) {
        throw invalid_argument(": name must be less than 30");
    }

    return true;

}

bool Cat::validateGender( const Genders newGender ){
    if ( newGender == Unknown ) {
        throw invalid_argument(": gender must be specified");
    }

    return true;

}

bool Cat::validateWeight(const Weight newWeight) {
    if(newWeight <= 0 ) {
        throw invalid_argument(": no weight is not possible");

    }

    return true;

}

bool Cat::validateBreed(const Breeds newBreed) {
    if(newBreed == UNKNOWN_BREED ){
        throw invalid_argument(": breed must be specified");

    }

    return true;

}

void Cat::fixCat(){
    Cat::isCatFixed = true;

}

void Cat::setWeight(Weight newWeight) {
    validateWeight(newWeight);
    Cat::weight = newWeight;

}

void Cat::setGender(Genders newGender) {
    if( gender != Unknown ) {
        throw logic_error(": gender is set, can't be changed");

    }

    validateGender( newGender );
    Cat::gender = newGender;

}

void Cat::setBreed( Breeds newBreed ){
    if( breed != UNKNOWN_BREED ){
        throw logic_error(": breed is set, can't be changed");

    }

    validateBreed( newBreed );
    Cat::breed = newBreed;

}