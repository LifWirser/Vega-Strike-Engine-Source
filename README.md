<header>
<p style="font-weight:600; font-size:36px">Vega Strike Space Simulation Engine</p>
</header>


```
#====================================
# @file   : README.md
# @version: 2020-02-07
# @created: 2020-02-06
# @author : pyramid
# @brief  : quick repo guide
#====================================
```

**Vega Strike Space Simulation Engine**
=====================================


**Basic Installation**
=====================================

1. Download everything or clone a copy to your system.
2. Install make and cmake.
3. Extract the Downloaded file to a directory of your choice. 
4. Enter /Vegastrike
5. Enter /engine
6. Create a directory called `build`
7. Enter /build
8. run `cmake ../`
9. run `make`
10. return to /Vegastrike
11. create directory called `bin`
12. Copy vegastrike, vegaserver, vssetup from `/engine/build` to `/bin`
13. Run command `./bin/vegastrike` or use the file in the bin as an 
executable.


**Running Vegastrike**
=====================================

Vegastrike takes a single command parameter indicating which mission it should load

```sh
vegastrike mission/explore_universe.mission
```

is an example of a valid mission call

the -l flag (must be flush with the system) will force a player to begin in a star system.

```sh
vegastrike -lvega_sector/vega mission/bomber.mission
```

will force the bomber mission to run in the vega sector


**Interstellar Warp Transit (Jump Drive)**
=====================================

Most starships come equipped with a warp drive.  Unfortunately they can only be used at large singularities in the space-time continuum.  Your computer signals these points by placing glowing blue balls in those areas.  Their relative size indicates how small a starship must be to fit through the jump point.

To engage a jump drive, position your ship inside and press 'j'.

Regulations state that starships should be stopped before jumping-- disasters have resulted from starships travelling at any great speed into a jump point.


**Time Compression**
=====================================

Often interstellar travel requires going great distances. To facilitate this, we have provided time compression.  Press F9 to increase time compression to get where you're going.  Press F10 to drop out of time compression.  F10 will happen automatically if enemies are nearby.


**Respawn**
=====================================

If you sadly lose your life in combat you may respawn by pressing ':'

A new starship will be created for you by Bob.


**Transfer Ship Command**
=====================================

If you wish to transfer command to another starship, simply press '\[' to switch over.  This is useful if you have died and do not wish to call on Bob for help.


**Controls**
=====================================

- Arrow keys: Flight Sim style turning
- \ full throttle
- backspace zero throttle
- =,+ accel
- \- decel
- ENTER fire missile
- space Fire Guns
- backspace  stop
- TAB Afterburners
- j engage interstellar warp drive (use at clear blue balls)
- *,ins Spin Right
- /,del Spin Left
- ~ (hold down, engage shelton slide)
- y match speed
- t target
- p target nearest to center of screen
- n target enemy targetting you
- T target enemies for your turret
- m change active missile
- g change active gun
- v switch targetting computer mode to navigation mode and then view mode
- w switch left targetting cpu
- Shift-W shift weapons computer mode to damage mode

- F1 toggle cockpit/background display
- F2 left
- F3 right
- F4 back
- F5 Chasecam
- F6 Panning Cam (s,a,w,z pan)
- F7 Target Cam
- F8 Strange Cam
- F9 Increase Time Compression
- F10 Reset Time Compression
- F11 Zoom in
- F12 Zoom out

- a,d,w,z pan ghost cam

- : respawn -- use after death to recreate your starship
- \[ switch ships in battle (use to control allies)


**Features**
=====================================

- All of the art assets are original.
- Never before seen ships modelled by the Vegastrike team!
- Astounding soundtrack!
- Multiple Systems
- Entire Sol sector and Vega sector included!
- Fly through huge multilayered asteroid fields
- Explore nebulae where your radar fritzes out
- Jump to other systems at blue jump points with the 'j' key
- Time compression
- Sound effects that make starships roar as they pass and zap as they die
- Bolt weapons with glowing lighting effects
- Cloaking that renders a ship partially/fully invisible
- Customizable fully working HUD with targetting displays, etc
- Customizable Alien Race logos that will change on all starships by editing TerranPriA.bmp and TechPriA.bmp
- Intelligent, Programmable AI
- Encounter epic battles happening in many systems
- The universe is fully dynamic and progresses on its own and independently of the player advancement
- Varied weapons on different starships
- Explosions that literally tear a starship into pieces
- Shields That Glow upon hit (in the location hit)
- Customizable missions
- Stars that fly past as you explore the system
- RAPID collision system that allows no problems with collisions
- BSP Trees that allow one to fly close to a starship, and in the runway of (well formed) models...unlike the victory from WC3.
- the Normal Force which bounces starships off of each other
- Respawn with the ':' key (shift and semicolon)
- Switch Ships with the '\[' key
- Joystick support for a full featured joystick


**Compiling Vegastrike**
=====================================

**Compiling On Linux**
-------------------------------------

use the vsbuild.sh script in the root directory.

or manually

```bash
engine> apt install cmake g++ python2-dev libgl1-mesa-glx freeglut3-dev libopenal-dev libsdl-gfx1.2-dev libvorbis-dev libjpeg-dev libpng-dev libgtk2.0-dev
engine> mkdir build & cd build
engine> cmake ..
engine> make
```

[Link to list of dependencies](http://vegastrike.sourceforge.net/wiki/HowTo:Compile_from_CVS)

If there are any problems with this installation method, please immediately file an issue with the Vega Strike development team by [posting a new issue](https://github.com/vegastrike/Vega-Strike-Engine-Source/issues).


**Compiling On Windows**
-------------------------------------

[HowTo:VCPP Compiling](http://vegastrike.sourceforge.net/wiki/HowTo:VCPP_Compiling)


**Compiling On OSX**
-------------------------------------

[HowTo:Compile on OSX](http://vegastrike.sourceforge.net/wiki/HowTo:Compile_on_OSX)


**Editing Missions**
=====================================

**How to make Vegastrike Missions**
-------------------------------------

An example mission(this is stored in the test1.mission file)

A mission must begin with the headers:

```xml
<mission>
    <variables>
        <var name="defaultplayer" value="blue"/>
        <var name="mission_name" value="4 versus 4" />
        <var name="splashscreen" value="bad_guys_vs_good_guys.bmp" />
        <var name="system" value="sol" />
        <var name="description" value="4vs4.txt" />
    </variables>
```

Currently all of these options are ignored except for the "system".  it loads sol.system  as the star system (which is in XML and stores all present planets)

The only other system included in this beta release is the blank.mission

which has 1 planet, 1 sun and 2 starbases.

After this, comes the actors in the mission, the flightgroups of fighters.

```xml
        <flightgroups>
```

You must begin the flight group tag as above, and terminate it after all of your flight groups

```xml
                <flightgroup name="blue" faction="confed" type="nova" ainame="default" waves="8" nr_ships="3">
```

The name will be used later for targetting and offset purposes.  The faction is a faction listed in factions.xml (should be self explanatory 0 is neutral 1 is happy -1 is mad) Currently confed and aera are the two active factions.  AI must be default in this version as no ohter AI scripts are yet written.  nr_ships indicates how many starships will be in this flight squadron.

```xml
            <pos x="10000.0" y="0.0" z="3000.0"/>
```

This indicates the flight group's position... be sure it is unique

```xml
            <rot x="180.0" y="180.0" z="180.0"/>
            <order order="tmptarget" target="omikron"/>
            <order priority="0" order="superiority" target="enemy"/>
            <order priority="1" order="bomber" target="omikron"/>
            <order priority="2" order="escort" target="blue"/>
```

the rest is in development

```xml
        </flightgroup>
```

you must end all flight group tags

continue with any other flightgroups... you can have as many as you want from as many named factions are you want...

```xml
      </flightgroup>
</mission>
```

**Editing AI**
=====================================

The AI is completely scriptable, and I have not spent all that long perfecting it.  There are included instructions about editing the AI scripts yourself.

Currently there is only 1 AI personality.  In the future there will be a method to assign different personalities to different starships.

it's the "default" personality.

2 files are responsible for the control of the "default" personality

default.agg.xml

and

default.int.xml

default.agg.xml means the "aggressive" AI.  it controls what it does to aggressively bring its vengeance upon its target.

When editing this file in notepad, you'll notice some tags and various numbers.

The first tag, AggressiveAI has a parameter time="4"

that's how often the AI checks if it should change its strategy.  This time can be any integer value... it can revise its plan more often or less often. 4 has been good because most maneuvers can mostly complete in 4 seconds and it's a good time to revise plans

underneath the beginning tag exist a list of tags that describes the logic the AI uses to figure out its next strategy.

there are a number of tags you can specify for the aggressive AI: distance, threat, hull, fshield lshield rshield bshield rand

Each tag asserts if one of the tag-values above is between min and max.

The AI needs to make a CHOICE about what it does next, so it takes a look at the list of tags and determines if any of the assertions is true.

Nested statements mean that BOTH must be true. so you can say "if the distance is at most .5 and the hull is between .25 and .75 by writing:

```xml
<distance max=".5">
  <hull min=".25" max=".75" script="afterburnerslide.xml">
  </hull>
</distance>
```

this means "if the distance is at most half the range of my guns and the hull is between 1/4 and 3/4 of its capacity, then perform an afterburner slide.

It goes down the list of such assertions and chooses the appropriate AI script to run.

The facing and movement tags fill in the gaps where NONE of the list of the assertions are true and the ship is not either turning or moving anywhere:

```xml
<facing script="turntowards.xml">
</facing>
```

at the very bottom the `</AggressiveAI>` must show up to indicate that the AIscript has terminated.

The aggressive.int.xml is written out exactly the same as the aggressive.agg.xml

the difference is that scripts listed here INTERRUPT the current action!

An example from the game is:

```xml
<AggressiveAI close=".05">
  <hull max = ".5" script="evade.xml">
   <threat min=".4" script="afterburnerslide.xml">
   </threat>
  </hull>

  <distance max=".03" script="turnaway.xml">
  <!-- distance less than .1-->
  </distance>

</AggressiveAI>
```

this says:

If the hull is at most half and someone is threatening me with a 40% chance to hit... then evade and then afterburner slide

OR

if someone is at most .03 of my max range away from me TURN AWAY!

this will interrupt the current progress of any scripts

So that's how to use AI scripts.

If you want to know more about writing actual maneuvers (like turnaway.xml  which as you can see is in the directory) please contact me at hellcatv@hotmail.com

you need to have a heavy background in vector math.


**Vegastrike Information**
=====================================

Mail comments or suggestions to vegastrike-users@lists.sourceforge.net

And if you can design some missions it would rock!


**Vega Strike Code Repository**
=====================================
 [https://github.com/vegastrike/Vega-Strike-Engine-Source](https://github.com/vegastrike/Vega-Strike-Engine-Source)



```EOF```
