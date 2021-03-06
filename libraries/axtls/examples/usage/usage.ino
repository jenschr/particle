/*
 * Example: usage.ino
 * Description: This tests the instantiation of the base library class
 * Author: Rob Cermak
 * Date: 2017-06-20
 *
 * This is test 1 of 3 for for the debugging capabilities.
 *
 * Test 1/3: Define debug_tls() but it should not be used
 *   when CONFIG_DEBUG is not defined.  If you see errors
 *   then there is some code that needs to be wrapped in
 *   #ifdef CONFIG_DEBUG; #endif
 */

#include "axtls.h"

// Use primary serial over USB interface for logging output
// You can watch logging of the Particle device via the Particle CLI
// This will enable basic diagnostic output.  See "axtls_config.h"
// for other options.
// $ particle serial monitor --follow
SerialLogHandler logHandler(LOG_LEVEL_ALL);

// FUNCTIONS

#ifdef CONFIG_DEBUG
void debugger_callback(const char* fmt, ...) {
}
#endif

// Initialize objects from the lib
axTLS axtls;

// Need this or we run functions over and over again
int do_once = 0;

void setup() {
    // Call functions on initialized library objects that require hardware
    axtls.begin();
    Log.trace("begin(): This ignores debug options");
}

void loop() {
    int i = 0;
    // Use the library's initialized objects and functions
    if (do_once == 0) {
      axtls.process();
      do_once = 1;
      Log.trace("loop(): do_once; this ignores debug options");
    }
}
