
#include "host2ip.h"


struct in_addr host2ip(char *host)
{
    struct in_addr in, tmp;
    struct hostent *hep;

    /* Strip leading white space. */
    if (host) {
        while (*host && isspace((int)*host))
            host++;
    }

    /* Check whether this is a dotted decimal. */
    if (!host) {
        in.s_addr = INADDR_ANY;
    }
    else if ((tmp.s_addr = inet_addr(host)) != -1) {
        in = tmp;
    }
    /* Attempt to resolve host name via DNS. */
    else if ((hep = gethostbyname(host)))
    {
        in = *(struct in_addr *)(hep->h_addr_list[0]);
    }
    else {
        // Not supporting YP on windows port.
        in.s_addr = INADDR_ANY;
    }
    return in;
}
