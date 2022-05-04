///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glob.h>

#define MAX_CATS (30)
#define MAX_CAT_NAME (30)

typedef float Weight;
typedef size_t NumCats;
const Weight UNKNOWN_WEIGHT = -1;


enum Genders { Male, Female, Unknown };
enum Breeds { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };
enum Colors { Black, White, Red, Blue, Green, Pink, Clear };

class Cat {
protected:
    char            name[MAX_CAT_NAME];
    enum Genders    gender;
    enum Breeds     breed;
    bool            isCatFixed;
    Weight          weight;
    enum Colors     collarColor;

public:
    Cat*            next;   //Next pointer

private:
    void zeroOutMember();

public:
    Cat();
    Cat( const char *newName, const Genders newGender, const Breeds newBreed, const Weight newWeight, const Colors newCollarColor );
    virtual ~Cat();

public:
    const char *getName() const noexcept;
    void setName( const char* newName );
    Genders getGender() const noexcept;
    Breeds getBreed() const noexcept;
    bool isFixed() const noexcept;
    void fixCat() noexcept;
    Weight getWeight() const noexcept;
    void setWeight( Weight newWeight );
    Colors getCollarColor() const noexcept;
    void setCollarColor( Colors newCollarColor );


protected:
public:
    void setGender( Genders newGender );
    void setBreed( Breeds newBreed );

public:
    bool print() const noexcept;       //prints cat
    bool validate() const noexcept;    //Checks if cat is good

    //Check if new[Name, Gender, Breed, Weight] are valid
public:
    static bool validateName( const char* newName );
    static bool validateGender( const Genders newGender );
    static bool validateBreed( const Breeds newBreed );
    static bool validateWeight( const Weight newWeight );
    static bool validateCollarColor( const Colors newCollarColor );


};

