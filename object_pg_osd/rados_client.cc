#include <cassert>
#include <string>

#include "rados_client.h"


void create_rados_client(librados::Rados & cluster,
        std::string conf_file,
        std::string cluster_name,
        std::string user_name,
        uint64_t flags)
{

    int ret = 0;

    /* Declare the cluster handle and required variables. */
    // librados::Rados cluster;
    // char cluster_name[] = "ceph";
    // char user_name[] = "client.admin";
    // uint64_t flags;

    /* Initialize the cluster handle with the "ceph" cluster name and "client.admin" user */
    {
        //ret = cluster.init2(user_name, cluster_name, flags);
        ret = cluster.init2(user_name.c_str(), cluster_name.c_str(), flags);
        if (ret < 0) {
            std::cerr << "Couldn't initialize the cluster handle! error " << ret << std::endl;
            ret = EXIT_FAILURE;
        //} else {
        //    std::cout << "Created a cluster handle." << std::endl;
        }
    }

    /* Read a Ceph configuration file to configure the cluster handle. */
    {
        ret = cluster.conf_read_file(conf_file.c_str());
        if (ret < 0) {
            std::cerr << "Couldn't read the Ceph configuration file! error " << ret << std::endl;
            ret = EXIT_FAILURE;
        //} else {
        //    std::cout << "Read the Ceph configuration file." << std::endl;
        }
    }

    /* Read command line arguments */
    //{
    //    ret = cluster.conf_parse_argv(argc, argv);
    //    if (ret < 0) {
    //        std::cerr << "Couldn't parse command line options! error " << ret << std::endl;
    //        ret = EXIT_FAILURE;
    //    } else {
    //        std::cout << "Parsed command line options." << std::endl;
    //    }
    //}

    /* Connect to the cluster */
    {
        ret = cluster.connect();
        if (ret < 0) {
            std::cerr << "Couldn't connect to cluster! error " << ret << std::endl;
            ret = EXIT_FAILURE;
        //} else {
        //    std::cout << "Connected to the cluster." << std::endl;
        }
    }
}
