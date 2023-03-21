#Makefile for Rational Calculator

CC = g++
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb

SOURCE = src
INCLUDE = include
OBJECT = build
BINARY = bin
RESOURCE = resource
EXAMPLE = example


all: ${BINARY}/rc


${BINARY}/rc: ${OBJECT}/main.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/rc ${OBJECT}/main.o


${OBJECT}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/main.h ${INCLUDE}/ratio.h ${INCLUDE}/rationalexpression.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/main.o ${SOURCE}/main.cpp


.PHONY: clean run run-example


clean:
	rm -rf ${OBJECT}/* ${BINARY}/*


run: ${BINARY}/rc
	${BINARY}/rc