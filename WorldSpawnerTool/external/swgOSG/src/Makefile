MSH_HOME = ../../meshLib
MSH_INC = $(MSH_HOME)/include
MSH_LIB = $(MSH_HOME)/lib

TRE_HOME = ../../treLib
TRE_INC = $(TRE_HOME)/include
TRE_LIB = $(TRE_HOME)/lib

INC = ../include

LIBS = -losg -losgAnimation -losgViewer -lz -L$(TRE_LIB) -ltreLib -L$(MSH_LIB) -lswgMsh -lswg
CXXFLAGS = -g -pipe -W -Wall -pedantic -I$(INC) -I$(MSH_INC) -I$(TRE_INC)

swgOSG: swgOSG.cpp swgRepository.o
	$(CXX) swgOSG.cpp swgRepository.o $(CXXFLAGS) $(LIBS) -o $@

swgRepository.o: swgRepository.cpp $(INC)/swgRepository.hpp
	$(CXX) -c $(CXXFLAGS) swgRepository.cpp -o $@

clean:
	rm -f *.o *~ swgOSG
