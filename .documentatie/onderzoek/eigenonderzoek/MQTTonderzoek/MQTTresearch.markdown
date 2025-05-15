# Title page

![mqqtilustratie](./../../../../.images/hogeschool-rotterdam.png)
Titel
• Naam
• Studentnummer
• Naam docenten
• Datum van inleveren
• Vermelding eerste gelegenheid of herkansing

# Executive Summary


# Introduction

This report has been written in response to a specific requirement set by our project developer, which states:  
> *"The prototype must use MQTT as the data transfer protocol."*

The project is led by Geert Mosterdijk, an employee at **PK Marine**, a company specialising in radar and maritime measurement technology.

Currently, the mooring of ships in harbours is largely carried out by the visual judgement of the captain, supported by sailors and a limited number of sensors placed around the ship. This manual process is both inefficient and error-prone. Human error can lead to excessive throttle use, unnecessary energy consumption, and increased operational costs due to the need for manual labour.

Considering the shipping industry moved 11.61 billion tons of cargo in 2023 (Fortune Business Insights, 2024), even a small improvement in the mooring process can lead to significant economic and environmental gains. Automating this process would not only reduce human error but also increase operational efficiency.

To realise this, Geert Mosterdijk envisions a system where multiple sensors are placed around the ship. These sensors will send real-time data to a central unit, which will then control the ship’s engines and propellers accordingly. The communication between the sensors and the central unit will be handled using the MQTT protocol — the core subject of this report.

### Main Research Question
> *How can we apply MQTT in our prototype to transfer data between different modules?*

To answer this question, the report is divided into several sub-questions, each addressing a key aspect of MQTT and its suitability for our use case:

1. What is MQTT and how does its publish/subscribe model work?  
2. What are the benefits of MQTT for real-time modular communication systems like ours?  
3. How does MQTT compare to alternative protocols for ship-based systems (e.g., CAN, WebSocket, HTTP)?  
4. What are the main challenges of using MQTT in a maritime prototype (e.g., network reliability, hardware limits)?  
5. How should MQTT topics and QoS be configured to handle multiple sensor streams effectively?  
6. How can MQTT communication be secured in our embedded prototype?  
7. What do existing studies or projects tell us about the use of MQTT in autonomous or semi-autonomous systems?

# Theoretical Framework

To understand how MQTT can be applied in our maritime prototype, it is important to explore the origin, purpose, and current usage of this protocol, as well as relevant alternatives and contextual factors.

## MQTT: Origin and Functionality

MQTT (Message Queuing Telemetry Transport) was developed in 1999 by IBM for use in remote oil pipelines with unreliable connections. It is a lightweight messaging protocol designed for constrained devices and low-bandwidth, high-latency networks. It follows a **publish/subscribe** model, where devices ("clients") send messages to a **broker**, which then forwards those messages to other clients subscribed to specific **topics**.

![mqqtilustratie](./../../../../.images/mqttilustratie.png)
`Foto: “Raspberry Pi and MQTT Essentials”` 

This architecture decouples senders and receivers, making the system modular, scalable, and suitable for real-time distributed systems like ours (MQTT.org, n.d.).

## Relevance in Embedded and Autonomous Systems

MQTT is widely adopted in:
- Home automation
- Industrial IoT
- Autonomous robotics

These domains have similar requirements as our system: low power usage, asynchronous messaging, and robustness to disconnections. Studies confirm that MQTT performs well for sensor networks in dynamic and resource-constrained environments (Naik, 2017).

## Comparison with Alternative Protocols

Several alternative protocols are used in embedded systems:

- **HTTP** follows a request/response model and is relatively heavy; it is less suited for real-time sensor data.
- **WebSocket** provides full-duplex communication but requires persistent connections and more complex state management.
- **CAN (Controller Area Network)** is fast and reliable for short-range communication, commonly used in vehicles and ships, but requires dedicated wiring and has limited range and payload size.

MQTT offers more flexibility, especially over IP-based networks like Wi-Fi and Ethernet (Thangavel et al., 2014).


## Terminology and Scope

In this report:
- A **module** is any sensor or actuator component with its own microcontroller.
- The **central point** or **broker** is the device that routes MQTT messages (e.g., Raspberry Pi).
- The **prototype** refers to a simplified test model of an autonomous mooring system.

This theoretical foundation will guide our analysis of how MQTT can be applied in our prototype.

---


# Methods

# Conclusions/recommendations

# References

# Appendix

# References


MQTT.org. (n.d.). *What is MQTT?* Retrieved May 15, 2025, from https://mqtt.org/faq/

Naik, N. (2017). *Choice of effective messaging protocols for IoT systems: MQTT, CoAP, AMQP and HTTP*. 2017 IEEE International Systems Engineering Symposium (ISSE), Vienna, Austria, 1–7. https://doi.org/10.1109/SysEng.2017.8088251

Thangavel, D., Ma, X., Valera, A., Tan, H. P., & Tan, C. K. Y. (2014). *Performance evaluation of MQTT and CoAP via a common middleware*. 2014 IEEE Ninth International Conference on Intelligent Sensors, Sensor Networks and Information Processing (ISSNIP), 1–6. https://doi.org/10.1109/ISSNIP.2014.6827678

Fortune Business Insights. (2024). Cargo Shipping Market Size, Share & COVID-19 Impact Analysis, By Cargo Type (Dry Bulk Cargo, Liquid Bulk Cargo, General Cargo, and Container Cargo), By End-Use Industry (Food, Manufacturing, Oil & Ores, Electrical & Electronics, and Others), and Regional Forecast, 2024–2032. https://www.fortunebusinessinsights.com/cargo-shipping-market-102045


# How We Apply MQTT in Our Prototype to transfer data between different modules

## Introduction

In the project “Autonomous Maneuvering in the Harbor”, the client has defined several technical requirements for the prototype. One key requirement is that the system must operate within an MQTT-based architecture to ensure modularity and universal data accessibility. To meet this requirement effectively, we initiated a technical investigation centered on the following research question:

### “How can we apply MQTT in our prototype to enable reliable and scalable data transmission?”

This document provides an overview of MQTT, its advantages and limitations, and a detailed explanation of why and how it is implemented in our autonomous harbor navigation prototype.

## What is MQTT?

MQTT stands for Message Queuing Telemetry Transport. It is a lightweight messaging protocol designed for efficient communication in resource-constrained environments, making it ideal for Internet of Things (IoT) applications. The protocol uses a publish/subscribe model, consisting of three core components:
> - **Publisher**: A device or system that sends (publishes) data.
> - **Subscriber**: A device or system that receives (subscribes to) data.
> - **Broker**: The central server that routes messages from publishers to all interested subscribers based on topics.

A *topic* is a string that acts as an identifier for a specific stream of data, such as "sensor/temperature" or "ship/position". Publishers send messages to these topics, and any subscribers listening to that topic will receive the corresponding messages in real time.

![mqqtilustratie](./../../../../.images/mqttilustratie.png)
`Foto: “Raspberru Pi and MQTT Essentials”` 

In our prototype, the MQTT architecture allows each onboard sensor—such as radar modules or GPS units—to act as publishers. Meanwhile, external systems such as a control dashboard, remote monitoring station, or other vessels can act as subscribers, listening to the same topics for coordination or visualization.

## Advantages and Limitations of MQTT

### Advantages
- #### Lightweight and Efficient
    &MQTT has minimal overhead, both in message size and system resources. This is crucial for our project, as our prototype uses microcontrollers with limited processing power and memory. MQTT ensures communication remains fast and responsive, even in bandwidth-constrained environments such as harbor Wi-Fi or mobile hotspots.

- #### Bidirectional Communication
    Devices can both publish and subscribe simultaneously, allowing two-way communication. In our system, this enables not just telemetry broadcasting but also remote command transmission back to the prototype, such as steering adjustments or mode switching.

- #### Scalability
    MQTT makes it easy to integrate new components. If a new module—say, an additional proximity sensor—is added to the vessel, it can simply start publishing to an existing or new topic without disrupting the existing system.

- #### Security Capabilities
    Though MQTT itself is simple, it can be used securely with modern encryption (TLS/SSL) and authentication mechanisms (e.g., username/password or certificate-based). This is especially relevant in our project, where harbor environments may expose the network to interference or malicious access attempts.

### Limitations
- #### No Built-In Delivery Acknowledgment (QoS 0)
    MQTT does not guarantee delivery unless higher Quality of Service (QoS) levels are configured. With QoS 0, the message is sent once without confirmation, which may not be ideal for critical commands. We mitigate this in our prototype by using QoS 1 (at least once) or QoS 2 (exactly once) for vital control messages.

- #### Network Dependency
    MQTT performance heavily depends on network quality. In a harbor environment with signal reflections, congestion, or coverage gaps, message latency or loss could occur. To address this, we are evaluating MQTT over reliable local networks with fallback mechanisms like onboard caching or retransmission.

## MQTT in Our Autonomous Harbor Navigation Prototype

For our prototype vessel, MQTT is central to the system architecture. The microcontroller onboard connects to the MQTT broker via Ethernet or Wi-Fi. Sensor data (e.g., obstacle detection via radar, GPS position) is continuously published under clearly defined topics like:
- `ship/gps/position`
- `ship/radar/front`
- `ship/battery/status`

##Onshore, a control interface subscribes to these topics and displays real-time data for monitoring or route planning. Furthermore, commands such as "goto waypoint" or "stop" are sent to the ship by publishing messages to a topic like ship/control/cmd, which the vessel subscribes to.

This architecture allows for loose coupling between modules—an essential property for modular design. Each subsystem can be developed and tested independently, as long as it adheres to the agreed topic structure and message format.

Additionally, this MQTT-based communication allows us to easily extend the system. For example:
- Adding a second autonomous vessel is as simple as giving it a different topic prefix (e.g., ship2/gps/position).
- Integrating the system with a cloud dashboard or logging service only requires a new subscriber.

## Conclusion

MQTT provides a robust, flexible, and lightweight communication framework that perfectly aligns with the needs of our prototype. Its publish/subscribe model supports the modular design, real-time updates, and scalability required in a complex harbor environment. By implementing MQTT, we ensure our autonomous vessel is not only connected and responsive but also future-proof and easy to maintain.

### Sources
1. HiveMQ. (n.d.). Unlock the value of your data with HiveMQ. Retrieved April 24, 2025, from https://www.hivemq.com

2. Parikh, D. (2022). Raspberry Pi and MQTT Essentials: A Complete Guide to Helping You Build Innovative Full-Scale Prototype Projects Using Raspberry Pi and MQTT Protocol. Packt Publishing. O’Reilly Link

3. https://www.fortunebusinessinsights.com/cargo-shipping-market-102045