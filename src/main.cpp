// Cmake command sent by Max to prevent to -fPIE flag error
//       cmake -DCMAKE_PREFIX_PATH=/s/apu/a/homes/rossi.m ..      //
// cd ~/projects/Sparsity_reduction/build

// data megares : /s/nut/a/data/Ali_Mehrdad/megares_full_database_v2.00.fasta

#include<iostream>
#include <vector>
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
//struct containing command line parameters and other globals
struct Args
{
  string input = "in.fa";
  string output   = "out.fa"; // output file prefix
  size_t length = 6;             // minumum MEM length
  size_t repetition = 10;              // number of repeatitions
  size_t threads = 1;             // number of threads
};

void parseArgs(int argc, char *const argv[], Args &arg)
{
  int c;
  extern char *optarg;
  extern int optind;

  string usage("usage: " + std::string(argv[0]) + " infile [-i input] [-o output] [-t threads] [-l len] [-k repetitions] \n\n" +
               "Copmputes unique substrings occuring at least repetition times with min lenght of l\n" +
               "    repetition: [integer]  - min occurances of the substring.\n" +
               "    length: [integer]  - min length of repeated substring.\n" +
               "    input: [string]  - input file prefix.\n" +
               "    output: [string]  - output file prefix.\n" +
               "    thread: [integer] - number of threads (def. 1)\n");

  string sarg;

    while ((c = getopt(argc, argv,"i:o:t:l:k:")) != -1)//
  {
    switch (c)
    {
    case 'i':
      
      arg.input.assign(optarg);
      
      break;
    case 'o':
      //cout<< optarg<<endl; //debug
      arg.output.assign(optarg);
      
      break;
    case 'l':
    
      //cout<< optarg<<endl; //debug
      sarg.assign(optarg);
      arg.length = stoi(sarg);
      break;
    case 't':
      //cout<< optarg<<endl; //debug
      sarg.assign(optarg);
      arg.threads = stoi(sarg);
      break;
    case 'k': 
      
      //cout<< optarg<<endl; //debug
      sarg.assign(optarg);
      arg.repetition = stoi(sarg);
      break;
    case '?':
      //cout<< optarg<<endl; //debug
      //cout<< "C is :"<< c << endl;
      cerr << "Uknown option\n" << usage << endl;
      exit(1);
    }
  }
  
  
  if (argc != optind && argc==2*5+1 )//2*5+1 since there are 5 parameters 
  //that should be determined plus the program name which is sparcity reductions
  //
  {
    cerr << "Invalid number of arguments\n" << usage << endl;
    }
}

#define DEBUG 


int main(int argc, char *const argv[])
{
//string in_address= "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/TestData/data.fa";
//string out_address= "/s/nut/a/homes/m.serajian/projects/Sparsity_reduction/TestData/output.fa";
 


// add a function for readin


//#ifdef DEBUG // Check to see if flag is defined

Args args;
parseArgs(argc, argv, args);


string input_sequence=  true_input_file_reader(args.input);
const char* input_sequence_char;
input_sequence_char= input_sequence.c_str();
cout<< " DNA Length" <<strlen(input_sequence_char)<<endl;
find_repetitive_sequences(input_sequence_char,1 ,args.repetition,args.length,args.output);


return 0;
}


