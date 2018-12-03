/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "sample_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>



int _kErrorCodeValues[] = {
  ErrorCode::ILLEGAL_ARGUMENT,
  ErrorCode::INVALID_IPADDR,
  ErrorCode::WINSOCK_FAILED,
  ErrorCode::INVALID_NUMERIC,
  ErrorCode::GENERATOR_FALIED
};
const char* _kErrorCodeNames[] = {
  "ILLEGAL_ARGUMENT",
  "INVALID_IPADDR",
  "WINSOCK_FAILED",
  "INVALID_NUMERIC",
  "GENERATOR_FALIED"
};
const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kErrorCodeValues, _kErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ErrorCode::type& val) {
  std::map<int, const char*>::const_iterator it = _ErrorCode_VALUES_TO_NAMES.find(val);
  if (it != _ErrorCode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


Calc::~Calc() throw() {
}


void Calc::__set_plus(const double val) {
  this->plus = val;
}

void Calc::__set_minus(const double val) {
  this->minus = val;
}

void Calc::__set_multiplies(const double val) {
  this->multiplies = val;
}

void Calc::__set_divides(const double val) {
  this->divides = val;
}
std::ostream& operator<<(std::ostream& out, const Calc& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Calc::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->plus);
          this->__isset.plus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->minus);
          this->__isset.minus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->multiplies);
          this->__isset.multiplies = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->divides);
          this->__isset.divides = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Calc::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Calc");

  xfer += oprot->writeFieldBegin("plus", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->plus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("minus", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->minus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("multiplies", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->multiplies);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("divides", ::apache::thrift::protocol::T_DOUBLE, 4);
  xfer += oprot->writeDouble(this->divides);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Calc &a, Calc &b) {
  using ::std::swap;
  swap(a.plus, b.plus);
  swap(a.minus, b.minus);
  swap(a.multiplies, b.multiplies);
  swap(a.divides, b.divides);
  swap(a.__isset, b.__isset);
}

Calc::Calc(const Calc& other0) {
  plus = other0.plus;
  minus = other0.minus;
  multiplies = other0.multiplies;
  divides = other0.divides;
  __isset = other0.__isset;
}
Calc& Calc::operator=(const Calc& other1) {
  plus = other1.plus;
  minus = other1.minus;
  multiplies = other1.multiplies;
  divides = other1.divides;
  __isset = other1.__isset;
  return *this;
}
void Calc::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Calc(";
  out << "plus=" << to_string(plus);
  out << ", " << "minus=" << to_string(minus);
  out << ", " << "multiplies=" << to_string(multiplies);
  out << ", " << "divides=" << to_string(divides);
  out << ")";
}


sampleException::~sampleException() throw() {
}


void sampleException::__set_code(const ErrorCode::type val) {
  this->code = val;
}

void sampleException::__set_reason(const std::string& val) {
  this->reason = val;
}
std::ostream& operator<<(std::ostream& out, const sampleException& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t sampleException::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast2;
          xfer += iprot->readI32(ecast2);
          this->code = (ErrorCode::type)ecast2;
          this->__isset.code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t sampleException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("sampleException");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->reason);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(sampleException &a, sampleException &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

sampleException::sampleException(const sampleException& other3) : TException() {
  code = other3.code;
  reason = other3.reason;
  __isset = other3.__isset;
}
sampleException& sampleException::operator=(const sampleException& other4) {
  code = other4.code;
  reason = other4.reason;
  __isset = other4.__isset;
  return *this;
}
void sampleException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "sampleException(";
  out << "code=" << to_string(code);
  out << ", " << "reason=" << to_string(reason);
  out << ")";
}

const char* sampleException::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: sampleException";
  }
}


