CC=g++
CCFLAGS=-std=c++14
LDFLAGS=-lgdal
APP=landuse

all: $(APP)

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(APP): $(APP).cpp readsources.o conversion.o mesh.o landuse_computation.o
	$(CC) $(LDFLAGS) $(CCFLAGS) $(APP).cpp -o $(APP) readsources.o conversion.o mesh.o landuse_computation.o

test: test.cpp readsources.o mesh.o
	$(CC) $(LDFLAGS) $(CCFLAGS) test.cpp -o test readsources.o mesh.o
