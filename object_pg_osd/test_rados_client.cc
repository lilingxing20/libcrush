#include <iostream>

#include "libcrush.h"

using namespace std;


int main() {
    librados::Rados rados;
    create_rados_client(rados, "/etc/ceph/ceph.conf", "ceph", "client.admin", 0);
    const struct crush_map *crushmap = rados.get_crushmap();
    std::cout << crushmap << std::endl;
    (void) crushmap;
    rados.put_crushmap();
    return 0;
}
