# Hoe passen wij MQTT toe op ons prototype om dataoverdracht mogelijk te maken?

## Inleiding
Binnen het project “Autonoom manoeuvreren in de haven” zijn er door de opdrachtgevers verschillende eisen gesteld aan wat het prototype moet voldoen. Een harde eis is dat het moet functioneren binnen een MQTT systeem om het modulair te maken en alle informatie overal beschikbaar te maken. Om er achter te komen waar MQTT allemaal tot in staat is en wat er nodig is om het te gebruiken hebben wij dit onderzoek gestart met als hoofdvraag: “Hoe passen wij MQTT toe op ons prototype om dataoverdracht mogelijk te maken?”.

## Wat is MQTT?
MQTT staat voor “Message Queuing Telemetry Transport”, het is een communicatie protocol dat veel wordt gebruikt in de IoT. De reden daarvoor is omdat het op een erg laag niveau werkt en weinig kracht vraagt van de client. MQTT werkt met subscribers, publishers en een broker, die laatste kan worden gezien als het centrale punt waar alle data naartoe wordt gestuurd door de publishers en waar al die data weer verder wordt verzonden naar de juiste subscribers.
 
Foto: “Raspberru Pi and MQTT Essentials”
In een systeem kunnen er meerdere publishers zijn die data willen verzenden naar andere apparaten, dit doen ze door de data te publishen onder een bepaald topic, bijvoorbeeld “temperatuur”. Deze data wordt dan verzonden naar de broker die dit binnen krijgt en weer doorgestuurt naar alle subscribers. Subscribers zijn alle apparaten die de data willen ontvangen, ze kunnen zich daarvoor “abboneren” op een bepaalde topic, in dit geval de temperatuur. Wanneer een apparaat is geabboneerd op “temperatuur” zal alle data onder die topic daarheen worden verstuurd.



## Wat zijn de voor en nadelen van MQTT?
Over het algemeen wordt MQTT gezien als een eenvoudige manier om te communiceren binnen een netwerk, dit komt doordat het op een aantal vlakken erg goed erg goed doet, hieronder zijn er enkele te lezen:
- Licht en efficient:
MQTT clients zijn erg licht om te gebruiken, zelfs de simpele microcontrollers kunnen het aan zolang ze een verbinding hebben binnen het netwerk. Ook de kleine berichtinhoud maakt het erg efficient, zo wordt ook het netwerk niet zwaar belast.

- Bidirectioneel
MQTT maakt het mogelijk dat elk apparaat zowel kan versturen als ontvangen, zo kan er snel gecommuniceerd worden zonder dat er ergens op hoeft worden gewacht.

- Makkelijk schaalbaar
Doordat niet gebruik wordt gemaakt van addressen of ID’s is het erg makkelijk om een nieuw apparaat aan het netwerk toe te voegen. Zolang ze verbinding kunnen maken met de broker kunnen ze data versturen of ontvangen

- Veilig
MQTT biedt de mogelijkheid om eenvoudig berichten te versleutelen met de meeste moderne authenticatie protocollen.

Ondanks de vele voordelen zijn er altijd nadelen waar rekening mee gehouden moet worden, hier staan de belangrijkste onder elkaar:

- Geen ontvangbevestigingen
Wanneer data verstuurd wordt, weet een apparaat nooit zeker of dit ook werkelijk aan komt. Er is geen mogelijk om daar een bevestiging op te geven.



- Snelheid
De snelheid waarop data kan worden uitgewisseld is sterk afhankelijk van hoe goed het netwerk in elkaar zit. Wanneer dit op een druk netwerk gebeurt kan er wellicht wat vertraging opgelopen worden.


## Waarom past MQTT het beste binnen ons project
MQTT is het protocol dan wij moeten gaan gebruiken binnen dit project, daarom is het handig te weten hoe het in elkaar zit en waarom dit handig is. De voornaamste reden van de opdrachtgever is dat alle data overal en voor elke apparaat beschikbaar moet zijn zodat, daarom is een systeem dat werk met publishers en subscribers perfect. Een andere belangerijke eis van de opdrachtgever is dat het prototype modulair moet zijn en doordat het erg makkelijk is om apparaten toe te voegen aan een MQTT systeem is het uiterst geschikt.


## Bronnen
- HiveMQ. (z.d.). Unlock the value of your data with HiveMQ. Geraadpleegd op 24 april 2025, van https://www.hivemq.com/​

- Parikh, D. (2022). Raspberry Pi and MQTT Essentials : a Complete Guide to Helping You Build Innovative Full-Scale Prototype Projects Using Raspberry Pi and MQTT Protocol. Packt Publishing, Limited. https://www.oreilly.com/library/view/-/9781803244488/

