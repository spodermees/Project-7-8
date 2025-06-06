# Gebruikersacceptatietest – Autonoom Manoeuvreren in de Haven

## Doel van de test

Deze gebruikersacceptatietest heeft als doel om vast te stellen of het systeem voldoet aan de verwachtingen en eisen van de opdrachtgever en eindgebruikers. Hierbij wordt gekeken naar functionaliteit, gebruiksgemak, betrouwbaarheid en communicatie van sensordata.

---

## Testomstandigheden

- **Datum**: 5 juni 2025  
- **Locatie**: Hogeschool Rotterdam - eindmarkt
- **Getest door**: Projectgroep + testgebruikers
- **Gebruikte apparatuur**:  
  - Raspberry Pi 5  
  - Ultrasoonsensor (waterdichte behuizing)  
  - MQTT-broker (Mosquitto)  
  - Wi-Fi netwerk  
  - Testopstelling

---

## Testcases

| Nr. | Testonderdeel                      | Verwachte uitkomst                                       | Resultaat | Opmerkingen                           |
|-----|------------------------------------|----------------------------------------------------------|-----------|----------------------------------------|
| 1   | Sensor meet afstand                | Sensor geeft binnen 1 seconde correcte afstand weer      | ❌    | Hij geeft wel een afstand weer binnen 1 seconde maar niet heel accuraat. |
| 2   | Data-overdracht via MQTT           | Data wordt realtime verzonden en ontvangen zonder fout   | ✅ |  Word goed, zonder fouten verstuurt via mqtt |
| 3   | Behuizing houdt sensor droog       | Geen vochtsporen na test in natte omgeving               | ❌ | Het prototype is op dit moment gemaakt van hout. Waardoor het water gemakklijk naar binnen kan komen|
| 4   | Logging van fouten werkt correct   | Fout wordt gelogd bij onderbreking van verbinding        | ✅  | De code geeft errors wanneer er systemen niet werken. Deze zijn door monteurs te zien op het LCD scherm |

---

## 💬 Feedback van opdrachtgever / eindgebruiker

> "De sensoren reageren goed, maar het zou fijn zijn als de metingen ook visueel weergegeven worden op een dashboard."
> "De MQTT-verbinding is stabiel, maar er is geen indicatie als het tijdelijk wegvalt."

---

## ✅ Conclusie & Acceptatie

Op basis van de testresultaten en feedback kan geconcludeerd worden dat het systeem:

- **Geaccepteerd** is door de opdrachtgever.
- **Geen** aanpassingen meer nodig heeft.

---

**Versie**: 1.0  
**Datum**: 6 juni 2025  
**Auteur**: Projectgroep 7/8 – Autonoom Manoeuvreren
