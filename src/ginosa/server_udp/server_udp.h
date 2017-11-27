#ifndef PROJECT_SERVER_UDP_H
#define PROJECT_SERVER_UDP_H


typedef struct server_udp {
  unsigned short int port;
  unsigned short int maxMessageSize;

  struct sockaddr_in* si_me;
  struct sockaddr_in* si_other;
  int s;
  int* slen;
  int recv_len;
  void* other;

  void (*listenConnections) (struct server_udp *);
  char* (*onMessageReceived)(char* fromAddress, unsigned short int port, char* message, void* other);
  void (*closeConnection)(struct server_udp*);
} server_udp;

server_udp* _new_server_udp(
  unsigned short int port,
  unsigned short int maxMessageSize,
  char* (*onMessageReceived)(char*, unsigned short int, char*, void*),
  void* onMessageReceivedArgs
);

#endif