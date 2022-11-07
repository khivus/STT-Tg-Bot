// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/cloud/dialogflow/v2/validation_result.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021006 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto;
namespace google {
namespace cloud {
namespace dialogflow {
namespace v2 {
class ValidationError;
struct ValidationErrorDefaultTypeInternal;
extern ValidationErrorDefaultTypeInternal _ValidationError_default_instance_;
class ValidationResult;
struct ValidationResultDefaultTypeInternal;
extern ValidationResultDefaultTypeInternal _ValidationResult_default_instance_;
}  // namespace v2
}  // namespace dialogflow
}  // namespace cloud
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> ::google::cloud::dialogflow::v2::ValidationError* Arena::CreateMaybeMessage<::google::cloud::dialogflow::v2::ValidationError>(Arena*);
template<> ::google::cloud::dialogflow::v2::ValidationResult* Arena::CreateMaybeMessage<::google::cloud::dialogflow::v2::ValidationResult>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace google {
namespace cloud {
namespace dialogflow {
namespace v2 {

enum ValidationError_Severity : int {
  ValidationError_Severity_SEVERITY_UNSPECIFIED = 0,
  ValidationError_Severity_INFO = 1,
  ValidationError_Severity_WARNING = 2,
  ValidationError_Severity_ERROR = 3,
  ValidationError_Severity_CRITICAL = 4,
  ValidationError_Severity_ValidationError_Severity_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ValidationError_Severity_ValidationError_Severity_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ValidationError_Severity_IsValid(int value);
constexpr ValidationError_Severity ValidationError_Severity_Severity_MIN = ValidationError_Severity_SEVERITY_UNSPECIFIED;
constexpr ValidationError_Severity ValidationError_Severity_Severity_MAX = ValidationError_Severity_CRITICAL;
constexpr int ValidationError_Severity_Severity_ARRAYSIZE = ValidationError_Severity_Severity_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ValidationError_Severity_descriptor();
template<typename T>
inline const std::string& ValidationError_Severity_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ValidationError_Severity>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ValidationError_Severity_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ValidationError_Severity_descriptor(), enum_t_value);
}
inline bool ValidationError_Severity_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ValidationError_Severity* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ValidationError_Severity>(
    ValidationError_Severity_descriptor(), name, value);
}
// ===================================================================

class ValidationError final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.cloud.dialogflow.v2.ValidationError) */ {
 public:
  inline ValidationError() : ValidationError(nullptr) {}
  ~ValidationError() override;
  explicit PROTOBUF_CONSTEXPR ValidationError(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ValidationError(const ValidationError& from);
  ValidationError(ValidationError&& from) noexcept
    : ValidationError() {
    *this = ::std::move(from);
  }

  inline ValidationError& operator=(const ValidationError& from) {
    CopyFrom(from);
    return *this;
  }
  inline ValidationError& operator=(ValidationError&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ValidationError& default_instance() {
    return *internal_default_instance();
  }
  static inline const ValidationError* internal_default_instance() {
    return reinterpret_cast<const ValidationError*>(
               &_ValidationError_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ValidationError& a, ValidationError& b) {
    a.Swap(&b);
  }
  inline void Swap(ValidationError* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ValidationError* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ValidationError* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ValidationError>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ValidationError& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ValidationError& from) {
    ValidationError::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ValidationError* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.cloud.dialogflow.v2.ValidationError";
  }
  protected:
  explicit ValidationError(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef ValidationError_Severity Severity;
  static constexpr Severity SEVERITY_UNSPECIFIED =
    ValidationError_Severity_SEVERITY_UNSPECIFIED;
  static constexpr Severity INFO =
    ValidationError_Severity_INFO;
  static constexpr Severity WARNING =
    ValidationError_Severity_WARNING;
  static constexpr Severity ERROR =
    ValidationError_Severity_ERROR;
  static constexpr Severity CRITICAL =
    ValidationError_Severity_CRITICAL;
  static inline bool Severity_IsValid(int value) {
    return ValidationError_Severity_IsValid(value);
  }
  static constexpr Severity Severity_MIN =
    ValidationError_Severity_Severity_MIN;
  static constexpr Severity Severity_MAX =
    ValidationError_Severity_Severity_MAX;
  static constexpr int Severity_ARRAYSIZE =
    ValidationError_Severity_Severity_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Severity_descriptor() {
    return ValidationError_Severity_descriptor();
  }
  template<typename T>
  static inline const std::string& Severity_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Severity>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Severity_Name.");
    return ValidationError_Severity_Name(enum_t_value);
  }
  static inline bool Severity_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Severity* value) {
    return ValidationError_Severity_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kEntriesFieldNumber = 3,
    kErrorMessageFieldNumber = 4,
    kSeverityFieldNumber = 1,
  };
  // repeated string entries = 3;
  int entries_size() const;
  private:
  int _internal_entries_size() const;
  public:
  void clear_entries();
  const std::string& entries(int index) const;
  std::string* mutable_entries(int index);
  void set_entries(int index, const std::string& value);
  void set_entries(int index, std::string&& value);
  void set_entries(int index, const char* value);
  void set_entries(int index, const char* value, size_t size);
  std::string* add_entries();
  void add_entries(const std::string& value);
  void add_entries(std::string&& value);
  void add_entries(const char* value);
  void add_entries(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& entries() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_entries();
  private:
  const std::string& _internal_entries(int index) const;
  std::string* _internal_add_entries();
  public:

  // string error_message = 4;
  void clear_error_message();
  const std::string& error_message() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_error_message(ArgT0&& arg0, ArgT... args);
  std::string* mutable_error_message();
  PROTOBUF_NODISCARD std::string* release_error_message();
  void set_allocated_error_message(std::string* error_message);
  private:
  const std::string& _internal_error_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_error_message(const std::string& value);
  std::string* _internal_mutable_error_message();
  public:

  // .google.cloud.dialogflow.v2.ValidationError.Severity severity = 1;
  void clear_severity();
  ::google::cloud::dialogflow::v2::ValidationError_Severity severity() const;
  void set_severity(::google::cloud::dialogflow::v2::ValidationError_Severity value);
  private:
  ::google::cloud::dialogflow::v2::ValidationError_Severity _internal_severity() const;
  void _internal_set_severity(::google::cloud::dialogflow::v2::ValidationError_Severity value);
  public:

  // @@protoc_insertion_point(class_scope:google.cloud.dialogflow.v2.ValidationError)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> entries_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr error_message_;
    int severity_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto;
};
// -------------------------------------------------------------------

class ValidationResult final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.cloud.dialogflow.v2.ValidationResult) */ {
 public:
  inline ValidationResult() : ValidationResult(nullptr) {}
  ~ValidationResult() override;
  explicit PROTOBUF_CONSTEXPR ValidationResult(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ValidationResult(const ValidationResult& from);
  ValidationResult(ValidationResult&& from) noexcept
    : ValidationResult() {
    *this = ::std::move(from);
  }

  inline ValidationResult& operator=(const ValidationResult& from) {
    CopyFrom(from);
    return *this;
  }
  inline ValidationResult& operator=(ValidationResult&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ValidationResult& default_instance() {
    return *internal_default_instance();
  }
  static inline const ValidationResult* internal_default_instance() {
    return reinterpret_cast<const ValidationResult*>(
               &_ValidationResult_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ValidationResult& a, ValidationResult& b) {
    a.Swap(&b);
  }
  inline void Swap(ValidationResult* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ValidationResult* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ValidationResult* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ValidationResult>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ValidationResult& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ValidationResult& from) {
    ValidationResult::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ValidationResult* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.cloud.dialogflow.v2.ValidationResult";
  }
  protected:
  explicit ValidationResult(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValidationErrorsFieldNumber = 1,
  };
  // repeated .google.cloud.dialogflow.v2.ValidationError validation_errors = 1;
  int validation_errors_size() const;
  private:
  int _internal_validation_errors_size() const;
  public:
  void clear_validation_errors();
  ::google::cloud::dialogflow::v2::ValidationError* mutable_validation_errors(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::ValidationError >*
      mutable_validation_errors();
  private:
  const ::google::cloud::dialogflow::v2::ValidationError& _internal_validation_errors(int index) const;
  ::google::cloud::dialogflow::v2::ValidationError* _internal_add_validation_errors();
  public:
  const ::google::cloud::dialogflow::v2::ValidationError& validation_errors(int index) const;
  ::google::cloud::dialogflow::v2::ValidationError* add_validation_errors();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::ValidationError >&
      validation_errors() const;

  // @@protoc_insertion_point(class_scope:google.cloud.dialogflow.v2.ValidationResult)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::ValidationError > validation_errors_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ValidationError

// .google.cloud.dialogflow.v2.ValidationError.Severity severity = 1;
inline void ValidationError::clear_severity() {
  _impl_.severity_ = 0;
}
inline ::google::cloud::dialogflow::v2::ValidationError_Severity ValidationError::_internal_severity() const {
  return static_cast< ::google::cloud::dialogflow::v2::ValidationError_Severity >(_impl_.severity_);
}
inline ::google::cloud::dialogflow::v2::ValidationError_Severity ValidationError::severity() const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.ValidationError.severity)
  return _internal_severity();
}
inline void ValidationError::_internal_set_severity(::google::cloud::dialogflow::v2::ValidationError_Severity value) {
  
  _impl_.severity_ = value;
}
inline void ValidationError::set_severity(::google::cloud::dialogflow::v2::ValidationError_Severity value) {
  _internal_set_severity(value);
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.ValidationError.severity)
}

// repeated string entries = 3;
inline int ValidationError::_internal_entries_size() const {
  return _impl_.entries_.size();
}
inline int ValidationError::entries_size() const {
  return _internal_entries_size();
}
inline void ValidationError::clear_entries() {
  _impl_.entries_.Clear();
}
inline std::string* ValidationError::add_entries() {
  std::string* _s = _internal_add_entries();
  // @@protoc_insertion_point(field_add_mutable:google.cloud.dialogflow.v2.ValidationError.entries)
  return _s;
}
inline const std::string& ValidationError::_internal_entries(int index) const {
  return _impl_.entries_.Get(index);
}
inline const std::string& ValidationError::entries(int index) const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.ValidationError.entries)
  return _internal_entries(index);
}
inline std::string* ValidationError::mutable_entries(int index) {
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.ValidationError.entries)
  return _impl_.entries_.Mutable(index);
}
inline void ValidationError::set_entries(int index, const std::string& value) {
  _impl_.entries_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::set_entries(int index, std::string&& value) {
  _impl_.entries_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::set_entries(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.entries_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::set_entries(int index, const char* value, size_t size) {
  _impl_.entries_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline std::string* ValidationError::_internal_add_entries() {
  return _impl_.entries_.Add();
}
inline void ValidationError::add_entries(const std::string& value) {
  _impl_.entries_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::add_entries(std::string&& value) {
  _impl_.entries_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::add_entries(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.entries_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline void ValidationError::add_entries(const char* value, size_t size) {
  _impl_.entries_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.cloud.dialogflow.v2.ValidationError.entries)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
ValidationError::entries() const {
  // @@protoc_insertion_point(field_list:google.cloud.dialogflow.v2.ValidationError.entries)
  return _impl_.entries_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
ValidationError::mutable_entries() {
  // @@protoc_insertion_point(field_mutable_list:google.cloud.dialogflow.v2.ValidationError.entries)
  return &_impl_.entries_;
}

// string error_message = 4;
inline void ValidationError::clear_error_message() {
  _impl_.error_message_.ClearToEmpty();
}
inline const std::string& ValidationError::error_message() const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.ValidationError.error_message)
  return _internal_error_message();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ValidationError::set_error_message(ArgT0&& arg0, ArgT... args) {
 
 _impl_.error_message_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.ValidationError.error_message)
}
inline std::string* ValidationError::mutable_error_message() {
  std::string* _s = _internal_mutable_error_message();
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.ValidationError.error_message)
  return _s;
}
inline const std::string& ValidationError::_internal_error_message() const {
  return _impl_.error_message_.Get();
}
inline void ValidationError::_internal_set_error_message(const std::string& value) {
  
  _impl_.error_message_.Set(value, GetArenaForAllocation());
}
inline std::string* ValidationError::_internal_mutable_error_message() {
  
  return _impl_.error_message_.Mutable(GetArenaForAllocation());
}
inline std::string* ValidationError::release_error_message() {
  // @@protoc_insertion_point(field_release:google.cloud.dialogflow.v2.ValidationError.error_message)
  return _impl_.error_message_.Release();
}
inline void ValidationError::set_allocated_error_message(std::string* error_message) {
  if (error_message != nullptr) {
    
  } else {
    
  }
  _impl_.error_message_.SetAllocated(error_message, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.error_message_.IsDefault()) {
    _impl_.error_message_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:google.cloud.dialogflow.v2.ValidationError.error_message)
}

// -------------------------------------------------------------------

// ValidationResult

// repeated .google.cloud.dialogflow.v2.ValidationError validation_errors = 1;
inline int ValidationResult::_internal_validation_errors_size() const {
  return _impl_.validation_errors_.size();
}
inline int ValidationResult::validation_errors_size() const {
  return _internal_validation_errors_size();
}
inline void ValidationResult::clear_validation_errors() {
  _impl_.validation_errors_.Clear();
}
inline ::google::cloud::dialogflow::v2::ValidationError* ValidationResult::mutable_validation_errors(int index) {
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.ValidationResult.validation_errors)
  return _impl_.validation_errors_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::ValidationError >*
ValidationResult::mutable_validation_errors() {
  // @@protoc_insertion_point(field_mutable_list:google.cloud.dialogflow.v2.ValidationResult.validation_errors)
  return &_impl_.validation_errors_;
}
inline const ::google::cloud::dialogflow::v2::ValidationError& ValidationResult::_internal_validation_errors(int index) const {
  return _impl_.validation_errors_.Get(index);
}
inline const ::google::cloud::dialogflow::v2::ValidationError& ValidationResult::validation_errors(int index) const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.ValidationResult.validation_errors)
  return _internal_validation_errors(index);
}
inline ::google::cloud::dialogflow::v2::ValidationError* ValidationResult::_internal_add_validation_errors() {
  return _impl_.validation_errors_.Add();
}
inline ::google::cloud::dialogflow::v2::ValidationError* ValidationResult::add_validation_errors() {
  ::google::cloud::dialogflow::v2::ValidationError* _add = _internal_add_validation_errors();
  // @@protoc_insertion_point(field_add:google.cloud.dialogflow.v2.ValidationResult.validation_errors)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::ValidationError >&
ValidationResult::validation_errors() const {
  // @@protoc_insertion_point(field_list:google.cloud.dialogflow.v2.ValidationResult.validation_errors)
  return _impl_.validation_errors_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v2
}  // namespace dialogflow
}  // namespace cloud
}  // namespace google

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::google::cloud::dialogflow::v2::ValidationError_Severity> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::google::cloud::dialogflow::v2::ValidationError_Severity>() {
  return ::google::cloud::dialogflow::v2::ValidationError_Severity_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fvalidation_5fresult_2eproto