# How does *bundle spreading* influence the readings of a sensor?

## Summary

This research focuses on the influence of bundle spreading on sensor readings within the context of autonomous sailing in harbors. The main objective is to determine how the diameter of the sensor's beam (the "bundle") affects its accuracy and reliability. The study uses literature research to explore how beam divergence, focal distance, and detection resolution are influenced by bundle diameter. The key conclusion is that a smaller beam diameter improves measurement resolution and accuracy, making it more suitable for precise object detection, particularly in controlled environments like an indoor pool used for testing.

## Introduction

### Background

Project 7/8 is centered on autonomous sailing, specifically focused on "Autonomous Docking in the Harbor". The goal is to automate the docking process of ships to improve safety and reduce the manual effort required by sailors and harbor personnel. This research is part of a broader initiative aimed at enhancing sensor accuracy for small-scale autonomous boats tested in indoor pools.

### Problem Statement

In the current setup, various sensors are used to detect obstacles and measure distances during docking maneuvers. However, the effectiveness of these sensors is highly dependent on the characteristics of the emitted and received beam, commonly referred to as the "bundle". A key issue is that improper bundle configuration can lead to inaccurate or noisy readings, making autonomous docking less reliable.

### Importance

The target audience includes engineers and developers working on autonomous marine systems. Accurate sensor readings are critical to avoiding collisions and ensuring safe, reliable docking. This issue affects all stakeholders involved in maritime automation, and solving it is essential to advancing the state of autonomous navigation technologies.

### Research Goal

The desired outcome is to determine the optimal bundle diameter for sensors used in indoor pool environments where precision is prioritized over range.

### Research Question

#### Main Research Question:

How does bundle spreading influence the readings of a sensor?

#### Sub-questions:

What is a bundle and how is it used in sensors?

What is bundle diameter and how does it affect sensor performance?

What are the effects of beam divergence, focal distance, and detection resolution on measurements?

How do different bundle diameters perform under various conditions such as noise, motion, and signal strength?

## Theoretical Framework

The concept of bundle spreading is not new and has been widely studied in the fields of optical and radar sensing. These principles are commonly applied in industries such as automotive radar and medical imaging.

Various commercial sensors exist that offer configurable beam widths. However, they are often generalized and not optimized for specific applications such as autonomous harbor docking. Literature indicates that beam diameter affects critical parameters like detection resolution and noise sensitivity, but comprehensive guidelines for choosing the right diameter in a maritime context are lacking.

## What is bundle?

The bundle is a wide used term for the light or radiation that is send out and/ or recieved to take a measurement.
This can be a bundle of light, Infrared or even X-rays.
Sensors that use this, use to detect oposing object and to measure distances between them and said object.
They do this by observing interruptions and changes around them

Definitions:

Bundle: The light or radiation emitted or received by a sensor for the purpose of measurement.

Bundle Diameter: The width of the beam used to detect objects.

Beam Divergence: How much the beam spreads over a distance.

Focal Distance: The point where the beam is most focused.

Detection Resolution: The sensor's ability to distinguish between multiple opposing objects.

## Methodology

This study was conducted using literature research. Sources include IEEE articles and sensor datasheets. The goal was to identify the effects of different bundle diameters on sensor performance.

Approach:

Literature review of academic papers and technical documentation.

Comparative analysis of beam behavior under varying conditions.

Tabulation of the effects of bundle diameter based on six evaluation criteria: resolution, sharpness, signal strength, range, noise interference, and motion sensitivity.

## Results

### What is a bundle and how is it used in sensors?

The bundle refers to the light or radiation that is emitted and/or received by sensors to detect objects or measure distances. This can be visible light, infrared, or other forms of electromagnetic radiation. Sensors analyze interruptions and changes in the bundle to detect objects and determine distances.

### What is bundle diameter and how does it affect sensor performance?

The bundle diameter is the width of the emitted or received beam. It significantly influences the resolution, reliability, and sensitivity of the sensor:

Small Bundle (1-5 mm): High resolution, more sensitive to disturbances.

Large Bundle (10-50 mm): Lower resolution, but more robust to noise and misalignment.

### What are the effects of beam divergence, focal distance, and detection resolution on measurements?

Beam Divergence: Larger divergence can cause the beam to detect multiple objects as one.

Focal Distance: The point where the beam is most focused, affecting how clearly it can detect objects at various distances.

Detection Resolution: Determines how well the sensor can distinguish between closely spaced objects. Higher resolution is achieved with smaller bundle diameters.

### How do different bundle diameters perform under various conditions such as noise, motion, and signal strength?

|Criterion|Small Bundle (1-5 mm)|Large Bundle (10-50 mm)|
|---|---|---|
|Resolution|High|Low|
|Sharpness|High, but alignment-sensitive|Low, tolerant to misalignment|
|Signal Strength|High, localized|Low, spread|
|Measuring Range|Narrow, precise|Broad, imprecise|
|Interference/Noise|High sensitivity|Low sensitivity|
|Motion Sensitivity|Difficult for fast objects|Easier, less precise|

## Conclusion and Recommendation

### Summary:
This research set out to understand how bundle diameter affects sensor readings. The study concluded that smaller bundle diameters provide better measurement resolution, but are more susceptible to noise and environmental disturbances.

### Answer to Main Question:
Bundle spreading significantly influences sensor readings, primarily affecting resolution, signal strength, and susceptibility to environmental noise.

### Recommendation:
Wherever feasible, opt for sensors with the smallest possible beam diameter for environments where precision is more critical than range—such as in indoor pool-based docking tests. This setup minimizes measurement errors and improves object detection reliability.

## Sources

Zubia, G., Zubia, J., Amorebieta, J., Aldabaldetreku, G., & Durana, G. (z.j.). A new method to design trifurcated optical fiber displacement sensors. IEEE.

Hasch, J., Topak, E., Schnabel, R., Zwick, T., Weigel, R., & Waldschmidt, C. (z.j.). Millimeter-wave technology for automotive radar sensors in the 77 GHz frequency band. IEEE.

## Glossary

Beam Divergence: The widening of the beam over distance.

Bundle: The emitted or received light or radiation.

Bundle Diameter: The width of the beam.

Detection Resolution: Ability to distinguish close objects.

Focal Distance: The distance at which the beam is most focused.

## Appendices

Appendix A: Raw data from literature sources.

Appendix B: Sensor specification sheets.

Appendix C: Comparative tables of sensor performance.

