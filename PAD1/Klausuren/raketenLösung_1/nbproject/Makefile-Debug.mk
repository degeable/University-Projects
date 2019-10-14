#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1715318708/Rakete.o \
	${OBJECTDIR}/_ext/1715318708/Tank.o \
	${OBJECTDIR}/_ext/1715318708/Triebwerk.o \
	${OBJECTDIR}/_ext/1715318708/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/raketenl_sung_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/raketenl_sung_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/raketenl_sung_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1715318708/Rakete.o: ../../Dropbox/huth/Rakete.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1715318708
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1715318708/Rakete.o ../../Dropbox/huth/Rakete.cpp

${OBJECTDIR}/_ext/1715318708/Tank.o: ../../Dropbox/huth/Tank.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1715318708
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1715318708/Tank.o ../../Dropbox/huth/Tank.cpp

${OBJECTDIR}/_ext/1715318708/Triebwerk.o: ../../Dropbox/huth/Triebwerk.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1715318708
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1715318708/Triebwerk.o ../../Dropbox/huth/Triebwerk.cpp

${OBJECTDIR}/_ext/1715318708/main.o: ../../Dropbox/huth/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1715318708
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1715318708/main.o ../../Dropbox/huth/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/raketenl_sung_1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
