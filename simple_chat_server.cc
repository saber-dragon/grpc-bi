#include <iostream>
#include <string>
#include <memory>

#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "simple_chat.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;

using simplechat::Msg;
using simplechat::SimpleChat;

#define BUF_SIZE 1024

class SimpleChatImpl final : public SimpleChat::Service {
   public:
    explicit SimpleChatImpl() {}
    Status Say(ServerContext* context,
               ServerReaderWriter<Msg, Msg>* stream) override {
        Msg msg;
		
		int flag = fcntl(STDIN_FILENO, F_GETFL, 0);
        flag |= O_NONBLOCK;
        fcntl(STDIN_FILENO, F_SETFL, flag);

        fd_set read_fds;
        
        char read_buf[BUF_SIZE];
        while (1) {
            // build fd_sets
            FD_ZERO(&read_fds);
            FD_SET(STDIN_FILENO, &read_fds);

            int ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, NULL);
            switch (ret) {
                case -1:
                    perror("select()");
                    exit(EXIT_FAILURE);
                case 0:
                    // should not reached
                    std::cout << "select() return 0.\n";
                    exit(EXIT_FAILURE);
                default:
                    memset(read_buf, 0, BUF_SIZE);
                    int nread = 0, ntotal = 0;
                    do {
                        read(STDIN_FILENO, &read_buf, BUF_SIZE);
                        if (nread < 0) {
                            perror("read()");
                            exit(EXIT_FAILURE);
                        } else {
                            ntotal += nread;
                            if (ntotal > BUF_SIZE) {
                                fprintf(stderr, "Message too large\n");
                                fflush(STDIN_FILENO);
                                break;
                            }
                        }
                    } while (nread > 0);
            }

            size_t len = strlen(read_buf);
            if ( len > 0 && read_buf[len - 1] == '\n' )
                read_buf[len - 1] = '\0';

            Msg msg_ts;
            msg_ts.set_msg(std::string(read_buf));
            stream->Write(msg_ts);
            //stream->WritesDone();
			while (stream->Read(&msg)) {
                if (msg.msg() == "I am coming") std::cout << "Client is up, Now you can send any message to he/she\n\n\n\n" << std::endl;
				else std::cout << "\t" << msg.msg() << std::endl;
            }

        }
        return Status::OK;
    }
};


int 
main(int argc, char *argv[]){
    std::string server_addr("0.0.0.0:50051");
    SimpleChatImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << server_addr << std::endl;
    std::cout << "\n\n\n" << std::endl;

    server->Wait();

    return 0;
}
