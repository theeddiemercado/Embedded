// Fall 2025 - HW4 - Problem 2

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

//enum for your use
typedef enum { MAGENTA, RED, BLUE, YELLOW, OFF } color_t;



// According to the schematics on page 37 of the Launchpad user guide,
// When a button is pressed, it is grounded (logic 0)
#define PRESSED 0

void TurnOn_Launchpad_LL1();
void TurnOff_Launchpad_LL1();
char LB2isPressed();
void Turn_BoosterPack_LED(color_t desiredColor);

char BB1isPressed();
char BB2isPressed();


void TurnOn_BoosterPack_BLR();
void TurnOn_BoosterPack_BLG();
void TurnOn_BoosterPack_BLB();

void TurnOff_BoosterPack_BLR();
void TurnOff_BoosterPack_BLG();
void TurnOff_BoosterPack_BLB();

// This function initializes all the peripherals
void initialize();

// In this example, the high-level function, main, is readable.
// It is also easy to port this function to other platforms with similar
// peripherals such as an LED and a switch
int main(void) {
  // initialize all the peripherals
  initialize();

  while (1) {
    // If the button is not pressed, keep the LED off
      if (BB1isPressed() && BB2isPressed()) {
               Turn_BoosterPack_LED (YELLOW);

           }

           else if (BB1isPressed() && !BB2isPressed()) {
               Turn_BoosterPack_LED (RED);
           }

           else if (BB2isPressed() && !BB1isPressed()) {
               Turn_BoosterPack_LED (BLUE);
           }

                  else if (!BB1isPressed() && !BB2isPressed()){
                      Turn_BoosterPack_LED (MAGENTA);


        }
  }
}

// The HAL itself is written using Driverlib, so it is much easier to implement.
void initialize() {
  // step 1: Stop watchdog timer
  // We do this at the beginning of all our programs for now.Later we learn more
  // about it.
  WDT_A_hold(WDT_A_BASE);

  // step 2: Initializing LED1, which is on Pin 0 of Port P1 (from page 37 of
  // the Launchpad User Guide)
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);


  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6); //RED
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4); //Green
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6); //Blue

  // step 3: Initializing S2 (switch 1 or button 1),
  // which is on Pin1 of Port 1 (from page 37 of the Launchpad User Guide)
  GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);

  GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN1); //BB1
  GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN5); //BB2


}

void TurnOn_Launchpad_LL1() {
  GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void TurnOff_Launchpad_LL1() {
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

char LB2isPressed() {
  return ((GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4) == PRESSED));
}

char BB1isPressed() {
    return ((GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN1) == PRESSED));

  }

char BB2isPressed() {
    return ((GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN5) == PRESSED));
  }



void TurnOn_BoosterPack_BLR() {
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);//Red
}

void TurnOff_BoosterPack_BLR() {
  GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);//Red
}


void TurnOn_BoosterPack_BLG() {
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);//Green
  }

void TurnOff_BoosterPack_BLG() {
  GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);//Green
}


void TurnOn_BoosterPack_BLB() {
  GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);//Blue
}

void TurnOff_BoosterPack_BLB() {
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);//Blue
}



void Turn_BoosterPack_LED(color_t desiredColor){
    switch(desiredColor){
    //check the switch documentation here: https://www.geeksforgeeks.org/c-switch-statement/
    case OFF:
        TurnOff_Launchpad_LL1();
        break;
    default:
        TurnOff_Launchpad_LL1();


    case RED:
           TurnOn_BoosterPack_BLR();
           TurnOff_BoosterPack_BLG();
           TurnOff_BoosterPack_BLB();
            break;
    case BLUE:
           TurnOn_BoosterPack_BLB();
           TurnOff_BoosterPack_BLG();
           TurnOff_BoosterPack_BLR();

            break;
    case YELLOW:
           TurnOn_BoosterPack_BLR();
           TurnOn_BoosterPack_BLG();
           TurnOff_BoosterPack_BLB();
            break;
    case MAGENTA:
           TurnOn_BoosterPack_BLR();
           TurnOn_BoosterPack_BLB();
           TurnOff_BoosterPack_BLG();
            break;
    }
}
