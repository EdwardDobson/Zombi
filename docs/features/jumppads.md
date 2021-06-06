## Overview

Jump pads allow the player to traverse the map more easily and opens up more level design options.

### Implementation

To create this feature I used Unreal 4s blueprint system. You can view the blueprint [here!](https://user-images.githubusercontent.com/47003895/120929723-14466b80-c6e2-11eb-9a8a-4e302444fefd.png)

When the jump pad has collided with the player I cast tp the Base Play which is the base class for the player, this allows me to get the players mesh so I can apply a force below it. This makes the player jump high into the air.
