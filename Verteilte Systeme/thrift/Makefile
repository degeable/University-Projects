GEN_SRC := getDataService.cpp getDataService_constants.cpp getDataService_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR) 

.PHONY: all clean

all: getDataService_server Thrift_client

%.o: %.cpp $(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

getDataService_server: getDataService_server.o $(GEN_OBJ) $(CXX) $^ -o $@ -L/usr/local/lib -lthrift -lstdc++

Thrift_client: Thrift_client.o $(GEN_OBJ) $(CXX) $^ -o $@ -L/usr/local/lib -lthrift -lstdc++

clean: $(RM) *.o getDataService_server Thrift_client


