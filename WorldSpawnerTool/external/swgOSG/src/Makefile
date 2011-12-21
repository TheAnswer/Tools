MSH_HOME = ../../meshLib
MSH_INC = $(MSH_HOME)/include
MSH_LIB = $(MSH_HOME)/lib

TRE_HOME = ../../treLib
TRE_INC = $(TRE_HOME)/include
TRE_LIB = $(TRE_HOME)/lib

INC = ../include
LIB = ../lib

LIBS = -L../../../../../osg_mingw/OpenSceneGraph-3.0.1/lib -L/local/lib -losg -losgAnimation -losgViewer -losgText -losgDB -losgGA -L$(TRE_LIB) -ltreLib -L$(MSH_LIB) -lswgMsh -lswg -lz
CXXFLAGS = -g -pipe -W -Wall -pedantic -I$(INC) -I$(MSH_INC) -I$(TRE_INC) -I../../../../../osg_mingw/OpenSceneGraph-3.0.1/include -I../../../../../boost_1_45_0 -I/local/include

swgOSG: swgOSG.cpp swgRepository.o swgRepository.a
	$(CXX) swgOSG.cpp swgRepository.o $(CXXFLAGS) $(LIBS) -o $@

swgRepository.o: swgRepository.cpp $(INC)/swgRepository.hpp
	$(CXX) -c $(CXXFLAGS) swgRepository.cpp -o $@
	
swgRepository.a: swgRepository.cpp $(INC)/swgRepository.hpp
	$(AR) cr $(LIB)/libswgRepository.a swgRepository.o
	ranlib $(LIB)/libswgRepository.a
	

clean:
	rm -f *.o *~ swgOSG
