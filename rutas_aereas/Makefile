SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c
CPPFINAL = -Wall -g -I$(INC) -L$(LIB)

rutas_aereas: librutas_aereas $(OBJ)/imagen.o
	$(CXX) $(CPPFINAL) $(SRC)/rutas_aereas.cpp $(OBJ)/imagen.o -lrutas_aereas -o $(BIN)/rutas_aereas 
test: librutas_aereas
	$(CXX) $(CPPFINAL) $(SRC)/test.cpp -lrutas_aereas -o $(BIN)/test 

librutas_aereas: $(OBJ)/punto.o $(OBJ)/ruta.o $(OBJ)/almacen_rutas.o 
	ar rvs $(LIB)/librutas_aereas.a $(OBJ)/punto.o $(OBJ)/ruta.o $(OBJ)/almacen_rutas.o 
$(OBJ)/punto.o:
	$(CXX) $(CPPFLAGS) $(SRC)/punto.cpp -o $(OBJ)/punto.o
$(OBJ)/ruta.o:
	$(CXX) $(CPPFLAGS) $(SRC)/ruta.cpp -o $(OBJ)/ruta.o
$(OBJ)/almacen_rutas.o:
	$(CXX) $(CPPFLAGS) $(SRC)/Almacen_Rutas.cpp -o $(OBJ)/almacen_rutas.o
$(OBJ)/imagen.o:
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
