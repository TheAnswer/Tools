MESH_INC = ../include
MESH_LIB = ../lib
MESH_BIN = ../bin


CFLAG = -I$(MESH_INC) -I../../../../../OpenSceneGraph-3.0.1-VS9.0.30729-x86-release-12741/include -I../../../../../boost_1_45_0 -g -pipe -W -Wall -pedantic -fPIC
LIBS =

OBJS = \
	mshVertex.o \
	mshVertexData.o \
	mshVertexIndex.o \
	apt.o \
	base.o \
	box.o \
	cach.o \
	cclt.o \
	ckat.o \
	cmp.o \
	cshd.o \
	cldf.o \
	cstb.o \
	dtii.o \
	eft.o \
	foot.o \
	flor.o \
	ilf.o \
	lod.o \
	mlod.o \
	model.o \
	msh.o \
	peft.o \
	prto.o \
	sbot.o \
	scot.o \
	sd2d.o \
	sd3d.o \
	shot.o \
	sht.o \
	sktm.o \
	skmg.o \
	slod.o \
	smat.o \
	spam.o \
	stat.o \
	ster.o \
	stot.o \
	str.o \
	swts.o \
	trn.o \
	trnAffector.o \
	trnBoundary.o \
	trnLayer.o \
	ws.o

MESH_OBJS = \
	mshVertex.o \
	mshVertexData.o \
	mshVertexIndex.o \
	base.o \
	box.o \
	model.o \
	msh.o \
	sht.o \
	eft.o \
	cshd.o


all: $(MESH_BIN)/iffDump $(MESH_BIN)/readMSH $(MESH_BIN)/readLOD \
	$(MESH_BIN)/readTRN $(MESH_BIN)/readSWG \
	$(MESH_LIB)/libswgMsh.a $(MESH_LIB)/libswg.a

$(MESH_LIB)/libswg.a: $(OBJS)
	#$(CXX) $(OBJS) -o $(MESH_LIB)/libswg.s
	ar cru $(MESH_LIB)/libswg.a $(OBJS)
	#ranlib $(MESH_LIB)/libswg.a

$(MESH_LIB)/libswgMsh.a: $(MESH_OBJS)
	#$(CXX) -shared $(MESH_OBJS) -o $(MESH_LIB)/libswgMsh.so
	ar cru $(MESH_LIB)/libswgMsh.a $(MESH_OBJS)
	#ranlib $(MESH_LIB)/libswgMsh.a

$(MESH_BIN)/iffDump: iffDump.cpp
	$(CXX) $(CFLAG) iffDump.cpp $(LIBS) -o $(MESH_BIN)/iffDump

$(MESH_BIN)/readMSH: readMSH.cpp $(MESH_OBJS)
	$(CXX) $(CFLAG) $(MESH_OBJS) readMSH.cpp \
	$(LIBS) -o $(MESH_BIN)/readMSH

$(MESH_BIN)/readLOD: readLOD.cpp lod.o $(MESH_OBJS)
	$(CXX) $(CFLAG) readLOD.cpp lod.o $(MESH_OBJS) \
	$(LIBS) -o $(MESH_BIN)/readLOD

$(MESH_BIN)/readTRN: readTRN.cpp trn.o trnAffector.o trnBoundary.o base.o \
	trnLayer.o
	$(CXX) $(CFLAG) readTRN.cpp trn.o base.o trnAffector.o trnBoundary.o \
	trnLayer.o $(LIBS) -o $(MESH_BIN)/readTRN

$(MESH_BIN)/readSWG: readSWG.cpp $(OBJS)
	$(CXX) $(CFLAG) readSWG.cpp $(OBJS) $(LIBS) -o $(MESH_BIN)/readSWG

apt.o: apt.cpp $(MESH_INC)/meshLib/apt.hpp
	$(CXX) $(CFLAG) -c apt.cpp

base.o: base.cpp $(MESH_INC)/meshLib/base.hpp
	$(CXX) $(CFLAG) -c base.cpp

box.o: box.cpp $(MESH_INC)/meshLib/box.hpp
	$(CXX) $(CFLAG) -c box.cpp

cach.o: cach.cpp $(MESH_INC)/meshLib/cach.hpp
	$(CXX) $(CFLAG) -c cach.cpp

cclt.o: cclt.cpp $(MESH_INC)/meshLib/cclt.hpp $(MESH_INC)/meshLib/shot.hpp
	$(CXX) $(CFLAG) -c cclt.cpp

ckat.o: ckat.cpp $(MESH_INC)/meshLib/ckat.hpp
	$(CXX) $(CFLAG) -c ckat.cpp

cmp.o: cmp.cpp $(MESH_INC)/meshLib/cmp.hpp $(MESH_INC)/meshLib/vector3.hpp \
	$(MESH_INC)/meshLib/matrix3.hpp
	$(CXX) $(CFLAG) -c cmp.cpp

cshd.o: cshd.cpp $(MESH_INC)/meshLib/cshd.hpp sht.o
	$(CXX) $(CFLAG) -c cshd.cpp

cldf.o: cldf.cpp $(MESH_INC)/meshLib/cldf.hpp
	$(CXX) $(CFLAG) -c cldf.cpp

eft.o: eft.cpp $(MESH_INC)/meshLib/eft.hpp
	$(CXX) $(CFLAG) -c eft.cpp

foot.o: foot.cpp $(MESH_INC)/meshLib/foot.hpp
	$(CXX) $(CFLAG) -c foot.cpp

flor.o: flor.cpp $(MESH_INC)/meshLib/flor.hpp
	$(CXX) $(CFLAG) -c flor.cpp

lod.o: lod.cpp $(MESH_INC)/meshLib/lod.hpp msh.o \
	$(MESH_INC)/meshLib/vector3.hpp \
	$(MESH_INC)/meshLib/matrix3.hpp
	$(CXX) $(CFLAG) -c lod.cpp

mlod.o: mlod.cpp $(MESH_INC)/meshLib/mlod.hpp
	$(CXX) $(CFLAG) -c mlod.cpp

msh.o: msh.cpp $(MESH_INC)/meshLib/msh.hpp sht.o cshd.o base.o
	$(CXX) $(CFLAG) -c msh.cpp

model.o: model.cpp $(MESH_INC)/meshLib/model.hpp
	$(CXX) $(CFLAG) -c model.cpp

peft.o: peft.cpp $(MESH_INC)/meshLib/peft.hpp
	$(CXX) $(CFLAG) -c peft.cpp

prto.o: prto.cpp $(MESH_INC)/meshLib/prto.hpp \
	$(MESH_INC)/meshLib/cell.hpp \
	$(MESH_INC)/meshLib/portal.hpp
	$(CXX) $(CFLAG) -c prto.cpp

sbot.o: sbot.cpp $(MESH_INC)/meshLib/sbot.hpp $(MESH_INC)/meshLib/stot.hpp
	$(CXX) $(CFLAG) -c sbot.cpp

scot.o: scot.cpp $(MESH_INC)/meshLib/scot.hpp $(MESH_INC)/meshLib/stot.hpp
	$(CXX) $(CFLAG) -c scot.cpp

sd2d.o: sd2d.cpp $(MESH_INC)/meshLib/sd2d.hpp
	$(CXX) $(CFLAG) -c sd2d.cpp

sd3d.o: sd3d.cpp $(MESH_INC)/meshLib/sd3d.hpp
	$(CXX) $(CFLAG) -c sd3d.cpp

shot.o: shot.cpp $(MESH_INC)/meshLib/shot.hpp
	$(CXX) $(CFLAG) -c shot.cpp

sht.o: sht.cpp $(MESH_INC)/meshLib/sht.hpp $(MESH_INC)/meshLib/eft.hpp
	$(CXX) $(CFLAG) -c sht.cpp

sktm.o: sktm.cpp $(MESH_INC)/meshLib/sktm.hpp
	$(CXX) $(CFLAG) -c sktm.cpp

skmg.o: skmg.cpp $(MESH_INC)/meshLib/skmg.hpp
	$(CXX) $(CFLAG) -c skmg.cpp

slod.o: slod.cpp $(MESH_INC)/meshLib/slod.hpp
	$(CXX) $(CFLAG) -c slod.cpp

smat.o: smat.cpp $(MESH_INC)/meshLib/smat.hpp
	$(CXX) $(CFLAG) -c smat.cpp

spam.o: spam.cpp $(MESH_INC)/meshLib/spam.hpp
	$(CXX) $(CFLAG) -c spam.cpp

stat.o: stat.cpp $(MESH_INC)/meshLib/stat.hpp $(MESH_INC)/meshLib/shot.hpp
	$(CXX) $(CFLAG) -c stat.cpp

ster.o: ster.cpp $(MESH_INC)/meshLib/ster.hpp
	$(CXX) $(CFLAG) -c ster.cpp

stot.o: stot.cpp $(MESH_INC)/meshLib/stot.hpp $(MESH_INC)/meshLib/shot.hpp
	$(CXX) $(CFLAG) -c stot.cpp

str.o: str.cpp $(MESH_INC)/meshLib/str.hpp
	$(CXX) $(CFLAG) -c str.cpp

swts.o: swts.cpp $(MESH_INC)/meshLib/swts.hpp
	$(CXX) $(CFLAG) -c swts.cpp

trn.o: trn.cpp $(MESH_INC)/meshLib/trn.hpp
	$(CXX) $(CFLAG) -c trn.cpp

trnAffector.o: trnAffector.cpp $(MESH_INC)/meshLib/trnAffector.hpp
	$(CXX) $(CFLAG) -c trnAffector.cpp

trnBoundary.o: trnBoundary.cpp $(MESH_INC)/meshLib/trnBoundary.hpp
	$(CXX) $(CFLAG) -c trnBoundary.cpp

trnLayer.o: trnLayer.cpp $(MESH_INC)/meshLib/trnLayer.hpp
	$(CXX) $(CFLAG) -c trnLayer.cpp

ws.o: ws.cpp $(MESH_INC)/meshLib/ws.hpp $(MESH_INC)/meshLib/vector3.hpp \
	$(MESH_INC)/meshLib/matrix3.hpp
	$(CXX) $(CFLAG) -c ws.cpp

ilf.o: ilf.cpp $(MESH_INC)/meshLib/ilf.hpp
	$(CXX) $(CFLAG) -c ilf.cpp

dtii.o: dtii.cpp $(MESH_INC)/meshLib/dtii.hpp
	$(CXX) $(CFLAG) -c dtii.cpp

cstb.o: cstb.cpp $(MESH_INC)/meshLib/cstb.hpp
	$(CXX) $(CFLAG) -c cstb.cpp

mshVertex.o: mshVertex.cpp $(MESH_INC)/meshLib/mshVertex.hpp
	$(CXX) $(CFLAG) -c mshVertex.cpp

mshVertexData.o: mshVertexData.cpp $(MESH_INC)/meshLib/mshVertexData.hpp \
	mshVertex.o
	$(CXX) $(CFLAG) -c mshVertexData.cpp

mshVertexIndex.o: mshVertexIndex.cpp $(MESH_INC)/meshLib/mshVertexIndex.hpp
	$(CXX) $(CFLAG) -c mshVertexIndex.cpp

clean:
	rm -f *.o *~ $(MESH_LIB)/*.so $(MESH_BIN)/iffDump \
	$(MESH_BIN)/readMSH $(MESH_BIN)/readLOD $(MESH_BIN)/readTRN \
	$(MESH_BIN)/readSWG

