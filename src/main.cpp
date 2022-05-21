// Cmake command sent by Max to prevent to -fPIE flag error
//       cmake -DCMAKE_PREFIX_PATH=/s/apu/a/homes/rossi.m ..      //
// cd ~/projects/Sparsity_reduction/build

#include<iostream>

#include <sdsl/rmq_support.hpp>
#include <sdsl/int_vector.hpp>
#include <sdsl/cst_sct3.hpp>
 #include <sdsl/vectors.hpp>
using namespace std;
using namespace sdsl;


#define DEBUG // Probably in a header file


int main(int argc, char *const argv[])
{
  
    
    // Start of First example with Max
    // std::string text = "ABRACADABRA";

    // uint8_t num_bytes = 1;
    // // build cst of the Text
    // sdsl::cst_sct3<sdsl::csa_wt<sdsl::wt_huff<sdsl::rrr_vector<>>>, sdsl::lcp_support_sada<>> cst; 
    // sdsl::construct_im(cst, static_cast<const char*>(&text[0]), num_bytes);// creating the CST
    
    // std::cout << cst.size() << std::endl; 
    // auto root = cst.root(); // showing the root
    // std::cout << root << std::endl;
    // cst.sl(root);
    
    // cst_sct3<> cst;
    // construct_im(cst, "umulmundumulmum", 1);
    // cout << "inner nodes : " << cst.nodes() - cst.csa.size() << endl;
    // auto v = cst.select_child(cst.child(cst.root(), 'u'),1);
    // auto d = cst.depth(v);
    // cout << "v : " << d << "-[" << cst.lb(v) << "," << cst.rb(v) << "]" << endl;
    // cout << "extract(cst, v) : " << extract(cst, v) << endl;


// Algorithm starts here    
// 1:  Input: (1) n input genome sequences S = {S1, .., Sn} and (2) a CST T
// constructed from S

// input
//std::string text = "ABRACADABRA";

//...
#ifdef DEBUG // Check to see if flag is defined

std::string text = "umulmundumulmum";
// CST calculation
cst_sct3<> cst;
construct_im(cst, text, 1);


int Node_numbers=cst.nodes(); 
int CSA_size=cst.csa.size();
auto root = cst.root();

cout << "Totall Leaves : " << CSA_size << endl;
cout << "Inner nodes : " << Node_numbers - CSA_size << endl;
cout << "Totall nodes : " << Node_numbers << endl;
cout << "CSA : " << cst.csa<< endl;
cout << "Root : " << root << endl;


auto v = cst.select_child(cst.child(cst.root(), 'u'),1);
auto d = cst.depth(v);
cout << "v : " << v << endl;
cout << "d : " << d << endl;
cout << "extract(cst, v) : " << extract(cst, v) << endl;
cout << "edge(v,1) : " << cst.edge(v,1) << endl;
cout << "edge(v,2) : " << cst.edge(v,2) << endl;
cout << "edge(v,3) : " << cst.edge(v,3) << endl;
cout << "edge(v,4) : " << cst.edge(v,4) << endl;




// cout << " --------------------------------------- " << endl;

// v = cst.select_child(root, 1);
// d = cst.depth(v);
// cout << "v : " << v << endl;
// cout << "d : " << d << endl;
// cout << "extract(cst, v) : " << extract(cst, v) << endl;
// cout << "edge(v,1) : " << cst.edge(v,1) << endl;



// cout << " --------------------------------------- " << endl;

// v = cst.select_child(cst.child(cst.root(), 'm'),1);
// d = cst.depth(v);
// cout << "v : " << v << endl;
// cout << "d : " << d << endl;
// cout << "extract(cst, v) : " << extract(cst, v) << endl;
// cout << "edge(v,1) : " << cst.edge(v,1) << endl;


// cout << " --------------------------------------- " << endl;

// v = cst.select_child(cst.child(cst.root(), 'm'),2);
// d = cst.depth(v);
// cout << "v : " << v << endl;
// cout << "d : " << d << endl;
// cout << "extract(cst, v) : " << extract(cst, v) << endl;
// cout << "edge(v,1) : " << cst.edge(v,1) << endl;
// cout << "edge(v,2) : " << cst.edge(v,2) << endl;

// cout << " --------------------------------------- " << endl;

// v = cst.select_child(root, 5);
// d = cst.depth(v);
// cout << "v : " << v << endl;
// cout << "d : " << d << endl;
// cout << "extract(cst, v) : " << extract(cst, v) << endl;
// cout << "edge(v,1) : " << cst.edge(v,1) << endl;
// cout << "id(v) : " << cst.id(v) << endl;
// cout << "sn(v) : " << cst.sn(v) << endl;
// cout << "inv_id(v) : " << cst.inv_id(5) << endl;


// cout << " --------------------------------------- " << endl;

// v= cst.select_leaf(2);
// d = cst.depth(v);
// cout << "v : " << v << endl;
// cout << "d : " << d << endl;



/* debugging code here */
#endif // DEBUG


// auto v= cst.child(cst.root(), 1);
// cout <<" v is:"<< v<< endl;
// cout << " --------------------------------------- " << endl;

// cout << "V= 0  : " << cst.is_leaf(root)<< endl;
// auto v= cst.child(v, 1);
// cout << "V= v  : " << cst.is_leaf(v)<< endl;


// 2: Let A be an array of nodes and initialize A to be equal to ∅.
// 3: Initialize each bit of each node in T to be 0.

//int A[Node_numbers]= {0};

// Checking the correctness
// int arrSize = sizeof(A)/sizeof(A[0]);
//cout << "The size of the array is: " << arrSize;



// 4: Let V be an array of nodes to be searched.

//int V[Node_numbers]= {0};

// 5: Initialize V to be equal to the set of the leaves of T .

// 6: while V ̸ = ∅ do
// 7: Let vi be a node in V .
// 8: Remove vi from V
// 9: Set the bit of vi to be equal to 1.
// 10: if the number of children of vi is greater than or equal to K then ▷
// Finding the subsequences occurring at least K times
// 11: A = A ∪ {vi}
// 12: end if
// 13: Add the parent node of vi to V .
// 14: end while
// 15: Let C be the set of all suffix chains for all the nodes in A.
// 16: for each chain c in C do ▷ Finds the subsequences that can not be
// extended from left
// 17: Find the node with lowest height in the chain
// 18: Ignore all other nodes in that chain
// 19: Store that node into B.
// 20: end for
// 21: Return T


































  return 0;
}
