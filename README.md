# Charlieplexing 
This repo explores the concept of charlieplexing as well as features an implementation of charlieplexing using an Arduino uno and some LED's
## Definition
Charlieplexing (also known as tristate multiplexing, reduced pin-count LED multiplexing, complementary LED drive and crossplexing) is a multiplexing technique for driving a multiplexed display in which relatively few I/O pins on a microcontroller are used e.g. to drive an array of LEDs. It was invented by Charlie Allen IN 1995.  It does this by utilizing the tri-state logic capabilities of microcontrollers in order to gain efficiency over traditional multiplexing.
As with any multiplexing, there is a requirement to cycle through the in-use LEDs rapidly so that the persistence of the human eye perceives the display to be lit as a whole. Multiplexing can generally be seen by a strobing effect and skewing if the eye's focal point is moved past the display rapidly.
## Use cases
Charlieplexing is used to multiplex many output signals to relatively few GPIO on a microcontroller. This can be used to power output devices like LED’s, piezo buzzers, etc. Note that when charlieplexing anything other than LED’s, you will need to connect a diode in series with the device (say a piezo buzzer) to control current flow.
Charlieplexing can also be used to multiplex digital input signals into a microcontroller. The same diode circuits are used, except a switch is placed in series with each diode. To read whether a switch is open or closed, the microcontroller configures one pin as an input with an internal pull-up resistor. The other pin is configured as an output and set to the low logic level. If the input pin reads low, then the switch is closed, and if the input pin reads high, then the switch is open. One potential application for this is to read a standard (4×3) 12-key numeric keypad using only 4 I/O lines.
## Implementation
The charlieplexing technique is based on the concept of tri-state logic. Tri-state logic means that the pins of a microcontroller can be in three possible states. High, Low and Input. The Input state is known as the high impendence state. This pin state disconnects the pin from the circuit, even while other pins of the microcontroller are till operational. 
The most common use case of charlieplexing is to drive many LED’s so we will be using this use case for our case study. The formula for charlieplexing multiple LED’s is 
npins =n(n-1)LED’s 
This formula give you the required pins for a giving number of LED’s 
Charlieplexing is made possible because of the characteristic of diode to allow current to flow in only one direction. An LED also possesses this characteristic. This means that if these LED’s are arranged in the correct order. Each LED can be lit individually by just changing the current flow. Lets look at an example. 

![image](Charlieplexing\Picture1.png)



