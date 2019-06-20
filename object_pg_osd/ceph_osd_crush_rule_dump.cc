#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "libcrush.h"

using namespace std;


void print_rule() {
    librados::Rados rados;
    create_rados_client(rados, "/etc/ceph/ceph.conf", "ceph", "client.admin", 0);

    const struct crush_map* crushmap = rados.get_crushmap();
    // print rules
    printf("crushmap max rules: %d\n", crushmap->max_rules);
    __u32 i;
    for (i = 0; i < crushmap->max_rules; i++) {
        std::cout << "crushmap:"<< crushmap << std::endl;
        std::cout << "rule:"<< crushmap->rules[i] << std::endl;
        printf("rule mask ruleset: %d\n", crushmap->rules[i]->mask.ruleset);
        printf("rule mask type: %d\n", crushmap->rules[i]->mask.type);
        printf("rule mask min size: %d\n", crushmap->rules[i]->mask.min_size);
        printf("rule mask max size: %d\n", crushmap->rules[i]->mask.max_size);
    }
    // function signature:
    // int crush_find_rule(const struct crush_map *map, int ruleset, int type, int size)
    // compare result with `cehp osd crush rule dump`
    int rule_id = crush_find_rule(crushmap, 0, 1, 2);
    printf("rule id: %d\n", rule_id);
    rados.put_crushmap();
}


// ceph/src/crush/mapper.c:51
// int crush_find_rule(const struct crush_map *map, int ruleset, int type, int size)
// {
//     __u32 i;
// 
//     for (i = 0; i < map->max_rules; i++) {
//         if (map->rules[i] &&
//                 map->rules[i]->mask.ruleset == ruleset &&
//                 map->rules[i]->mask.type == type &&
//                 map->rules[i]->mask.min_size <= size &&
//                 map->rules[i]->mask.max_size >= size)
//             return i;
//     }
//     return -1;
// }


int main() {
    print_rule();
}
