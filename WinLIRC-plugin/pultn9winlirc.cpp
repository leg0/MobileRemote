#include "pch.h"
#include "pultn9winlirc.h"

class Server
{
public:

    Server(HANDLE exitEvent)
        : exitEvent_(exitEvent)
        , readEvent_(WSACreateEvent())
        , sock_(SOCKET_ERROR)
    { }

    ~Server()
    {
        if (sock_ != SOCKET_ERROR)
        {
            closesocket(sock_);
        }

        if (readEvent_ != INVALID_HANDLE_VALUE)
        {
            CloseHandle(readEvent_);
        }
    }

    int init()
    {
        WSADATA data;
        if (WSAStartup(MAKEWORD(2, 0), &data))
        {
            return 0;
        }
        else
        {
            sock_ = socket(AF_INET, SOCK_DGRAM, 0);
            if (sock_ == 0)
            {
                return 0;
            }
            else
            {
                sockaddr_in serv_addr;
                memset(&serv_addr, 0, sizeof(sockaddr_in));

                serv_addr.sin_family      = AF_INET;
                serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
                serv_addr.sin_port        = htons(9999);

                if (bind(sock_, reinterpret_cast<sockaddr*>(&serv_addr), sizeof(serv_addr)) == SOCKET_ERROR)
                {
                    //printf("failed bind\n");
                    return 0;
                }

                if (WSAEventSelect(sock_, readEvent_, FD_READ) == SOCKET_ERROR)
                {
                    deinit();
                    return 0;
                }
            }
        }
        return 1;
    }

    int decodeIR(char* out)
    {
        assert(out != nullptr);
        assert(exitEvent_ != INVALID_HANDLE_VALUE);
        assert(readEvent_ != INVALID_HANDLE_VALUE);
        assert(sock_ != SOCKET_ERROR);

        for (;;)
        {
            HANDLE const h[] = { exitEvent_, readEvent_ };
            switch (WaitForMultipleObjects(2, h, FALSE, INFINITE))
            {
            default:
                // no break
            case WAIT_OBJECT_0:
                return 0;

            case WAIT_OBJECT_0+1:
                {
                    char buffer[256] = {0};
                    int const numberOfBytes = recvfrom(sock_, buffer, sizeof(buffer)-1, 0, nullptr, nullptr);
                    int res = 0;
                    if (numberOfBytes > 0)
                    {
                        // copy received data with terminating zero
                        memcpy(out, buffer, numberOfBytes+1);
                        res = 1;
                    }

                    // purge any remaining events
                    WSANETWORKEVENTS networkEvent;
                    WSAEnumNetworkEvents(sock_, readEvent_, &networkEvent);

                    if (res)
                    {
                        return res;
                    }
                }
            }
        }
    }
private:

    HANDLE exitEvent_;
    HANDLE readEvent_;
    SOCKET sock_;
};

static Server* svr = nullptr;

int init(HANDLE exitEvent)
{
    if (exitEvent != INVALID_HANDLE_VALUE)
    {
        delete svr;
        svr = new Server(exitEvent);
        return svr->init();
    }
    else
    {
        return 0;
    }
}

void deinit()
{
    delete svr;
    svr = nullptr;
}

int hasGui()
{
    return 0;
}

void loadSetupGui()
{ }

int sendIR(ir_remote*, ir_ncode*, int)
{
    return 0;
}

int decodeIR(ir_remote*, char* out)
{
    if (svr == nullptr || out == nullptr)
    {
        return 0;
    }
    else
    {
        return svr->decodeIR(out);
    }
}

struct hardware* getHardware()
{
    return nullptr;
}
