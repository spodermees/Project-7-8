# Autonoom Manouevreren In De Haven
"Autonoom Manoeuvreren In De Haven" is een project opgestart door *Geert Mosterdijk*, mede-eigenaar van het bedrijf Sens2Sea. Zij zijn gespecialiseerd in maritieme radar- en meetsystemen en hebben de wens om Schepen autonoom te laten aanmeren in de haven. Zij zien dit voor zich door een systeem te maken voor op schepen waarbij er verschillende sensor- en aandrijfmodules zijn, deze werken vervolgens nauw samen om ervoor te zorgen dat de aandrijfmodules het schip autonoom naar de kade kunnen voortbewegen. 

## Probleem
Het autonoom aanmeren van schepen lijkt iets wat anno 2025 allang mogelijk moet zijn, kijk bijvoorbeeld naar de zelf-rijdende auto's. Echter is dit door de vele verschillende omstandigheden waar je mee te maken hebt op een schip nog niet toegepast, denk hierbij aan weersomstandigheden, stroming of de getijde. 

Er bestaan reeds sensormodules voor op schepen die het al mogelijk maken de afstand tot de kade te meten. Deze zijn echter lastig/duur te onderhouden, in bezit van grote bedrijven en niet open source. Door hier zelf een variant op te ontwikkelen die al deze problemen tackled, hoopt Geert dat de scheepvaart in de toekomst efficienter en duurzamer zal zijn

## Impact
Doordat huidige systemen niet open-source zijn, is onderhoud of reparatie alleen uit te voeren door de producent. Dit brengt veel kosten, onnodige wachttijden of ongewenst afval met zich mee. Door het creeeren van een module die juist makkelijk te onderhouden is, zorg je ervoor dat er altijd iemand op een schip aanwezig is die in staat is om dit uit te voeren. Dit kan bedrijven veel geld en tijd schelen.

Helaas zijn mensen niet perfect en maken deze soms wel eens foutjes, wanneer je deze factor weg laat bij het aanmeren van schepen, zullen fouten minder snel voorkomen en zal de energie van de motoren op veel efficientere wijze worden ingezet. Dit kan, in zo'n enorme economie als de scheepvaart, al veel CO2 uitstoot besparen en dus een enorme impact hebben op het klimaat.

## Context
Dit project 7/8 zal zich focussen op het ontwikkelen van de Sensormodules die de taak hebben om de afstand tot de kade te meten en deze door te sturen naar de MQTT broker. Vanaf daar kan deze data verwerkt worden en de motoren aangestuurd worden. In de onderstaande afbeelding zie hoe dit er uit zal zien, waarbij alle groene onderdelen binnen de scope van dit project zijn.

![Indeling](./documentatie/diagrammen/Architectuur.png)
*Afbeelding: scope project*


## Opdracht
Vanuit de opdrachtgever zijn er verschillende requirements opgesteld, deze zijn allemaal uitgebreid beschreven in de [requirement analyse](./documentatie/projectdocumentatie/Requirementanalyse.md). Hieronder staan de belangrijkste punten nog onder elkaar met hoe die zijn aangepakt:

* #### Het moet nauwkeurig afstanden tot objecten kunnen meten: 
    Voor het meten van de afstand tot de kade of andere objecten is er een sensor nodig, daarom is er onderzoek gedaan naar welke het beste zou passen binnen dit project, zie [hier](./documentatie/onderzoek/eigenonderzoek/Sensoronderzoek/SensorResearch.pdf). In dit verslag worden alle requirements uitgebreid meegenomen. Uit de conclusie is gebleken dat de XM125 radar sensor het meest geschikt is voor dit project, echter is de theorie niet altijd zoals de praktijk. Om die reden is er een [experimenteel onderzoek](./documentatie/onderzoek/eigenonderzoek/Experimenteelonderzoek/experimentalresearch.pdf) gedaan om er zeker van te zijn dat de gekozen sensor zowel nu als in de toekomst op correcte wijze de afstand kan meten

* #### Het moet de bewegingssnelheid kunnen bepalen

* #### Het ontwerp moet waterdicht en robuust zijn
* #### Het moet voldoen aan de SDI-standaarden
* #### Het moet alle data via MQTT versturen
    Aangezien MQTT een veel gebruikte oplossing is voor communicatie tussen verschillende microcontrollers is er een eis dat dit gebruikt wordt in het project. Om ervoor te zorgen dat alle functionaliteiten tot het uiterste benut worden is er onderzoek naar gedaan, zie [hier](./documentatie/onderzoek/eigenonderzoek/MQTTonderzoek/MQTT_research.pdf). Uit de resultaten van dit onderzoek blijkt dat dit communcatieprotocol een goede basis is voor als het eindproducten van dit project straks op grotere schaal zal worden toegepast

* #### Het systeem moet op afstand bedienbaar zijn via een gebruikersinterface


## Het prototype
Er is als eindproduct van dit project een prototype ontworpen die de gestelde requirements kan laten zien, deze wordt gedomonstreerd in de [demo video](./demovideo.mp4).

Voor het gebruiken of namaken van het prototype verwijzen we je naar de  [handleiding](./documentatie/projectdocumentatie/handleiding.md), hierin is volledig beschreven hoe het prototype gebouwd is met eventuele visuele 
beschrijvingen.

Een lijst van overige bestanden die de werking/bouw van het prototype kunnen verhelderen:
- [Architectuur diagram](./documentatie/diagrammen/Architectuur.png)
- [Interne Achitectuur diagram](./documentatie/diagrammen/InterneArchitectuur.png)
- [Flowchart code](./documentatie/diagrammen/Flowchart.pdf)
- [Elektrisch schema](./documentatie/diagrammen/ElektrischSchema.pdf)


## Conclusie 
conclusie

## Advies
advies
