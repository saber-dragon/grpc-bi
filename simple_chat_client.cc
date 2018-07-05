#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "simple_chat.grpc.pb.h"



using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using simplechat::Msg;
using simplechat::SimpleChat;


class SimpleChatClient {
    public:
        SimpleChatClient(std::shared_ptr<Channel> channel):
            stub_(SimpleChat::NewStub(channel)), connected_(false){

            }

        void Say() {
            ClientContext context;

            std::shared_ptr<ClientReaderWriter<Msg, Msg> > stream(stub_->Say(&context));

            std::thread writer([this, stream](){
                    std::string s;
                    
                    if ( this->connected_ ) std::cin >> s;
                    else {
						s = "I am coming";
                        this->connected_ = true;
                        }

                    Msg msg_ts;
                    msg_ts.set_msg(s);

                    stream->Write(msg_ts);

                    stream->WritesDone();
                    });

            Msg msg;
            if ( stream->Read(&msg) ) {
                std::cout << "\t" << msg.msg() << std::endl;
            }

            writer.join();

            Status status = stream->Finish();

            if ( !status.ok() ) {
                std::cout << "rpc failed." << std::endl;
            }
        }
    private:
        std::unique_ptr<SimpleChat::Stub> stub_;
		bool connected_;
};


int
main(int argc, char *argv[])
{
    SimpleChatClient scc(grpc::CreateChannel("localhost:50051",
                grpc::InsecureChannelCredentials()));

    
	while(1)
        scc.Say();

    return 0;
}
