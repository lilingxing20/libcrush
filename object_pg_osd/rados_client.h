#ifndef LIBCRUSH_CLIENT_H
#define LIBCRUSH_CLIENT_H

#include <string>
#include <rados/librados.hpp>

void create_rados_client(librados::Rados & cluster,
    std::string conf_file,
    std::string cluster_name,
    std::string user_name,
    uint64_t flags);

#endif

