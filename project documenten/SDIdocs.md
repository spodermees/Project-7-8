
# Inleiding


Een van de belangrijkste onderdelen van het project autonoom manoeuvreren in de haven is dat het product makkelijk te installeren of onderhouden is en dat alle onderdelen als losse modules werken. De manier waarop dit gerealiseerd wordt is door alle onderdelen modulair te maken en gebruik te maken van SDI, dat staat voor Standardized Distributed Intelligence. SDI houdt in dat alle data die verstuurd wordt hetzelfde format gebruikt en overal en voor iedereen toegankelijk is. Zo zouden alle aparte modules van elkaar kunnen weten wat op dat moment de gemeten waardes zijn.



Om ervoor te zorgen dat alle modules makkelijk te installeren, onderhouden of vervangen zijn is het dus erg van belang dat ze allemaal volgens hetzelfde protocol en format praten. Om die reden is dat vastgestelde format onderaan dit verslag te lezen.

## Documentatie
### MQTT
Alle modules zullen met elkaar verbonden zijn in een MQTT netwerk zodat alle data overal beschikbaar is. Het zal voor 2 doelen gebruikt worden, voor het versturen van data vanaf de sensor modules en voor het aansturen van de sensor modules vanuit de controller

### Data format
Het versturen van data vanaf de sensor modules gebeurt in SI eenheden distance in cm en speed in m/s. Deze worden verstuurd naar het volgende topic:

``module/sensordata``

In het volgende format:
```
{
	"sensor": 1,
	"data": {
		"distance": 45,
		"speed": 10
	}
}
```

### Commando format
Om de verschillende sensor modules aan of uit te zetten zal er via MQTT een commando gestuurd worden op het volgende topic:

``module/action``

In het volgende format:
```
{
	"action": 1
}
```
Hierbij geldt:

``0`` = uit

``1`` = aan