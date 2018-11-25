// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef PROTOBUF_msg_2eproto__INCLUDED
#define PROTOBUF_msg_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace MY {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_msg_2eproto();
void protobuf_AssignDesc_msg_2eproto();
void protobuf_ShutdownFile_msg_2eproto();

class msg;

// ===================================================================

class msg : public ::google::protobuf::Message {
 public:
  msg();
  virtual ~msg();

  msg(const msg& from);

  inline msg& operator=(const msg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const msg& default_instance();

  void Swap(msg* other);

  // implements Message ----------------------------------------------

  msg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const msg& from);
  void MergeFrom(const msg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // required int32 type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // optional string name = 3;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 3;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional string role = 4;
  inline bool has_role() const;
  inline void clear_role();
  static const int kRoleFieldNumber = 4;
  inline const ::std::string& role() const;
  inline void set_role(const ::std::string& value);
  inline void set_role(const char* value);
  inline void set_role(const char* value, size_t size);
  inline ::std::string* mutable_role();
  inline ::std::string* release_role();
  inline void set_allocated_role(::std::string* role);

  // optional int32 error = 5;
  inline bool has_error() const;
  inline void clear_error();
  static const int kErrorFieldNumber = 5;
  inline ::google::protobuf::int32 error() const;
  inline void set_error(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:MY.msg)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_role();
  inline void clear_has_role();
  inline void set_has_error();
  inline void clear_has_error();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 type_;
  ::std::string* name_;
  ::std::string* role_;
  ::google::protobuf::int32 error_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_msg_2eproto();
  friend void protobuf_AssignDesc_msg_2eproto();
  friend void protobuf_ShutdownFile_msg_2eproto();

  void InitAsDefaultInstance();
  static msg* default_instance_;
};
// ===================================================================


// ===================================================================

// msg

// required int32 id = 1;
inline bool msg::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void msg::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void msg::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void msg::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 msg::id() const {
  return id_;
}
inline void msg::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// required int32 type = 2;
inline bool msg::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void msg::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void msg::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void msg::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 msg::type() const {
  return type_;
}
inline void msg::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// optional string name = 3;
inline bool msg::has_name() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void msg::set_has_name() {
  _has_bits_[0] |= 0x00000004u;
}
inline void msg::clear_has_name() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void msg::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& msg::name() const {
  return *name_;
}
inline void msg::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void msg::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void msg::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* msg::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* msg::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void msg::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string role = 4;
inline bool msg::has_role() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void msg::set_has_role() {
  _has_bits_[0] |= 0x00000008u;
}
inline void msg::clear_has_role() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void msg::clear_role() {
  if (role_ != &::google::protobuf::internal::kEmptyString) {
    role_->clear();
  }
  clear_has_role();
}
inline const ::std::string& msg::role() const {
  return *role_;
}
inline void msg::set_role(const ::std::string& value) {
  set_has_role();
  if (role_ == &::google::protobuf::internal::kEmptyString) {
    role_ = new ::std::string;
  }
  role_->assign(value);
}
inline void msg::set_role(const char* value) {
  set_has_role();
  if (role_ == &::google::protobuf::internal::kEmptyString) {
    role_ = new ::std::string;
  }
  role_->assign(value);
}
inline void msg::set_role(const char* value, size_t size) {
  set_has_role();
  if (role_ == &::google::protobuf::internal::kEmptyString) {
    role_ = new ::std::string;
  }
  role_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* msg::mutable_role() {
  set_has_role();
  if (role_ == &::google::protobuf::internal::kEmptyString) {
    role_ = new ::std::string;
  }
  return role_;
}
inline ::std::string* msg::release_role() {
  clear_has_role();
  if (role_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = role_;
    role_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void msg::set_allocated_role(::std::string* role) {
  if (role_ != &::google::protobuf::internal::kEmptyString) {
    delete role_;
  }
  if (role) {
    set_has_role();
    role_ = role;
  } else {
    clear_has_role();
    role_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 error = 5;
inline bool msg::has_error() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void msg::set_has_error() {
  _has_bits_[0] |= 0x00000010u;
}
inline void msg::clear_has_error() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void msg::clear_error() {
  error_ = 0;
  clear_has_error();
}
inline ::google::protobuf::int32 msg::error() const {
  return error_;
}
inline void msg::set_error(::google::protobuf::int32 value) {
  set_has_error();
  error_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace MY

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msg_2eproto__INCLUDED
