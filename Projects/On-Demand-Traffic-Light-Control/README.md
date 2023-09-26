# On-demand Traffic light control System

## This is a mini project the idia was token from FWD professional trak.

<br />

The system will use an ***STM32F103C8*** microcontroller and various components, simulated within the Proteus environment, to manage traffic lights for both vehicles and pedestrians.

### User Stories And Tests
- USER STORY 1
   - As a pedestrian when I will make a short press on the crosswalk button while the cars green light is on and pedestrian red light is off, I will wait for the 
    yellow lights to blink for five seconds then the cars red light is on and pedestrian green light is on for five seconds, so that I can cross the street.

- USER STORY 2
   - As a pedestrian when I will make a short press on the crosswalk button while the cars yellow light is blinking and pedestrian red light is on, I will wait for 
    all yellow lights to blink for five seconds then the cars red light is on and pedestrian green light is on for five seconds, so that I can cross the street.
- USER STORY 3
   - As a pedestrian, when I will make a short press on the crosswalk button while the cars red light is on and pedestrian green light is on, I expect nothing to 
    be done.
- USER STORY 4
   - As a pedestrian when I made a long press on the crosswalk button, I expected nothing to be done.
- USER STORY 5
   - As a pedestrian when I made a double press on the crosswalk button, I expect that the first press will do the action and nothing to be done after the second 
  press.

### Objectives:

- Control traffic lights for cars and pedestrians within the Proteus simulation environment.
- Efficiently respond to pedestrian crosswalk requests.
- Implement error handling and reporting.
