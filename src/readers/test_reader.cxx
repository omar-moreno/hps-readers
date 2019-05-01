

//---------//
//   C++   //
//---------//
#include <cstdlib>
#include <iostream>
#include <memory>

//-----------//
//   rogue   //
//-----------//
#include "rogue/Helpers.h"
#include "rogue/utilities/fileio/StreamReader.h"

#include "SvtDataReader.h" 

using namespace rogue::utilities::fileio;

int main( int argc, char **argv) { 

    if (argc < 2) return EXIT_FAILURE;  

    std::cout << "[ SvtDataReaderTest ]: " << argv[1] << std::endl;

    std::shared_ptr<StreamReader> reader = std::make_shared<StreamReader>(); 
   
    std::shared_ptr<SvtDataReader> parser = std::make_shared<SvtDataReader>();  

    streamConnect(reader, parser); 

    reader->open(argv[1]); 

    std::cout << "[ SvtDataReaderTest ]: Reader has openened file. " << std::endl;
    
    reader->closeWait();
    parser->closeCSV();  

    std::cout << "[ SvtDataReaderTest ]: File has been closed. " << std::endl;
    
    return EXIT_SUCCESS; 
}
