# How does *bundle spreading* influence the readings of a sensor?

## Context

Project 7/8 is all about sailing autonomously, at least the part of the project group that covers "Autonoom varen in de Haven".
To put it more precisely it all about docking a ship in the harbour and how to eliminate manual labour from the whole process. This will help with the safety of docking in a harbour, but it will also help with reducing the stress on the sailors and harbour itself.
To accomplish this goal the ship needs sensors and actuators to guide the ship while docking safely in the harbour. This project the focus will be on the sensors and not the actuators.
The tests will be a smaller boat in a indoor pool, so not a big oil tanker or something like that. Because of this the results may swing in favor of accuracy instead of range.

To decide which sensor is best for the project a lot of reasearch has te be done. This research will focus on the bundle what a bundle is and how it effects the readings and measurements of a sensor.

## What is bundle?

The bundle is a wide used term for the light or radiation that is send out and/ or recieved to take a measurement.
This can be a bundle of light, Infrared or even X-rays.
Sensors that use this, use to detect oposing object and to measure distances between them and said object.
They do this by observing interruptions and changes around them

## What is a bundlediameter?

The bundlediameter is the width of the beam that a sensor uses to detect objects. A smaller bundlediameter makes it easier or even possible distinguish individual objects, but it is more sensitive to disturbances.
Whereas a bigger bundeldiameter maybe makes it so that multiple oposing objects gets percieved as one big object, but it can be more reliable and less sensitive to disturbances

To fully understand why some sensors chose a smaller or bigger bundlediameter, there are a couple key concepts that are crucial for chosing a sensor for a project:

- Beam divergence
  The *beam divergence* talks about how much de bundle spreads itself out over a certain distance, this is important to have a beam thats not to big, so that multiple objects don't get seen as one big object.
- Focal distance
  The focal distance is the distance from the sensor or lens where the beam is most focused.
- Detection resolution
  The detection is how accurate the sensor can distinguish multiple oposing objects.

## Hoe does bundlediameter influence the readings

There are multiple ways that the bundle/ bundlediameter influence the readings of a sensor, which needs to be taken into account when choosing the final sensors on a boat.
Because the terms are going to be 'thrown around'quite loosly here, when there is any mention of a 'small bundle' it means the bundle is roughly 1-5mm big, when there is any mention of a 'big bundle' it means the is roughly 10-50mm big.

1. The resolution of the measurements
   - Small bundle
     A smaller beam can provide more accurate measurements because it covers a smaller area. This is especially important in applications where precision is required, such as optical sensors for object detection.
   - Big bundle
     A larger beam can provide less detailed information because it covers a larger area and may capture more noise or interference from environmental factors.

2. The *sharpness* of the measurments
   - Small bundle
     It can be difficult to detect small, well-defined objects because the beam must be very precise to hit the object. In some cases, it may also be harder to get a good signal if the beam is too narrow.
   - Big bundle
      A larger beam may be more capable of detecting objects, even if they are not precisely in the center of the beam, but it may also be less sharp when distinguishing object or changes in the measured area.
3. The signalstrentgh
   - Small bundle
      A smaller beam can result in a higher signal intensity over a small area, which is useful for detecting small amounts of light or specific details. However, it can also be more sensitive to small deviations or disturbances.
   - Large bundle
      A wider beam can spread the signal over a larger area, making the average signal weaker, but at the same time, less sensitive to small disturbances.
4. Measuring range
   - Small bundle
      A smaller beam may limit the measurement capacity to a specific, smaller range. This is useful for detailed, localized measurements but less suitable for detecting larger areas.
   - Big bundle
      A wider beam can cover a larger area, which is useful for measuring or detecting objects over a greater range, but this may come at the cost of precision.
5. Interferance and noice
   - Small bundle
      The chance of interference may be greater because small deviations in the sensor or environment have a larger impact on the measurements.
   - Big bundle
      A wider beam may be less sensitive to small disturbances, as the signal is spread over a larger area, but it can also pick up more background noise from the larger measurement area.
6. Motion sensitivity
   - Small bundle
      With fast-moving objects, the small beam may have difficulty tracking the movement, as it needs to react quickly to changes in position.
   - Big bundle
    A wider beam can more easily track objects moving across a larger area, but it may be less accurate in tracking specific movements.

## Conclusion

After considering all the possible ways in which beam diameter can affect measurements and aligning these with the requirements, the decision has been made to use the smallest possible beam diameter wherever feasible.

## Sources

Zubia, G., Zubia, J., Amorebieta, J., Aldabaldetreku, G., & Durana, G. (z.j.). A new method to design trifurcated optical fiber displacement sensors. IEEE.

Hasch, J., Topak, E., Schnabel, R., Zwick, T., Weigel, R., & Waldschmidt, C. (z.j.). Millimeter-wave technology for automotive radar sensors in the 77 GHz frequency band. IEEE.
