#ifdef _WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

extern struct in_addr host2ip(char *host);
