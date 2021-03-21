CXXFLAGS=-std=c++11 -g
CXX=g++

testBuild: $(OBJECTS)
                $(CXX) $(CXXFLAGS) -Itest/catch -o nextFit nextFitMain.cpp                                                                       
