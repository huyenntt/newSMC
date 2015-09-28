#include "config.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <string>
#include <time.h>



#ifdef PNAPI_ASSERT_H /* inclusion check */
#error DO NOT include pnapi-assert.h
#endif

#include "cmdline.h"
#include "Output.h"
#include "verbose.h"
#include "pnapi.h"

using std::vector;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

using namespace pnapi;

/// the command line parameters
gengetopt_args_info args_info;

/// a suffix for the output filename
string suffix = "";


int main(int argc, char** argv) {
	 PetriNet n;
	 ifstream in;

	 assert (argc == 2);
	 in.open (argv[1]);
	 try
	 {
		 in >> io::pnml >> n;
	 }
	 catch (const exception::InputError & err)
	 {
		 std::cerr << err << std::endl;
	     exit (EXIT_FAILURE);
	 }

	 std::cout << n.getPlaces().size() << " places, " <<
	 n.getTransitions().size() << " transitions\n";

	 Marking m0(n,false);
	 Graph g(m0);
	 g.buildGraph(m0);
	 std::cout<< "Number of marking: "<<g.getNumMarking()<<std::endl;
	// Place * p=*(n.getPlaces().begin());
	// g.check_reachable_place(*p);

	 char * ofile=new char[255];
	 std::cout <<"Please enter the output file name: ";
	 std::cin>> ofile;
	 g.print_dot(ofile);

	 return 0;

}
