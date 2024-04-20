# Pitch

* Get a 2 layer board for a pulse generator
  * Based on two MD1213/TC6320 - see application note: [20005713B.pdf](20005713B.pdf).
* Connectors: 
  * PMOD interface that connects on the board we've done 
  * SMA as output of the pulser
* IOs: 4 logic entries
  * P+
  * P-
  * Pdamp
  * OE 
* The first three IOs must be protected by some logic, see [logic_protection.pdf](logic_protection.pdf).
* High voltage coming from the +-24V source at [HV.PDF](HV.PDF)


## Resources

* [HV.PDF](HV.PDF)
* [logic_protection.pdf](logic_protection.pdf)
* [pulse_generator.pdf](pulse_generator.pdf)