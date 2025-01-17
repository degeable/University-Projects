/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef getDataService_H
#define getDataService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "getDataService_types.h"

namespace Test {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class getDataServiceIf {
 public:
  virtual ~getDataServiceIf() {}
  virtual void getData(std::vector<std::string> & _return, const std::string& filename) = 0;
};

class getDataServiceIfFactory {
 public:
  typedef getDataServiceIf Handler;

  virtual ~getDataServiceIfFactory() {}

  virtual getDataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(getDataServiceIf* /* handler */) = 0;
};

class getDataServiceIfSingletonFactory : virtual public getDataServiceIfFactory {
 public:
  getDataServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<getDataServiceIf>& iface) : iface_(iface) {}
  virtual ~getDataServiceIfSingletonFactory() {}

  virtual getDataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(getDataServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<getDataServiceIf> iface_;
};

class getDataServiceNull : virtual public getDataServiceIf {
 public:
  virtual ~getDataServiceNull() {}
  void getData(std::vector<std::string> & /* _return */, const std::string& /* filename */) {
    return;
  }
};

typedef struct _getDataService_getData_args__isset {
  _getDataService_getData_args__isset() : filename(false) {}
  bool filename :1;
} _getDataService_getData_args__isset;

class getDataService_getData_args {
 public:

  getDataService_getData_args(const getDataService_getData_args&);
  getDataService_getData_args& operator=(const getDataService_getData_args&);
  getDataService_getData_args() : filename() {
  }

  virtual ~getDataService_getData_args() throw();
  std::string filename;

  _getDataService_getData_args__isset __isset;

  void __set_filename(const std::string& val);

  bool operator == (const getDataService_getData_args & rhs) const
  {
    if (!(filename == rhs.filename))
      return false;
    return true;
  }
  bool operator != (const getDataService_getData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const getDataService_getData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class getDataService_getData_pargs {
 public:


  virtual ~getDataService_getData_pargs() throw();
  const std::string* filename;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _getDataService_getData_result__isset {
  _getDataService_getData_result__isset() : success(false) {}
  bool success :1;
} _getDataService_getData_result__isset;

class getDataService_getData_result {
 public:

  getDataService_getData_result(const getDataService_getData_result&);
  getDataService_getData_result& operator=(const getDataService_getData_result&);
  getDataService_getData_result() {
  }

  virtual ~getDataService_getData_result() throw();
  std::vector<std::string>  success;

  _getDataService_getData_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  bool operator == (const getDataService_getData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const getDataService_getData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const getDataService_getData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _getDataService_getData_presult__isset {
  _getDataService_getData_presult__isset() : success(false) {}
  bool success :1;
} _getDataService_getData_presult__isset;

class getDataService_getData_presult {
 public:


  virtual ~getDataService_getData_presult() throw();
  std::vector<std::string> * success;

  _getDataService_getData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class getDataServiceClient : virtual public getDataServiceIf {
 public:
  getDataServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  getDataServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getData(std::vector<std::string> & _return, const std::string& filename);
  void send_getData(const std::string& filename);
  void recv_getData(std::vector<std::string> & _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class getDataServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<getDataServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (getDataServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  getDataServiceProcessor(::apache::thrift::stdcxx::shared_ptr<getDataServiceIf> iface) :
    iface_(iface) {
    processMap_["getData"] = &getDataServiceProcessor::process_getData;
  }

  virtual ~getDataServiceProcessor() {}
};

class getDataServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  getDataServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< getDataServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< getDataServiceIfFactory > handlerFactory_;
};

class getDataServiceMultiface : virtual public getDataServiceIf {
 public:
  getDataServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<getDataServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~getDataServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<getDataServiceIf> > ifaces_;
  getDataServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<getDataServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getData(std::vector<std::string> & _return, const std::string& filename) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getData(_return, filename);
    }
    ifaces_[i]->getData(_return, filename);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class getDataServiceConcurrentClient : virtual public getDataServiceIf {
 public:
  getDataServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  getDataServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getData(std::vector<std::string> & _return, const std::string& filename);
  int32_t send_getData(const std::string& filename);
  void recv_getData(std::vector<std::string> & _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
