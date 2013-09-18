//
// A wrapper for the DOSBox OPL2 emulator.
//


#ifndef BSTONE_OPL2_H
#define BSTONE_OPL2_H


#include <cstdint>

#include "dbopl.h"


namespace bstone {


// A wrapper for DOSBox OPL2 emulator.
class Opl2 {
public:
    Opl2();

    // Initializes the emulator with a specified output sample rate.
    void initialize(
        int sample_rate);

    // Uninitializes the emulator.
    void uninitialize();

    // Returns true if the wrapper initialized or false otherwise.
    bool is_initialized() const;

    // Returns an output sample rate.
    int get_sample_rate() const;

    // Writes a value into a register.
    void write(
        int fm_port,
        int fm_value);

    // Generates number of mono samples into a provided buffer.
    // Returns false on error.
    bool generate(
        int count,
        int16_t* buffer);

    // Resets the emulator.
    bool reset();

    // Returns a minimum output sample rate.
    // (Emulator dependant value)
    static int get_min_sample_rate();

private:
    bool is_initialized_;
    int sample_rate_;
    DBOPL::Handler emulator_;
    MixerChannel channel_;

    // Returns a maximum number of output samples generated at once.
    // (Emulator dependant value)
    static int get_max_samples_count();
}; // class Opl2


} // namespace bstone


#endif // BSTONE_OPL2_H
