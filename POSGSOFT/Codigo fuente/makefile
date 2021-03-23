all: compilar
compilar: criterio baseDatos menu acta main detallesCriterio persona
			g++ -o ejecutable criterio.o basedatos.o menu.o acta.o main.o detallesCriterio.o persona.o
criterio: criterio.cpp criterio.h
			g++ -c criterio.cpp

baseDatos: baseDatos.cpp baseDatos.h
			g++ -c baseDatos.cpp
menu: menu.cpp menu.h
			g++ -c menu.cpp
acta: acta.cpp acta.h detallesCriterio.h
			g++ -c acta.cpp
detallesCriterio: detallesCriterio.cpp detallesCriterio.h
			g++ -c detallesCriterio.cpp
persona: persona.cpp persona.h
			g++ -c persona.cpp
main: main.cpp menu.h baseDatos.h
			g++ -c main.cpp