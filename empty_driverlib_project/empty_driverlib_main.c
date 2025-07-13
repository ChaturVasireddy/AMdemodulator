#include "driverlib.h"
#include "device.h"

//
// Main
//

void main(void)
{
    Device_init();
    DINT;

    GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);

    for(;;)
    {
        // Turn the LED ON
        // Replaces GpioDataRegs.GPASET.bit.GPIO0 = 1;
        GPIO_togglePin(0);
        DEVICE_DELAY_US(10000); // Wait 0.5 seconds
    }
}

//
// End of File
//
