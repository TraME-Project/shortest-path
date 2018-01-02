
// g++-mp-7 -O2 -Wall -std=c++11 -I./../include rosetta_prob.cpp -o rosetta_prob.out -L./.. -lsp -framework Accelerate

#include "sp.hpp"

int main()
{
    
    sp::graph_t arc_list(6);

    // 0 = a
    arc_list[0].push_back(sp::node_data(1, 7));
    arc_list[0].push_back(sp::node_data(2, 9));
    arc_list[0].push_back(sp::node_data(5, 14));

    // 1 = b
    arc_list[1].push_back(sp::node_data(2, 10));
    arc_list[1].push_back(sp::node_data(3, 15));

    // 2 = c
    arc_list[2].push_back(sp::node_data(3, 11));
    arc_list[2].push_back(sp::node_data(5, 2));

    // 3 = d
    arc_list[3].push_back(sp::node_data(4, 6));

    // 4 = e
    arc_list[4].push_back(sp::node_data(5, 9));

    // 5 = f

    int source_ind = 0;
    int dest_ind = 4;
 
    std::vector<double> min_distance;
    std::vector<int> path_list;

    sp::dijkstra::compute_paths(source_ind, arc_list, min_distance, path_list);

    std::cout << "Distance from " << source_ind << " to " << dest_ind << " = " << min_distance[4] << std::endl;
    std::list<int> path = sp::get_shortest_path(4, path_list);
    
    std::cout << "Path: ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " -> "));
    std::cout << std::endl;
 
    return 0;
}
