#!/usr/local/bin/thrift --gen cpp

namespace cpp Test

service getDataService {
  list<string> getData(1: string filename)
}
