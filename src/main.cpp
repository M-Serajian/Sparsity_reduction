#include<iostream>

#include <sdsl/rmq_support.hpp>
#include <sdsl/int_vector.hpp>
#include <sdsl/cst_sct3.hpp>

int main(int argc, char *const argv[])
{

    std::string text = "ABRACADABRA";

    uint8_t num_bytes = 1;
    // build cst of the Text
    sdsl::cst_sct3<sdsl::csa_wt<sdsl::wt_huff<sdsl::rrr_vector<>>>, sdsl::lcp_support_sada<>> cst;
    sdsl::construct_im(cst, static_cast<const char*>(&text[0]), num_bytes);
    
    std::cout << cst.size() << std::endl;
  return 0;
}