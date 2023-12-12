#include "test.h"
#include <math.h>
#include <sys/util.h>
#include <timing/timing.h>
#include "stm32_std.h"

/* For the program:
    - Runs the motor for a number of seconds equal to testTime
    - Automatically chooses a print delay based on the inout frequency

*/

// Sets the value of pi
const double pi = 3.141592;
const double MAX_SPEED = 100;

const double MAX_MOTOR_SPEED = 175 * 6;

void runTest(double freq)
{
    // setup constants
    const double fConst = pi * freq * 2;
    const double mag = 5;//MIN(900, MAX_MOTOR_SPEED / fConst);
    // const double mag = 90; // set constant value for initial testing

    // setup time
    long long int dt;
    long long int time;

    long long int test_time_ns = determineSimTime(freq);
    dt = k_uptime_get(); // get initial time marker
    time = k_uptime_delta(&dt); // get current time in milliseconds

    // setup print variables and print delay
    long printDelay = mag > 20 ? (mag/2) : 0;
    long printCounter = 0;

    // create local variables
    double speed = 0;     // the speed of the motor
    double targetPos = 0; // desired location

    // signify start of new test
    printk("----------\n");
    k_msleep(5);
    reset_deg();
    // printk("%llu\n", time);

    while (time < test_time_ns * 1000)
    {
        // Get the current time
        time += k_uptime_delta(&dt); // get current time in milliseconds

        targetPos = mag * sin( (double) (fConst * time / 1000) );           // Target position in degrees
        speed = fConst * mag * cos( (double)(fConst * time / 1000) );      // Speed in deg/second
        double speed_frac = (speed / MAX_MOTOR_SPEED) * MAX_SPEED;
        setMotorSpeed(speed_frac);

        float deg = read_deg();

        if (printCounter >= printDelay)
        {
            printVals(deg, targetPos, time, freq, mag, test_time_ns, speed_frac);
            printCounter = 0;
        }
        printCounter++;
    }

    // end off with stopping motor
    setMotorSpeed(0);
}

void runRiseTest(double speed)
{
    // setup time
    long long int dt;
    long long int time;

    long long int test_time_ns = 2;
    dt = k_uptime_get();        // get initial time marker
    time = 0; // get current time in milliseconds

    // create local variables
    // double speed = 4000;     // the speed of the motor

    // signify start of new test
    printk("---------- Starting Test----------\n");
    k_msleep(5);
    reset_deg();
    // printk("%llu\n", time);

    printk("----- SPEED HIGH -----\n");
    while (time < test_time_ns * 1000)
    {
        // Get the current time
        time += k_uptime_delta(&dt); // get current time in milliseconds

        setMotorSpeed(speed);

        float deg = read_deg();
        printk("%f, %lld\n", deg, time);
    }
}

void runForceTest(double freq, int mag) {
    // setup constants
    const double fConst = pi * freq * 2;
    // const double mag = 90; // set constant value for initial testing

    // setup time
    long long int dt;
    long long int time;

    long long int test_time_ns = determineSimTime(freq);
    dt = k_uptime_get();        // get initial time marker
    time = k_uptime_delta(&dt); // get current time in milliseconds

    // setup print variables and print delay
    // long printDelay = mag > 20 ? (mag / 2) : 0;
    long printDelay = 100;
    long printCounter = 0;

    // create local variables
    double speed = 0;     // the speed of the motor
    double targetPos = 0; // desired location

    // signify start of new test
    printk("----------\n");
    k_msleep(5);
    reset_deg();
    // printk("%llu\n", time);

    while (time < test_time_ns * 1000)
    {
        // Get the current time
        time += k_uptime_delta(&dt); // get current time in milliseconds

    
        speed = fConst * mag * cos((double)(fConst * time / 1000)); // Speed in deg/second
        double speed_frac = (speed / MAX_MOTOR_SPEED) * MAX_SPEED;
        setMotorSpeed(speed_frac);

        float deg = read_deg();
        uint16_t adc_val = read_adc(10);

        if (printCounter >= printDelay)
        {
            int converted_speed = ((speed > 0 ? speed : -speed) * 4096) / 100;
            int freq_conv = (freq * 100);

            printk("%f, %d, %d, %d, %d\n", deg, adc_val, (int)time, freq_conv, (int)mag);
            printCounter = 0;
        }
        printCounter++;
    }

    // end off with stopping motor
    setMotorSpeed(0);
}

uint64_t determineSimTime(double freq)
{
    if (freq < 0.02) {
        return 270;
    } else if (freq < 0.05) {
        return 150;
    } else if (freq < 0.1) {
        return 90;
    } else {
        return 60;
    }
}

void printVals(double degree, double target, uint64_t time, double freq, double mag, uint64_t maxtime, double speed)
{
    int converted_speed = ((speed > 0 ? speed : -speed) * 4096) / 100;
    int freq_conv = (freq * 100);

    // char buff[25];
    printk("%f, %f, %d, %d, %d\n", degree, target, (int)time, freq_conv, (int)mag);
    // printq_add(buff);
    // k_msleep(4);
}