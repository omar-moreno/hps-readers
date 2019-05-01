/**
 *
 */

#ifndef __SVT_DATA_READER_H__
#define __SVT_DATA_READER_H__

#include <fstream>

//-----------//
//   rogue   //
//-----------//
#include "rogue/interfaces/stream/Slave.h"

// Forward declarations 
namespace rogue { 
    namespace interfaces { 
        namespace stream { 
            class Frame;
        }
    }
}

class SvtDataReader : public rogue::interfaces::stream::Slave {

    public: 

        /** Constructor */
        SvtDataReader(); 

        /** Destructor */
        ~SvtDataReader(); 

        //! Accept a frame from master
        /** This method is called by the Master object to which this Slave is attached when
         * passing a Frame. By default this method will print debug information if enabled
         * and is typically re-implemented by a Slave sub-class.
         *
         * Re-implemented as _acceptFrame() in a Python subclass
         * @param frame Frame pointer (FramePtr)
         */
        virtual void acceptFrame ( std::shared_ptr<rogue::interfaces::stream::Frame> frame );

        void closeCSV() { csv.close(); }

    private:

        int event_index{0}; 
       //void parseFrame(byte data); 

       int getField(int value, int high_bit, int low_bit) {
            int mask = pow(2, (high_bit - low_bit + 1)) - 1;
            return (value >> low_bit) & mask;
       }

      void print_uint8_t(uint8_t n) {
        int i;
        for (i = 8; i >= 0; i--)
                printf("%d", (n & (1<<i)) >> i);
        putchar('\n');
    }
        std::vector<uint8_t> channels;

        std::ofstream csv;  

}; // SvtDataReader

#endif // __SVT_DATA_READER_H__
