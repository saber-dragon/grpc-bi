// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: simple_chat.proto
#ifndef GRPC_simple_5fchat_2eproto__INCLUDED
#define GRPC_simple_5fchat_2eproto__INCLUDED

#include "simple_chat.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace simplechat {

class SimpleChat final {
 public:
  static constexpr char const* service_full_name() {
    return "simplechat.SimpleChat";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>> Say(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>>(SayRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>> AsyncSay(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>>(AsyncSayRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>> PrepareAsyncSay(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>>(PrepareAsyncSayRaw(context, cq));
    }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>* SayRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>* AsyncSayRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::simplechat::Msg, ::simplechat::Msg>* PrepareAsyncSayRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::simplechat::Msg, ::simplechat::Msg>> Say(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::simplechat::Msg, ::simplechat::Msg>>(SayRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>> AsyncSay(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>>(AsyncSayRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>> PrepareAsyncSay(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>>(PrepareAsyncSayRaw(context, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* SayRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* AsyncSayRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* PrepareAsyncSayRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Say_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Say(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_Say : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Say() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Say() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Say(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSay(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Say<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Say : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Say() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Say() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Say(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::simplechat::Msg, ::simplechat::Msg>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace simplechat


#endif  // GRPC_simple_5fchat_2eproto__INCLUDED
