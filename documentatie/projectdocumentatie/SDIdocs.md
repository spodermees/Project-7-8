# SDI documentatie
## Context

"Autonoom Manoeuvreren In De Haven" is een project opgestart door Geert Mosterdijk, mede-eigenaar van het bedrijf Sens2Sea. Zij zijn gespecialiseerd in maritieme radar- en meetsystemen en hebben de wens om Schepen autonoom te laten aanmeren in de haven. Zij zien dit voor zich door een systeem te maken voor op schepen waarbij er verschillende sensor- en aandrijfmodules zijn, deze werken vervolgens nauw samen om ervoor te zorgen dat de aandrijfmodules het schip autonoom naar de kade kunnen voortbewegen.
Uit dit project is een prototype ontstaan die ontworpen is aan de hand van verschillende requirements.

## Inleiding
Een van de belangrijkste onderdelen van het project autonoom manoeuvreren in de haven is dat het product makkelijk te installeren of onderhouden is en dat alle onderdelen als losse modules werken. De manier waarop dit gerealiseerd wordt is door alle onderdelen modulair te maken en gebruik te maken van SDI, dat staat voor Standardized Distributed Intelligence. SDI houdt in dat alle data die verstuurd wordt hetzelfde format gebruikt en overal en voor iedereen toegankelijk is. Zo zouden alle aparte modules van elkaar kunnen weten wat op dat moment de gemeten waardes zijn.



Om ervoor te zorgen dat alle modules makkelijk te installeren, onderhouden of vervangen zijn is het dus erg van belang dat ze allemaal volgens hetzelfde protocol en format praten. Om die reden is dat vastgestelde format onderaan dit verslag te lezen.

## Documentatie
### MQTT
Alle modules zullen met elkaar verbonden zijn in een MQTT netwerk zodat alle data overal beschikbaar is. Het zal voor 2 doelen gebruikt worden, voor het versturen van data vanaf de sensor modules en voor het aansturen van de sensor modules vanuit de controller

### Data format
Het versturen van data vanaf de sensor modules gebeurt in SI eenheden. Het gaat hier om de afstand in meter. Deze worden verstuurd naar het volgende topic:

``sensor/data``

In het volgende format:
```

"Distance: <afstand in meter>"

```

### Commando format
Om de verschillende sensor modules aan of uit te zetten zal er via MQTT een commando gestuurd worden op het volgende topic:

``sensor1/action``

Om te stoppen:
```
STOP
```

Om te starten:
```
START
```
