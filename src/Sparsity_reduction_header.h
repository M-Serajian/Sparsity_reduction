#pragma once

// /usr/bin/time -v ./Sparsity_reduction -i /s/nut/a/data/Ali_Mehrdad/megares_full_database_v2.00.fasta -o /s/nut/a/homes/m.serajian/projects/Sparsity_reduction/TestData/output.fa -t 0 -l 100 -k 100

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
#include <vector>
using namespace std;
using namespace sdsl;

typedef cst_sct3<csa_bitcompressed<int_alphabet<> > >::node_type node_t;
//template <class cst_t, class node_t=typename cst_t::node_type, class char_t=typename cst_t::char_type>

/// ---------------------------------------Previous version using array -> vector
/// This works for a short sequence not long ----> long data -> failed segmentation -- core dump  
/// the output should be a text file in which all the repetions are removed except the first occurances




void find_repetitive_sequences (const char *X, uint8_t num_bytes_X,long int k, long int l, string found_substrings_address){    
    /* discription:
        X -> input sequence
        num_bytes_X -> number of bytes for constructing CST
        k -> the number of times a substring should be occured
        l -> min length of the substring to occur
    */
    cst_t cst;// cst is a class, initially empty
    construct_im(cst, X, num_bytes_X);

    node_t root= cst.root();
    long int nodes= cst.nodes();
    
    cout<<"---------------------------------------------------"<<endl;
    cout<< " DNA Length = " <<strlen(X)<<endl;
    cout<< " Totall number of CST nodes = "<< nodes<< endl;
    cout<<"---------------------------------------------------"<<endl;
    cout << "done!" << endl;
    // long int *array = new long int[nodes](); // malloc
    // xarray[0] = 9;
    // cout<< array[0] << endl;
    //long int* Node_children_based_on_id_DFS= NULL;
    //new long int Node_children_based_on_id_DFS[nodes]= {0};
    //long int Node_children_based_on_id_DFS[nodes]= {0}; // Node_children_based_on_id_DFS
    vector<long int> Node_children_based_on_id_DFS(nodes, 0);
    cout << "done!" << endl;
    //int flag[nodes]= {0}; // a flag array for showing the number of leaves reaching to a node are higher than threshold=k
    vector<bool> flag(nodes, false);
    cout << "done!" << endl;
    //node_t NodeCST[nodes]={}; // Nodes of CST based on DFS ID
    vector<node_t> NodeCST;
    NodeCST.resize(nodes);


    long int max_depth = nodes+1;
    cout << "done!" << endl;
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

        if (it.visit() == 2){ // its an internal node
            auto v = *it;
            Node_children_based_on_id_DFS[cst.id(v)]=0; // it means the node is internal so there is no point in adding them (our mistake)
            // only the number of leaves that are rooted to a specific internal node are important for

                for (auto& child: cst.children(v)){

                    Node_children_based_on_id_DFS[cst.id(v)]=Node_children_based_on_id_DFS[cst.id(v)]+ Node_children_based_on_id_DFS[cst.id(child)];
                    if (Node_children_based_on_id_DFS[cst.id(v)] > k) {
                        flag[cst.id(v)]=true;
                }
                }
        }
    }
    cout << "done!" << endl;
    Node_children_based_on_id_DFS.clear();

    long int counter=0;
    for (int i=0;i<nodes;i++){
        if(flag[i]== true){
            counter++;
        }
    }

    cout<< "---------------- number of flagged nodes after checking k repetitions ---------------"<< endl;
    cout<< counter<< endl;
    cout<< "-------------------------------------------------"<< endl;



     // BFS to find the parts that can not be extended from right anymore
     queue<node_t> f;
     f.push(cst.root());
     while(!f.empty()){
       node_t v = f.front();
       f.pop();
       long int node_id = cst.id(v);

       if (flag[node_id]==true){
        node_t parent= cst.parent(v);
        flag[cst.id(parent)]=false;
       }

       if(!cst.is_leaf(v))
         for(auto child:cst.children(v)) f.push(child);

    }

    counter=0;
    for (long int i=0;i<nodes;i++){
        if(flag[i]==1){
            counter++;
        }
    }

    cout<< "---------------- BFS to not extended from right anymore---------------"<< endl;
    cout<< counter<< endl;
    cout<< "-------------------------------------------------"<< endl;



    counter=0;
    // unflagging nodes with length lower than l
    for (long int i=0;i<nodes-1;i++){ //-1 is because the root of the CST is not important for us. infact its associate with an empty string (usually shown as epsilon in litreture)

        if ( cst.depth(NodeCST[i])<l ){
            flag[i]=false;
        }
    }

    //node_t output_array_nodes[counter]={};

    vector<node_t> output_array_nodes;
    counter=0;
    for (long int i=0;i<nodes;i++){
        if(flag[i]==true){
            output_array_nodes.push_back(NodeCST[i]);
            counter++;
        }
    }

    cout<< "----------------removing nodes with depth higher than l---------------"<< endl;
    cout<< counter<< endl;
    cout<< "-------------------------------------------------"<< endl;

//    // cout<< "---------------- number of nodes with k children----------------"<< endl;
//    // cout<< counter<< endl;
//    // cout<< "-------------------------------------------------"<< endl;
//    // // checking the fact that the substrings can not be extended form right anymore
//    // flag[cst.id(root)]=0; // root is not important, trivial!
//    // for (int i=0;i<counter;i++){
//    //     auto mid_var_node= output_array_nodes[i];
//    //     if (flag[cst.id(mid_var_node)]==1){
//    //         mid_var_node= cst.parent(mid_var_node);
//
//    //         while ( cst.depth(mid_var_node) > l ){
//    //             if (flag[cst.id(mid_var_node)]==1){
//    //                 flag[cst.id(mid_var_node)]=0;
//    //                 counter--;
//    //             }
//
//    //         }
//    //     }
//    // }
//
//
//    //  Queue
//    //  queue<node_t> f;
//    //  f.push(cst.root());
//    //  while(!f.empty()){
//    //    node_t v = f.front();
//    //    f.pop();
//    //    int node_id = cst.id(v);
//    //    bfs_to_v[global_bfs] = v;
//    //    bfs_to_ids[global_bfs] = node_id;
//    //    ids_to_bfs[node_id] = global_bfs--;
//    //    // Build the Weiner link character for each node
//    //    for(auto c: tmp_alphabet){
//    //      node_t wl = cst.wl(v,c);
//    //      if(cst.root() != wl) alphabet[node_id].insert(c);
//    //    }
//    //    if(!cst.is_leaf(v))
//    //      for(auto child:cst.children(v)) f.push(child);
//    //  }
//
//
//
//

    counter=0;
    node_t slink_p, node; // slink_p = suffix like of the node, node= node that is recalled based on its id
    vector<bool> met_before_suffix_chain_linear(nodes, false);

    for (long int i=0;i<nodes-1;i++){// -1 since root is not important and its id is always = nodes (total number of nodes)
        if(flag[i]==1){
            met_before_suffix_chain_linear[i]=true;
            node= NodeCST[i];
            slink_p= cst.sl(node);
            bool end_while=false;
            while(slink_p!=root && end_while==false){
                if (met_before_suffix_chain_linear[cst.id(slink_p)] == false){
                    met_before_suffix_chain_linear[cst.id(slink_p)] = true;
                    flag[cst.id(slink_p)]=0;
                    node=slink_p;
                    slink_p=cst.sl(node);
                }
                else{
                    flag[cst.id(slink_p)]=0;
                    end_while=true;
                }
            }
        }
    }

    counter=0;
    for (long int i=0;i<nodes;i++){
        if(flag[i]==1){
            counter++;
        }
    }

    cout<< "----------------removing suffix links---------------"<< endl;
    cout<< counter<< endl;
    cout<< "-------------------------------------------------"<< endl;

//    // vector<node_t> output_array_nodes_final;
//    // output_array_nodes_final.resize(counter);
//
//    // for (int i=0;i<nodes;i++){
//    //     if(flag[i]==1){
//    //         output_array_nodes_final[counter]=NodeCST[i];
//    //     }
//    // }
//    // int node_flag_variable=0;
//    // int first_leaf_variable=0;
//    // int lenght_of_repeated_text= 0;
//    /*
//    for (auto it=cst.begin(); it!=cst.end(); ++it) {
//        if (it.visit() == 1) {  // node visited the first time
//            if (flag[cst.id(*it)]==1){ // internal flag node
//                // a flagged node is visited
//                node_flag_variable=1;
//                lenght_of_repeated_text=cst.depth(*it);
//            }
//            if(cst.is_leaf(*it)==1 && first_leaf_variable==0){ //first visited leaf of the internal flagged node is visited
//                first_leaf_variable=1;
//            }
//
//            if(cst.is_leaf(*it)==1 && first_leaf_variable==1){ //not first visited leaf of the internal flagged node is visited
//                // debug mode
//                int suffix_number=cst.sn(*it);
//                //cout<< "start = " << suffix_number<<endl;
//                //cout <<"finish= " << suffix_number+ lenght_of_repeated_text-1 <<endl;
//
//
//            }
//        }
//
//        if (it.visit() == 2){
//            if (flag[cst.id(*it)]==1){ //the procedure for this node and its leaves are done
//                node_flag_variable=0;
//            }
//        }
//    }
//    */
//
//    ofstream myfile;
//    myfile.open (found_substrings_address);
//    myfile << "Output of the algrithm\n";
//    myfile << "Substrings that have occured at least ";
//    myfile << k;
//    myfile <<" (k) times\nwith the length of at least (l) ";
//    myfile << l;
//    myfile << "that can not be extended\nany further from left or right.\n";
//
//
//    if (counter==0) {
//        myfile << "No substrings found with the aforementioned criteria\n";
//    } else {
//        int output_strings_counter=1;
//        for (long int i=0;i<nodes;i++){
//            if(flag[i]==1){
//            myfile<<">Substring"<<output_strings_counter<< "\n";
//            myfile<<extract(cst, NodeCST[i])<<"\n";
//            output_strings_counter++;
//            }
//        }
//    }
//    myfile.close();
//
     return;
}

string true_input_file_reader (string address)
{
    ifstream Input_file;
    Input_file.open(address);

    string line, name /*,content*/;
    string out="";
    
    int first_line_detector=0;
    
    while( getline( Input_file, line ).good() ){
        /* find the first line
        facign > => then go to the next line
        if line is not empty, add it to out, if it the first time visiting >, no $ is needed,
        otherwise, add a $ wen facing a new > */
        if( line[0] == '>' ){ // Identifier marker- For new Lines
            if (first_line_detector==0){
                first_line_detector=1;
            } else {
                out=out+"$";
            }

            
            //content.clear();
        }
        else{ // we have a DNA sequence line
            if( !line.empty() ){
                name = line.substr(0);
                //cout<<name <<endl;
                out=out+name;        
                name.clear();   
             } 
        }  
    
    }
    Input_file.close();

return (out);
}
