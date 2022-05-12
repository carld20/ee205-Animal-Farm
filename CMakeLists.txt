cmake_minimum_required(VERSION 3.22)

project(ee205_animal_farm2
        VERSION 2.0
        DESCRIPTION "All animals are equal, but some animals are more equal than others"
        LANGUAGES CXX)


add_executable(ee205_lab_animal_farm2 src/main.cpp src/addCats.cpp src/addCats.h src/catDatabase.cpp src/catDatabase.h src/deleteCats.cpp src/deleteCats.h src/reportCats.cpp src/reportCats.h src/Cat.cpp src/Cat.h)
