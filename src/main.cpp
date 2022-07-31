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

//*********************** Argument options ***************************************
// struct containing command line parameters and other globals
// struct Args
// {
//   std::string input = "in.fa";
//   std::string output   = "out.fa"; // output file prefix
//   size_t l = 100;             // minumum MEM length
//   size_t k = 1;              // number of repeatitions
//   size_t th = 1;             // number of threads
// };

// void parseArgs(int argc, char *const argv[], Args &arg)
// {
//   int c;
//   extern char *optarg;
//   extern int optind;

//   std::string usage("usage: " + std::string(argv[0]) + " infile [-i input] [-o output] [-t threads] [-l len] [-k repetitions] \n\n" +
//                     "Copmputes unique substrings occuring at least k times with min lenght of l\n" +
//                     "    k: [integer]  - min occurances of the substring.\n" +
//                     "    len: [integer]  - min length of repeated substring.\n" +
//                     "    input: [string]  - input file prefix.\n" +
//                     "    output: [string]  - output file prefix.\n" +
//                     "    thread: [integer] - number of threads (def. 1)\n");

//   std::string sarg;
//   while ((c = getopt(argc, argv, "l:hp:o:t:")) != -1)
//   {
//     switch (c)
//     {
//     case 'i':
//       arg.input.assign(optarg);
//       break;
//     case 'o':
//       arg.output.assign(optarg);
//       break;
//     case 'l':
//       sarg.assign(optarg);
//       arg.l = stoi(sarg);
//       break;
//     case 't':
//       sarg.assign(optarg);
//       arg.th = stoi(sarg);
//       break;
//     case 'k':
//       sarg.assign(optarg);
//       arg.k = stoi(sarg);
//     case '?':
//       error("Unknown option.\n", usage);
//       exit(1);
//     }
//   }
//   // the only input parameter is the file name
//   if (argc == optind + 1)
//   {
//     arg.input.assign(argv[optind]);
//   }
//   else
//   {
//     error("Invalid number of arguments\n", usage);
//   }
// }

#define DEBUG 


int main(int argc, char *const argv[])
{
string in_address= "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/TestData/data.fa";
string out_address= "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/TestData/output.fa";
string A=  input_file_reader(in_address);
const char* out;
out= A.c_str();
cout << out <<endl;
// add a function for readin

find_repetitive_sequences(out,1,10,2);

#ifdef DEBUG // Check to see if flag is defined

//Args args;
//parseArgs(argc, argv, args);

// step2
// read input ::istream, 
// Do it in a function in main.cpp, call that function
// kseq header file for this function-Max's code

// Step 3
// instantiate the class and building the cst
// inside the class
// inside the header file (SR), output, fasta file

//find_repetitive_sequences(out, 1,5);

ofstream output;


#endif // DEB

  return 0;
}


