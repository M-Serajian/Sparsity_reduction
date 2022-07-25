#pragma once

// wrapper function declarations will be here!
#include<iostream>
#include <algorithm>
#include <queue>
#include <sdsl/rmq_support.hpp>
#include <sdsl/int_vector.hpp>
#include <sdsl/cst_sct3.hpp>
#include <sdsl/vectors.hpp>
#include <sdsl/suffix_trees.hpp>
#include <sdsl/bit_vectors.hpp>
using namespace std;
using namespace sdsl;


template <class cst_t, class node_t=typename cst_t::node_type, class char_t=typename cst_t::char_type>
struct To_be_reported {
    public:
        const int output_size;
        cst_t Compressed_Suffix_tree;
        node_t selected_nodes_array[output_size];
        string substrings[output_size];
};

template <class cst_t, class node_t=typename cst_t::node_type, class char_t=typename cst_t::char_type>
void find_repetitive_sequences(const char *X, uint8_t num_bytes_X,int Threshold, int L,To_be_reported output){    
    cst_t cst;
    construct_im(cst, X, 1);

    node_t root= cst.root();
    int nodes= cst.nodes();
    int Node_children_based_on_id_DFS[nodes]= {0}; // Node_children_based_on_id_DFS
    int flag[nodes]= {0}; // a flag array for showing the number of leaves reaching to a node are higher than threshold
    node_t NodeCST[nodes]={}; // Nodes of CST based on DFS ID
    uint64_t max_depth = nodes+1;

    // use the DFS iterator to traverse `cst`
    for (auto it=cst.begin(); it!=cst.end(); ++it) {
        if (it.visit() == 1) {  // node visited the first time
            auto v = *it;       // get the node by dereferencing the iterator
            if (cst.depth(v) <= max_depth){// if depth node is <= max_depth
                // process node, e.g. output it in format d-[lb, rb]
                
                Node_children_based_on_id_DFS[cst.id(v)]=1;
                NodeCST[cst.id(v)]=v; 
            } else { // skip the subtree otherwise
                it.skip_subtree();
            }
        }

        if (it.visit() == 2){
            auto v = *it;
            Node_children_based_on_id_DFS[cst.id(v)]=0; // it means the node is internal so there is no point in adding them (our mistake)
            // only the number of leaves that are rooted to a specific internal node are important for 
            
                for (auto& child: cst.children(v)){
                    
                Node_children_based_on_id_DFS[cst.id(v)]=Node_children_based_on_id_DFS[cst.id(v)]+ Node_children_based_on_id_DFS[cst.id(child)];
                }
        }
    }



    // Flagging the number leaves rooting a node with id= i
    for (int i=0;i<nodes-1;i++){ //-1 is because the root of the CST is not important for us. infact its associate with an empty string (usually shown as epsilon in litreture)

    if (Threshold <= Node_children_based_on_id_DFS[i]  ){
        flag[i]=1;
    }
    }


    // 15: Let C be the set of all suffix chains for all the nodes in A.
    // 16: for each chain c in C do ▷ Finds the subsequences that can not be
    // extended from left
    // here we did not calculate the C, since it was not needed, just for each flaged node, we check the slink until we reach the top of the tree(root)
    // 17: Find the node with lowest height in the chain
    // 18: Ignore all other nodes in that chain
    // Store that node into B.
    // 20: end for
    // 21: Return T (here T is equivalent to the array __ flag __ )


    node_t slink_p, node; // slink_p = suffix like of the node, node= node that is recalled based on its id 
    for (int i=0;i<nodes-1;i++){// -1 since root is not important and its id is always = nodes (total number of nodes)

        if(flag[i]==1){
            node= NodeCST[i];
            slink_p= cst.sl(node);
            while(slink_p!=root){
                if (flag[cst.id(slink_p)]==1){
                    if (cst.depth(node)<cst.depth(slink_p)){
                        flag[cst.id(node)]=0;
                    }
                    else{
                        flag[cst.id(slink_p)]=0;
                    }
                }
                node=slink_p;
                slink_p=cst.sl(node);

            }



        }
    }
int counter=0;
for (int i=0;i<nodes;i++){
    if(flag[i]==1){
        counter++;
    }  
}
node_t output_array_nodes[counter]={};
counter=0;
for (int i=0;i<nodes;i++){
    if(flag[i]==1){
        output_array_nodes[counter]=NodeCST[i];
        counter++;
    }  
}

    
for (int i=0;i<nodes;i++){
    
        if(flag[i]==1){
        cout<< "For the node with id=  "<< i <<", the substring which is repeated at least " << Threshold <<" times is : " << extract(cst, NodeCST[i]) <<endl;
        }
    
    }

output.output_size=counter;
output.Compressed_Suffix_tree=cst;
output.selected_nodes_array=output_array_nodes;
for (int i=0;i<counter;i++){
    output.substrings[i]=extract(cst,output.selected_nodes_array[i]);
}
return;
}   
// void repeated_substring_printer(To_be_reported output){

//     for (int i=0;i<output.output_size;i++){
//         cout<<output.substrings[i]<<endl;  
//     }
//     return;
// }
