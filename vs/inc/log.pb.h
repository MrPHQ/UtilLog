// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#ifndef PROTOBUF_log_2eproto__INCLUDED
#define PROTOBUF_log_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace UTIL_LOG {
class MsgLogContent;
class MsgLogContentDefaultTypeInternal;
extern MsgLogContentDefaultTypeInternal _MsgLogContent_default_instance_;
class MsgLogControl;
class MsgLogControlDefaultTypeInternal;
extern MsgLogControlDefaultTypeInternal _MsgLogControl_default_instance_;
class MsgLogFile;
class MsgLogFileDefaultTypeInternal;
extern MsgLogFileDefaultTypeInternal _MsgLogFile_default_instance_;
}  // namespace UTIL_LOG

namespace UTIL_LOG {

namespace protobuf_log_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_log_2eproto

enum MsgLogControl_CmdType {
  MsgLogControl_CmdType_CMD_TYPE_NONE = 0,
  MsgLogControl_CmdType_CMD_TYPE_NEW_LOG = 1,
  MsgLogControl_CmdType_MsgLogControl_CmdType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MsgLogControl_CmdType_MsgLogControl_CmdType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MsgLogControl_CmdType_IsValid(int value);
const MsgLogControl_CmdType MsgLogControl_CmdType_CmdType_MIN = MsgLogControl_CmdType_CMD_TYPE_NONE;
const MsgLogControl_CmdType MsgLogControl_CmdType_CmdType_MAX = MsgLogControl_CmdType_CMD_TYPE_NEW_LOG;
const int MsgLogControl_CmdType_CmdType_ARRAYSIZE = MsgLogControl_CmdType_CmdType_MAX + 1;

const ::google::protobuf::EnumDescriptor* MsgLogControl_CmdType_descriptor();
inline const ::std::string& MsgLogControl_CmdType_Name(MsgLogControl_CmdType value) {
  return ::google::protobuf::internal::NameOfEnum(
    MsgLogControl_CmdType_descriptor(), value);
}
inline bool MsgLogControl_CmdType_Parse(
    const ::std::string& name, MsgLogControl_CmdType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgLogControl_CmdType>(
    MsgLogControl_CmdType_descriptor(), name, value);
}
// ===================================================================

class MsgLogFile : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UTIL_LOG.MsgLogFile) */ {
 public:
  MsgLogFile();
  virtual ~MsgLogFile();

  MsgLogFile(const MsgLogFile& from);

  inline MsgLogFile& operator=(const MsgLogFile& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgLogFile(MsgLogFile&& from) noexcept
    : MsgLogFile() {
    *this = ::std::move(from);
  }

  inline MsgLogFile& operator=(MsgLogFile&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgLogFile& default_instance();

  static inline const MsgLogFile* internal_default_instance() {
    return reinterpret_cast<const MsgLogFile*>(
               &_MsgLogFile_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MsgLogFile* other);
  friend void swap(MsgLogFile& a, MsgLogFile& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgLogFile* New() const PROTOBUF_FINAL { return New(NULL); }

  MsgLogFile* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MsgLogFile& from);
  void MergeFrom(const MsgLogFile& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MsgLogFile* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string File = 2;
  void clear_file();
  static const int kFileFieldNumber = 2;
  const ::std::string& file() const;
  void set_file(const ::std::string& value);
  #if LANG_CXX11
  void set_file(::std::string&& value);
  #endif
  void set_file(const char* value);
  void set_file(const char* value, size_t size);
  ::std::string* mutable_file();
  ::std::string* release_file();
  void set_allocated_file(::std::string* file);

  // uint32 HeadMode = 1;
  void clear_headmode();
  static const int kHeadModeFieldNumber = 1;
  ::google::protobuf::uint32 headmode() const;
  void set_headmode(::google::protobuf::uint32 value);

  // uint32 Day = 3;
  void clear_day();
  static const int kDayFieldNumber = 3;
  ::google::protobuf::uint32 day() const;
  void set_day(::google::protobuf::uint32 value);

  // uint32 Size = 4;
  void clear_size();
  static const int kSizeFieldNumber = 4;
  ::google::protobuf::uint32 size() const;
  void set_size(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:UTIL_LOG.MsgLogFile)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr file_;
  ::google::protobuf::uint32 headmode_;
  ::google::protobuf::uint32 day_;
  ::google::protobuf::uint32 size_;
  mutable int _cached_size_;
  friend struct protobuf_log_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgLogContent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UTIL_LOG.MsgLogContent) */ {
 public:
  MsgLogContent();
  virtual ~MsgLogContent();

  MsgLogContent(const MsgLogContent& from);

  inline MsgLogContent& operator=(const MsgLogContent& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgLogContent(MsgLogContent&& from) noexcept
    : MsgLogContent() {
    *this = ::std::move(from);
  }

  inline MsgLogContent& operator=(MsgLogContent&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgLogContent& default_instance();

  static inline const MsgLogContent* internal_default_instance() {
    return reinterpret_cast<const MsgLogContent*>(
               &_MsgLogContent_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(MsgLogContent* other);
  friend void swap(MsgLogContent& a, MsgLogContent& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgLogContent* New() const PROTOBUF_FINAL { return New(NULL); }

  MsgLogContent* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MsgLogContent& from);
  void MergeFrom(const MsgLogContent& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MsgLogContent* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string File = 1;
  void clear_file();
  static const int kFileFieldNumber = 1;
  const ::std::string& file() const;
  void set_file(const ::std::string& value);
  #if LANG_CXX11
  void set_file(::std::string&& value);
  #endif
  void set_file(const char* value);
  void set_file(const char* value, size_t size);
  ::std::string* mutable_file();
  ::std::string* release_file();
  void set_allocated_file(::std::string* file);

  // string Content = 2;
  void clear_content();
  static const int kContentFieldNumber = 2;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // @@protoc_insertion_point(class_scope:UTIL_LOG.MsgLogContent)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr file_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  mutable int _cached_size_;
  friend struct protobuf_log_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgLogControl : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UTIL_LOG.MsgLogControl) */ {
 public:
  MsgLogControl();
  virtual ~MsgLogControl();

  MsgLogControl(const MsgLogControl& from);

  inline MsgLogControl& operator=(const MsgLogControl& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgLogControl(MsgLogControl&& from) noexcept
    : MsgLogControl() {
    *this = ::std::move(from);
  }

  inline MsgLogControl& operator=(MsgLogControl&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgLogControl& default_instance();

  static inline const MsgLogControl* internal_default_instance() {
    return reinterpret_cast<const MsgLogControl*>(
               &_MsgLogControl_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(MsgLogControl* other);
  friend void swap(MsgLogControl& a, MsgLogControl& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgLogControl* New() const PROTOBUF_FINAL { return New(NULL); }

  MsgLogControl* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MsgLogControl& from);
  void MergeFrom(const MsgLogControl& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MsgLogControl* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef MsgLogControl_CmdType CmdType;
  static const CmdType CMD_TYPE_NONE =
    MsgLogControl_CmdType_CMD_TYPE_NONE;
  static const CmdType CMD_TYPE_NEW_LOG =
    MsgLogControl_CmdType_CMD_TYPE_NEW_LOG;
  static inline bool CmdType_IsValid(int value) {
    return MsgLogControl_CmdType_IsValid(value);
  }
  static const CmdType CmdType_MIN =
    MsgLogControl_CmdType_CmdType_MIN;
  static const CmdType CmdType_MAX =
    MsgLogControl_CmdType_CmdType_MAX;
  static const int CmdType_ARRAYSIZE =
    MsgLogControl_CmdType_CmdType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  CmdType_descriptor() {
    return MsgLogControl_CmdType_descriptor();
  }
  static inline const ::std::string& CmdType_Name(CmdType value) {
    return MsgLogControl_CmdType_Name(value);
  }
  static inline bool CmdType_Parse(const ::std::string& name,
      CmdType* value) {
    return MsgLogControl_CmdType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // bytes Data = 4;
  void clear_data();
  static const int kDataFieldNumber = 4;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // .UTIL_LOG.MsgLogControl.CmdType Cmd = 1;
  void clear_cmd();
  static const int kCmdFieldNumber = 1;
  ::UTIL_LOG::MsgLogControl_CmdType cmd() const;
  void set_cmd(::UTIL_LOG::MsgLogControl_CmdType value);

  // uint32 CmdFlag = 2;
  void clear_cmdflag();
  static const int kCmdFlagFieldNumber = 2;
  ::google::protobuf::uint32 cmdflag() const;
  void set_cmdflag(::google::protobuf::uint32 value);

  // uint32 Timestamp = 3;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 3;
  ::google::protobuf::uint32 timestamp() const;
  void set_timestamp(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:UTIL_LOG.MsgLogControl)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  int cmd_;
  ::google::protobuf::uint32 cmdflag_;
  ::google::protobuf::uint32 timestamp_;
  mutable int _cached_size_;
  friend struct protobuf_log_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MsgLogFile

// uint32 HeadMode = 1;
inline void MsgLogFile::clear_headmode() {
  headmode_ = 0u;
}
inline ::google::protobuf::uint32 MsgLogFile::headmode() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogFile.HeadMode)
  return headmode_;
}
inline void MsgLogFile::set_headmode(::google::protobuf::uint32 value) {
  
  headmode_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogFile.HeadMode)
}

// string File = 2;
inline void MsgLogFile::clear_file() {
  file_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgLogFile::file() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogFile.File)
  return file_.GetNoArena();
}
inline void MsgLogFile::set_file(const ::std::string& value) {
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogFile.File)
}
#if LANG_CXX11
inline void MsgLogFile::set_file(::std::string&& value) {
  
  file_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:UTIL_LOG.MsgLogFile.File)
}
#endif
inline void MsgLogFile::set_file(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UTIL_LOG.MsgLogFile.File)
}
inline void MsgLogFile::set_file(const char* value, size_t size) {
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UTIL_LOG.MsgLogFile.File)
}
inline ::std::string* MsgLogFile::mutable_file() {
  
  // @@protoc_insertion_point(field_mutable:UTIL_LOG.MsgLogFile.File)
  return file_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgLogFile::release_file() {
  // @@protoc_insertion_point(field_release:UTIL_LOG.MsgLogFile.File)
  
  return file_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgLogFile::set_allocated_file(::std::string* file) {
  if (file != NULL) {
    
  } else {
    
  }
  file_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), file);
  // @@protoc_insertion_point(field_set_allocated:UTIL_LOG.MsgLogFile.File)
}

// uint32 Day = 3;
inline void MsgLogFile::clear_day() {
  day_ = 0u;
}
inline ::google::protobuf::uint32 MsgLogFile::day() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogFile.Day)
  return day_;
}
inline void MsgLogFile::set_day(::google::protobuf::uint32 value) {
  
  day_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogFile.Day)
}

// uint32 Size = 4;
inline void MsgLogFile::clear_size() {
  size_ = 0u;
}
inline ::google::protobuf::uint32 MsgLogFile::size() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogFile.Size)
  return size_;
}
inline void MsgLogFile::set_size(::google::protobuf::uint32 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogFile.Size)
}

// -------------------------------------------------------------------

// MsgLogContent

// string File = 1;
inline void MsgLogContent::clear_file() {
  file_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgLogContent::file() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogContent.File)
  return file_.GetNoArena();
}
inline void MsgLogContent::set_file(const ::std::string& value) {
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogContent.File)
}
#if LANG_CXX11
inline void MsgLogContent::set_file(::std::string&& value) {
  
  file_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:UTIL_LOG.MsgLogContent.File)
}
#endif
inline void MsgLogContent::set_file(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UTIL_LOG.MsgLogContent.File)
}
inline void MsgLogContent::set_file(const char* value, size_t size) {
  
  file_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UTIL_LOG.MsgLogContent.File)
}
inline ::std::string* MsgLogContent::mutable_file() {
  
  // @@protoc_insertion_point(field_mutable:UTIL_LOG.MsgLogContent.File)
  return file_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgLogContent::release_file() {
  // @@protoc_insertion_point(field_release:UTIL_LOG.MsgLogContent.File)
  
  return file_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgLogContent::set_allocated_file(::std::string* file) {
  if (file != NULL) {
    
  } else {
    
  }
  file_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), file);
  // @@protoc_insertion_point(field_set_allocated:UTIL_LOG.MsgLogContent.File)
}

// string Content = 2;
inline void MsgLogContent::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgLogContent::content() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogContent.Content)
  return content_.GetNoArena();
}
inline void MsgLogContent::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogContent.Content)
}
#if LANG_CXX11
inline void MsgLogContent::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:UTIL_LOG.MsgLogContent.Content)
}
#endif
inline void MsgLogContent::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UTIL_LOG.MsgLogContent.Content)
}
inline void MsgLogContent::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UTIL_LOG.MsgLogContent.Content)
}
inline ::std::string* MsgLogContent::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:UTIL_LOG.MsgLogContent.Content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgLogContent::release_content() {
  // @@protoc_insertion_point(field_release:UTIL_LOG.MsgLogContent.Content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgLogContent::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:UTIL_LOG.MsgLogContent.Content)
}

// -------------------------------------------------------------------

// MsgLogControl

// .UTIL_LOG.MsgLogControl.CmdType Cmd = 1;
inline void MsgLogControl::clear_cmd() {
  cmd_ = 0;
}
inline ::UTIL_LOG::MsgLogControl_CmdType MsgLogControl::cmd() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogControl.Cmd)
  return static_cast< ::UTIL_LOG::MsgLogControl_CmdType >(cmd_);
}
inline void MsgLogControl::set_cmd(::UTIL_LOG::MsgLogControl_CmdType value) {
  
  cmd_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogControl.Cmd)
}

// uint32 CmdFlag = 2;
inline void MsgLogControl::clear_cmdflag() {
  cmdflag_ = 0u;
}
inline ::google::protobuf::uint32 MsgLogControl::cmdflag() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogControl.CmdFlag)
  return cmdflag_;
}
inline void MsgLogControl::set_cmdflag(::google::protobuf::uint32 value) {
  
  cmdflag_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogControl.CmdFlag)
}

// uint32 Timestamp = 3;
inline void MsgLogControl::clear_timestamp() {
  timestamp_ = 0u;
}
inline ::google::protobuf::uint32 MsgLogControl::timestamp() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogControl.Timestamp)
  return timestamp_;
}
inline void MsgLogControl::set_timestamp(::google::protobuf::uint32 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogControl.Timestamp)
}

// bytes Data = 4;
inline void MsgLogControl::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgLogControl::data() const {
  // @@protoc_insertion_point(field_get:UTIL_LOG.MsgLogControl.Data)
  return data_.GetNoArena();
}
inline void MsgLogControl::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UTIL_LOG.MsgLogControl.Data)
}
#if LANG_CXX11
inline void MsgLogControl::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:UTIL_LOG.MsgLogControl.Data)
}
#endif
inline void MsgLogControl::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UTIL_LOG.MsgLogControl.Data)
}
inline void MsgLogControl::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UTIL_LOG.MsgLogControl.Data)
}
inline ::std::string* MsgLogControl::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:UTIL_LOG.MsgLogControl.Data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgLogControl::release_data() {
  // @@protoc_insertion_point(field_release:UTIL_LOG.MsgLogControl.Data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgLogControl::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:UTIL_LOG.MsgLogControl.Data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace UTIL_LOG

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::UTIL_LOG::MsgLogControl_CmdType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::UTIL_LOG::MsgLogControl_CmdType>() {
  return ::UTIL_LOG::MsgLogControl_CmdType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_log_2eproto__INCLUDED
