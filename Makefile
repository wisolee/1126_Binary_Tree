#----------------------------------------------------------------------
#  Author: William Sola Lee, wisolee@ucsc.edu
#  linked_list
#
#  make all                 Build the executable image, all necessary
#                           object files, and any required intermediate
#                           files.
#  make clean               Delete object files and generated inter-
#                           mediate files.  Do not delete executable 
#                           image
#  make spotless            Depends on clean and deletes the excutable
#                           image
#  make ci                  Checks in all source files (but not gene-
#                           rated files) into the RCS subdirectory.
#  make deps                Recreates the dependencies
#  make submit              submit project files
#  make check_submit        verifies that files were successfully sub-
#                           mitted
#----------------------------------------------------------------------

CPP = g++ -g -O0 -Wall -Wextra-std=gnu++14

MODULES = binary_tree node
HDSRC = ${MODULES:=.h}
CPPSRC = ${MODULES:=.cpp} main.cpp
OBJECTS = ${CPPSRC:.cpp=.o}
EXECBIN = binary_tree

all: ${EXECBIN}

${EXECBIN}: ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS}

clean:
	rm ${OBJECTS}

spotless:
	rm ${OBJECTS} ${EXECBIN}
	