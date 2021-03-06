SET(CMAKE_C_COMPILER avr-g++)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CWARN "-Wall")
SET(COPT "-O2 -lm -lprintf_flt -Wl,-u,vfprintf")
SET(CMCU "-fno-exceptions -mmcu=atmega2560")
SET(CDEFS "-DF_CPU=16000000L")


SET(CFLAGS "${CMCU} ${CDEFS} ${COPT} ${CWARN}")
SET(CXXFLAGS "${CMCU} ${CDEFS} ${COPT} ${CWARN}")
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
SET(CMAKE_EXE_LINK_CXX_FLAGS "--gc-sections")

SET(CMAKE_C_FLAGS  ${CFLAGS})
SET(CMAKE_CXX_FLAGS ${CXXFLAGS})
