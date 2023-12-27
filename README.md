# ImpactTrackingArmor

Concept

  As the name suggests this project aims to build an armor pieces with sensors that will register hits.  Those hits will set off other effects such as turning on a light in a particular color and registering the hit count on a small screen.  This will provide a useful way to track the total count of hits and also signal to the rest of the room when a hit has been struck.  In this way it will serve a similar purpose to the existing system used for detecting hits in professional fencing but it will be much cooler.  

  To achieve this goal there are several elements and we will start with the armor proper.  The armor will be based on the female fantasy armor pattern from Prince Armory.  There will certainly be various modifications for both form and function purposes but the basic pattern will remain.  To get it to the desired size for use the armor pattern will be increased at all points by 15 percent.  This will give the rough measurements of 40.25 inches for the chest, 32.2 inches for the waist, and 41.4 inches for the hip.  These measurements will change somewhat due to minor errors in the handmaking process.  It is also worth noting that while this is the default size the straps can increase or decrease this in practice.  
  The leather used will be 8 ounce C-grade cowhide processed via vegetable tanning methods.  This provides a solid surface not only for striking and for use as armor but also as a building surface for electronics and hardware elements.  The pieces will cut using the paper printed patterns previously mentioned.  Once hand cut the pieces will be laser etched/burned using the FUSE makerspace laser cutting machines on a low setting.  After the laser effects are complete the pieces will be painted and shaped.  Finally they will be riveted together using double sided quick rivets of medium size.  Final fitting wll be competed with straps added as needed for comfort and function.  After curing for a day it will be ready to take on other elements.

  The electronic elements will be driven primarily using 3.3 v from a photon 2 computer.  In any case, if this power is not sufficient, 5v will be used.  The photon 2 will be attached just below the nickline on the back of the armor in a hardened case to protect it against the expected impacts from swords and other game weapons.  It will be powered by a battery pack that will be spread out near that photon two in order to increase comfort and distribute weight so as not to restrict movement.  

  The first and most important sensor system will be the piezoelectric sensors.  These are the most vital as every other effect flows from the information that they gather.  The basic idea is to place a handful of such sensors into the armor at key points.  They will be placed in such a way that normal movement within the armor will not cause them to compress or detect a hit.  At least two sensors will be used.  One for the back and one for the front of the leather cuirass.  These will be placed roughly centered with more added if it is reasonable to do so while still achieving the requirements of the project within the allotted time.  
  Any time there is sufficient force to compress and set off the sensors they will record it as one hit. The location of the hit will be recorded and will iterate a numerical output that displays the number of hits taken to that area.  This will be displayed on a small led screen.  

  The Hue lights will be programmed to respond to inputs from the piezo sensors.  Any time a sufficient force is applied to them to have a hit detected the lights will flash and change color.  They should have default color of perhaps green or white and they will change to a color such as yellow or red.  Which color they change will depend on which sensor was hit.  A back hit will have different color than a front hit.  If more sensors are implemented other colors will be implemented as well.  After a ten second interval the lights will revert to their default color and will change again should another hit be registered.

  Wemo Outlets - 

  The OLED display will be set up in a safe box near the Photon 2.  It will display locations and the hit numbers that have been taken and their locations.  

  A handful of NeoPixel lights will be set up at aesthetically advantageous points around the armor.  These will reflect colorations similar to those of the hue lights but rather than a brief flash and reset they will keep shifting through a series of colors.  Which color they are showing at a given point will be a secondary way of counting the current total number of hits that have been successfully delivered to a specific sensor location. 

  There will be at least one button.  Its purpose will mostly be that of a reset and cycling button.  The first press will reset the system to 0 for total hits registered and all lights and other displays to their default starting state.  Subsequent presses will cycle through numbers and color values or back to zero if enough time has passed.

  Speakers will trigger an auditory hit notification.  This will be quite simple and the speaker will mounted in a grilled section of the box right next to the photon 2.  The box will be desgned and printed at FUSE in 3d modeling program.  Measurements will depend on fit.  All effort will be made to keep it small and blend it as seamlessly as possible with the armor to avoid damaging the aesthetic value.

  
