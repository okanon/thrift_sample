/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;


#if !SILVERLIGHT
[Serializable]
#endif
public partial class SampleException : TException, TBase
{
  private ErrorCode _code;
  private string _reason;

  /// <summary>
  /// 
  /// <seealso cref="ErrorCode"/>
  /// </summary>
  public ErrorCode Code
  {
    get
    {
      return _code;
    }
    set
    {
      __isset.code = true;
      this._code = value;
    }
  }

  public string Reason
  {
    get
    {
      return _reason;
    }
    set
    {
      __isset.reason = true;
      this._reason = value;
    }
  }


  public Isset __isset;
  #if !SILVERLIGHT
  [Serializable]
  #endif
  public struct Isset {
    public bool code;
    public bool reason;
  }

  public SampleException() {
  }

  public void Read (TProtocol iprot)
  {
    iprot.IncrementRecursionDepth();
    try
    {
      TField field;
      iprot.ReadStructBegin();
      while (true)
      {
        field = iprot.ReadFieldBegin();
        if (field.Type == TType.Stop) { 
          break;
        }
        switch (field.ID)
        {
          case 1:
            if (field.Type == TType.I32) {
              Code = (ErrorCode)iprot.ReadI32();
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          case 2:
            if (field.Type == TType.String) {
              Reason = iprot.ReadString();
            } else { 
              TProtocolUtil.Skip(iprot, field.Type);
            }
            break;
          default: 
            TProtocolUtil.Skip(iprot, field.Type);
            break;
        }
        iprot.ReadFieldEnd();
      }
      iprot.ReadStructEnd();
    }
    finally
    {
      iprot.DecrementRecursionDepth();
    }
  }

  public void Write(TProtocol oprot) {
    oprot.IncrementRecursionDepth();
    try
    {
      TStruct struc = new TStruct("SampleException");
      oprot.WriteStructBegin(struc);
      TField field = new TField();
      if (__isset.code) {
        field.Name = "code";
        field.Type = TType.I32;
        field.ID = 1;
        oprot.WriteFieldBegin(field);
        oprot.WriteI32((int)Code);
        oprot.WriteFieldEnd();
      }
      if (Reason != null && __isset.reason) {
        field.Name = "reason";
        field.Type = TType.String;
        field.ID = 2;
        oprot.WriteFieldBegin(field);
        oprot.WriteString(Reason);
        oprot.WriteFieldEnd();
      }
      oprot.WriteFieldStop();
      oprot.WriteStructEnd();
    }
    finally
    {
      oprot.DecrementRecursionDepth();
    }
  }

  public override string ToString() {
    StringBuilder __sb = new StringBuilder("SampleException(");
    bool __first = true;
    if (__isset.code) {
      if(!__first) { __sb.Append(", "); }
      __first = false;
      __sb.Append("Code: ");
      __sb.Append(Code);
    }
    if (Reason != null && __isset.reason) {
      if(!__first) { __sb.Append(", "); }
      __first = false;
      __sb.Append("Reason: ");
      __sb.Append(Reason);
    }
    __sb.Append(")");
    return __sb.ToString();
  }

}

