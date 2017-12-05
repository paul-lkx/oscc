/**
 * @file main.cpp
 *
 */


#include "arduino_init.h"
#include "communications.h"
#include "debug.h"
#include "init.h"
#include "timers.h"
#include "throttle_control.h"


int main( void )
{
    init_arduino( );

    init_globals( );

    init_devices( );

    init_communication_interfaces( );

#ifdef OSCC_FAULTS
    start_timers( );
#endif

    DEBUG_PRINTLN( "init complete" );

    while( true )
    {
        check_for_incoming_message( );

#ifdef OPERATOR_OVERRIDE
        check_for_operator_override( );
#endif
    }
}
