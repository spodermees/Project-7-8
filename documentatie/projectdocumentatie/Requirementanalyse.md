# Requirementanalyse

## Definities
<!-- 
*(Eventueel hier termen als “functie”, “kwaliteit”, “restrictie”, “SDI”, “MQTT” kort verklaren indien gewenst.)* -->
- SDI (Standardized Distributed Intelligence) is een manier waarop slimme systemen samenwerken door informatie met elkaar te delen

- MQTT (Message Queuing Telemetry Transport) is een eenvoudig protocol waarmee apparaten snel en efficiënt berichten naar elkaar sturen, zelfs als het netwerk langzaam of onbetrouwbaar is.

## Inleiding

"Autonoom Manoeuvreren In De Haven" is een project opgestart door Geert Mosterdijk, mede-eigenaar van het bedrijf Sens2Sea. Zij zijn gespecialiseerd in maritieme radar- en meetsystemen en hebben de wens om Schepen autonoom te laten aanmeren in de haven. Zij zien dit voor zich door een systeem te maken voor op schepen waarbij er verschillende sensor- en aandrijfmodules zijn, deze werken vervolgens nauw samen om ervoor te zorgen dat de aandrijfmodules het schip autonoom naar de kade kunnen voortbewegen. In dit verslag worden alle gestelde requirements volledig beschreven en uitgewerkt. Voor een korter overzicht met bijbehorende taken en storypoints kun je [Requirements.xlsx](./Requirements.xlsx) lezen.

## Opdrachtomschrijving

Het doel is het ontwikkelen van een prototype dat voldoet aan de volgende functionele en technische eisen:

* Het moet nauwkeurig afstanden tot objecten kunnen meten
* Het moet de bewegingssnelheid kunnen bepalen
* Het ontwerp moet waterdicht en robuust zijn
* Het moet voldoen aan de SDI-standaarden
* Het moet alle data via MQTT versturen
* Het systeem moet op afstand bedienbaar zijn via een gebruikersinterface

## Analyse

### Categorieën

| Categorie       | Beschrijving                                 | Voorbeeld                   |
| --------------- | -------------------------------------------- | --------------------------- |
| Functionele eis | Beschrijft wat het systeem moet doen         | Meet de afstand tot de kade |
| Kwaliteitseis   | Beschrijft hoe goed het moet functioneren    | Nauwkeurigheid van ±1 cm    |
| Restrictie      | Beschrijft waar het systeem aan moet voldoen | Maximaal budget van €500    |

---

### 1. Afstandsmeting (20m ±1 cm)

* **Beschrijving**:
  Het systeem moet in staat zijn de afstand tot de kade te meten met een nauwkeurigheid van ±1 cm, tot op minimaal 20 meter afstand.

* **Categorie**:
  *Functionele eis* 

* **Analyse**:

  * **Helderheid**:
     De eis is duidelijk en meetbaar geformuleerd.
     De term “kade” dient nader gespecificeerd te worden (bijvoorbeeld: vlak oppervlak, metaal, beton?).

  * **Haalbaarheid**:

    * Lidar biedt deze nauwkeurigheid, maar is kostbaar (> €1000).
    * Radar is betaalbaarder, maar typisch minder nauwkeurig (±5 cm).

  * **Testprotocol**:

    1. Zet het meetsysteem op verschillende vaste afstanden (0–20 m).
    2. Voer 100 metingen uit per afstand.
    3. Vergelijk de metingen met referentieafstanden en analyseer de standaarddeviatie (≤ 0,5 cm).

  * **Risico’s**:

    * Hoge kosten bij gebruik van lidar
    * Reflecties of verstoringen kunnen de meetwaarden beïnvloeden

---

### 2. Snelheidsbepaling

* **Beschrijving**:
  De snelheid van het schip moet worden bepaald op basis van opeenvolgende afstandsmetingen.

* **Categorie**:
  *Functionele eis*

* **Analyse**:

  * **Berekeningsmethode**:
    Gebruik van de formule `v = Δx / Δt` met een minimale samplefrequentie van 10 Hz.

  * **Testcases**:

    | Snelheid | Toegestane meetfout |
    | -------- | ------------------- |
    | 0,5 m/s  | ±0,05 m/s           |
    | 1,0 m/s  | ±0,08 m/s           |

  * **Risico’s**:

    * Meetruis beïnvloedt nauwkeurigheid
    * Tijdregistratie moet zeer precies zijn

---

### 3. Behuizing

* **Beschrijving**:
  Alle elektronische componenten dienen in een behuizing geplaatst te worden waarin zij vast zitten.

* **Categorie**:
  *Kwaliteitseis* 

* **Analyse**:

  * **Behuizingsopties**:

    * 3D-geprinte behuizing
    * Houten behuizing

  * **Risico’s**:

    * Warmteafvoer binnen de behuizing
    * Moeilijke toegang voor onderhoud of herprogrammering
    * Sensor interventie

---

### 4. SDI-standaard

* **Beschrijving**:
  Het systeem moet communiceren volgens de SDI-12 v1.4 standaard voor sensordata.

* **Categorie**:
  *Restrictie*

* **Analyse**:

  * **Implementatie**:

    * Hardware moet compatibel zijn met het SDI-12 protocol

  * **Risico’s**:

    * Mogelijke licentiekosten
    * Hardware- en firmware-compatibiliteit kan beperkend zijn

---

### 5. MQTT-implementatie

* **Beschrijving**:
  Dataoverdracht naar gebruikers of servers moet plaatsvinden via het MQTT-protocol.

* **Categorie**:
  *Restrictie*

* **Analyse**:

  * **QoS-instellingen**:

    | QoS-niveau | Toepassing             |
    | ---------- | ---------------------- |
    | 0          | Onkritische sensordata |
    | 1          | Besturingscommando’s   |

  * **Risico’s**:

    * Vertraagde overdracht bij instabiele netwerken
    * Beveiliging van data (versleuteling en authenticatie)

---

### 6. Remote bediening

* **Beschrijving**:
  Het systeem moet op afstand kunnen worden ingeschakeld en uitgeschakeld.

* **Categorie**:
  *Functionele eis*

* **Analyse**:

  * **Oplossingen**:

    * Relaismodule gekoppeld aan microcontroller
    * Softwarematige shutdown via interface

  * **Risico’s**:

    * Stroompieken bij inschakelen
    * Onbevoegd gebruik zonder adequate beveiliging

---

### 7. Webinterface

* **Beschrijving**:
  Een gebruiksvriendelijke webinterface toont real-time sensorwaarden.

* **Categorie**:
  *Functionele eis*

* **Analyse**:

  * **Technische stack**:

    * HTML5 + JavaScript frontend
    * WebSocket-verbinding voor realtime communicatie

  * **Risico’s**:

    * Hoge belasting op microcontroller
    * Kwetsbaarheden in beveiliging van webportaal

---

### 8. LCD-scherm

* **Beschrijving**:
  Het systeem toont basisinformatie lokaal op een LCD-display.

* **Categorie**:
  *Functionele eis*

* **Analyse**:

  * **Technische specificaties**:

    * 20x4 karakter display met I2C-aansluiting

  * **Risico’s**:

    * Beperkte informatiecapaciteit
    * Stroomverbruik bij continue weergave

---

### 9. Microcontroller

* **Beschrijving**:
  De centrale verwerkingscomponent van het systeem

* **Categorie**:
  *Functionele eis* 

* **Analyse**:

  * **Opties**:

    * ESP32 (met geïntegreerde Wi-Fi en lage kosten)
    * Raspberry Pi (krachtiger, maar duurder en energie-intensiever)

  * **Risico’s**:

    * Beperkingen in real-time prestaties
    * Beperkt aantal I/O-pinnen of compatibiliteitsproblemen

---

## Conclusie

### Kritieke aandachtspunten:

1. Selectie van geschikte sensor (balans tussen kostprijs en nauwkeurigheid)
2. Behuizing dient IP67-gecertificeerd te zijn en toch toegankelijk
3. Correcte en compatibele implementatie van de SDI-standaard
4. Real-time prestaties van het totale systeem onder belasting

### Actiepunten:

* Definitieve keuze van de sensor(en) vastleggen
* Behuizing ontwerpen, vervaardigen en testen op waterdichtheid
* SDI-protocolspecifieke vereisten en limieten in kaart brengen
* Uitgebreide integratietests uitvoeren met alle componenten in combinatie

## Changelog

| Versie |Datum|Changelog|
|---|---|---|
|1|11-03-2025|Eerste opzet gemaakt|
|2|27-05-2025|Na overleg |
|3|4-06-2025|Alle requirements uitgewerkt|
