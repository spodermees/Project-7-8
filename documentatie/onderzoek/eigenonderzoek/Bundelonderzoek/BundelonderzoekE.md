# How does *bundle spreading* influence the readings of a sensor?

![picturechatgpt](<../../../../images/ChatGPT Image May 22, 2025, 12_06_36 PM (1).png>)

Name: Mees van der Waal
Studentnumber: 1052159
Teachers: Anne de Gier, Alex Slaa
Date: 08/06/2025
First opportunity

## 1. Summary

This research investigates the influence of bundle spreading on sensor readings, specifically within the context of autonomous docking in indoor pools. The study explores how the diameter of a sensor's beam, or "bundle," impacts accuracy and resolution. The findings indicate that a smaller beam diameter improves measurement precision but may introduce higher sensitivity to noise. This study is supported by literature from optical fiber and radar sensing domains.

---
<div style="page-break-after: always;"></div>

## 2. Introduction

### 2.1 Background

Project 7/8 aims to automate the docking process of small autonomous boats to improve efficiency and safety. Collaborators include Sens2Sea, Geert Mosterdijk, and the Hogeschool Rotterdam. A core challenge in this domain is optimizing the configuration of sensors used to detect obstacles and guide docking maneuvers.

### 2.2 Problem Statement

Sensor effectiveness in docking scenarios is significantly influenced by beam properties. Improper bundle configurations can yield inaccurate readings, risking unsafe docking operations.

### 2.3 Research Goal

To determine the optimal bundle diameter for sensors operating in small-scale controlled environments.

### 2.4 Main Research Question

How does bundle spreading influence the readings of a sensor?

### 2.5 Sub-questions

1. What is a bundle and how is it used in sensors?  
2. How does bundle diameter affect sensor performance?  
3. What are the effects of beam divergence, focal distance, and detection resolution on measurements?  
4. How do different bundle diameters perform under conditions like noise, motion, and signal strength?

---

## 3. Theoretical Framework

Literature confirms that bundle geometry plays a pivotal role in sensing accuracy. Zubia et al. (2024) outline that trifurcated optical fiber displacement sensors use beam geometry to balance sensitivity and range. The method they propose allows optimization of fiber bundle dimensions based on sensitivity, range, and beam divergence [1]. Similarly, Hasch et al. (2012) argue that radar systems benefit from narrower beams for precision, especially in short-range scenarios like parking assistance [2].
The key formula used to describe optical beam responsivity is detailed in Appendix A.

---

## 4. Terminology

- **Bundle**: Emitted or received light/radiation for sensing.  
- **Bundle Diameter**: Width of the beam used in detection.  
- **Beam Divergence**: Degree of beam spread over distance.  
- **Focal Distance**: Point where the beam converges most.  
- **Detection Resolution**: Ability to distinguish close objects.

---
<div style="page-break-after: always;"></div>

## 5. Methodology

A literature study was conducted using IEEE articles and sensor design papers. Two key sources include:

- Zubia et al. (2024), which presents equations to compute beam structure and responsivity in trifurcated optical sensors [1].  
- Hasch et al. (2012), discussing automotive radar sensor design principles for optimal angular and distance resolution [2].  

Comparative analysis was applied across six criteria: resolution, sharpness, signal strength, range, noise interference, and motion sensitivity.

---
<div style="page-break-after: always;"></div>

## 6. Results

### 6.1 Bundle Function

Bundles refer to the light or radiation beams that detect object presence or distance. These may be optical, infrared, or radar-based, depending on the sensor type.

### 6.2 Bundle Diameter Effects

- **Small Bundles (1-5 mm)**: High resolution, prone to noise and misalignment.  
- **Large Bundles (10-50 mm)**: Lower resolution, better tolerance to environmental noise.

### 6.3 Influencing Parameters

- **Beam Divergence**: Increases with larger diameters, reducing precision [1].  
- **Focal Distance**: Determines optimal detection range and focus [1].  
- **Detection Resolution**: Smaller diameters improve object distinction [2].
The sensor specifications used for comparison are summarized in Appendix B.

### 6.4 Performance Comparison

| Criterion           | Small Bundle (1-5 mm)     | Large Bundle (10-50 mm)     |
|--------------------|----------------------------|------------------------------|
| Resolution         | High                       | Low                          |
| Sharpness          | High, alignment-sensitive  | Low, misalignment-tolerant   |
| Signal Strength    | High, localized            | Lower, diffused              |
| Measuring Range    | Short, precise             | Broad, less precise          |
| Noise Interference | High                       | Low                          |
| Motion Sensitivity | High                       | Lower                        |

---

## 7. Conclusion and Recommendation

### 7.1 Conclusion

Beam diameter directly affects sensor reading quality. Narrow bundles enhance precision but at the cost of increased sensitivity to environmental factors.
For a full breakdown of the performance comparison, see Appendix C.

### 7.2 Recommendation

Use narrow bundles in controlled environments requiring high precision, such as indoor testing pools. Broader beams are better suited for unpredictable, noisy outdoor environments.

---
<div style="page-break-after: always;"></div>

## 8. References

[1] Zubia, G., Zubia, J., Amorebieta, J., Aldabaldetreku, G., & Durana, G. (2024). *A New Method to Design Trifurcated Optical Fiber Displacement Sensors*. IEEE Sensors Journal, 24(2).  
[2] Hasch, J., Topak, E., Schnabel, R., Zwick, T., Weigel, R., & Waldschmidt, C. (2012). *Millimeter-Wave Technology for Automotive Radar Sensors in the 77 GHz Frequency Band*. IEEE Transactions on Microwave Theory and Techniques, 60(3), 845-860.

---
<div style="page-break-after: always;"></div>

## 9. Appendices

### Appendix A: Extracted Equations from Optical Sensor Models

From Zubia et al. (2024), the responsivity of a trifurcated optical fiber displacement sensor is expressed as:

η(z) = sinh(A₂ / z²tan²θ₀) / sinh(A₁ / z²tan²θ₀) × exp[-q / z²]

yaml

Where:  
- `A₁ = ρ₁∆ρ₁` and `A₂ = ρ₂∆ρ₂` represent structural constants,  
- `θ₀` is the maximum acceptance angle,  
- `z` is the distance, and  
- `q` is a proportionality constant related to attenuation.

These parameters help determine optimal focal zones and the influence of divergence.

---

### Appendix B: Radar Sensor Specifications

Summarized from Hasch et al. (2012):

| Parameter              | Value                            |
|------------------------|----------------------------------|
| Frequency Band         | 76–81 GHz                        |
| Range Resolution       | ~4 cm                            |
| Angular Resolution     | ~1–5 degrees                     |
| Sensor Type            | FMCW (Frequency Modulated CW)   |
| Max Detection Range    | Up to 250 meters                 |
| Technology             | SiGe-based RFIC                 |
| Use Case               | Automotive radar (e.g., ACC)     |

---

### Appendix C: Evaluation Table for Beam Configurations

| Criterion           | Small Bundle (1–5 mm)     | Large Bundle (10–50 mm)     | Remarks                                      |
|--------------------|----------------------------|------------------------------|----------------------------------------------|
| Resolution         | High                       | Low                          | Smaller bundles resolve details better       |
| Sharpness          | High, alignment-sensitive  | Low, misalignment-tolerant   | Precise but fragile alignment needed         |
| Signal Strength    | High, localized            | Lower, diffused              | Narrow beam gives strong localized signal    |
| Measuring Range    | Short, precise             | Broad, less precise          | Wide beams cover more, with less clarity     |
| Noise Interference | High                       | Low                          | Wide beams average out fluctuations          |
| Motion Sensitivity | High                       | Lower                        | Narrow beams pick up fine changes            |
