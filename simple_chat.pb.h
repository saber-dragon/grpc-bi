// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simple_chat.proto

#ifndef PROTOBUF_INCLUDED_simple_5fchat_2eproto
#define PROTOBUF_INCLUDED_simple_5fchat_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_simple_5fchat_2eproto 

namespace protobuf_simple_5fchat_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_simple_5fchat_2eproto
namespace simplechat {
class Msg;
class MsgDefaultTypeInternal;
extern MsgDefaultTypeInternal _Msg_default_instance_;
}  // namespace simplechat
namespace google {
namespace protobuf {
template<> ::simplechat::Msg* Arena::CreateMaybeMessage<::simplechat::Msg>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace simplechat {

// ===================================================================

class Msg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:simplechat.Msg) */ {
 public:
  Msg();
  virtual ~Msg();

  Msg(const Msg& from);

  inline Msg& operator=(const Msg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Msg(Msg&& from) noexcept
    : Msg() {
    *this = ::std::move(from);
  }

  inline Msg& operator=(Msg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Msg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Msg* internal_default_instance() {
    return reinterpret_cast<const Msg*>(
               &_Msg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Msg* other);
  friend void swap(Msg& a, Msg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Msg* New() const final {
    return CreateMaybeMessage<Msg>(NULL);
  }

  Msg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Msg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Msg& from);
  void MergeFrom(const Msg& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Msg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string msg = 1;
  void clear_msg();
  static const int kMsgFieldNumber = 1;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_msg(::std::string&& value);
  #endif
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:simplechat.Msg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_simple_5fchat_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Msg

// string msg = 1;
inline void Msg::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Msg::msg() const {
  // @@protoc_insertion_point(field_get:simplechat.Msg.msg)
  return msg_.GetNoArena();
}
inline void Msg::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:simplechat.Msg.msg)
}
#if LANG_CXX11
inline void Msg::set_msg(::std::string&& value) {
  
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:simplechat.Msg.msg)
}
#endif
inline void Msg::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:simplechat.Msg.msg)
}
inline void Msg::set_msg(const char* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:simplechat.Msg.msg)
}
inline ::std::string* Msg::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:simplechat.Msg.msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Msg::release_msg() {
  // @@protoc_insertion_point(field_release:simplechat.Msg.msg)
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Msg::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:simplechat.Msg.msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace simplechat

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_simple_5fchat_2eproto