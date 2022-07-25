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
#include <sdsl/suffix_trees.hpp>
#include <sdsl/bit_vectors.hpp>
#include <algorithm>
#include <queue>
typedef cst_sct3<> cst_t;
typedef cst_sada<> csts_t;
typedef cst_sct3<csa_bitcompressed<int_alphabet<> > >::node_type node_t;

// recalling the classes defined in this project
# include "Sparsity_reduction_header.h"


#define DEBUG 


int main(int argc, char *const argv[])
{


#ifdef DEBUG // Check to see if flag is defined

const char * text= "ACGGCACGAATACG";

int k;

#endif // DEB

  return 0;
}


